//
//  map.hpp
//  ft_containers_new
//
//  Created by Сергей on 04.02.2021.
//

#ifndef map_hpp
#define map_hpp

#include "ft.hpp"

template < class Key, class T, class Compare, class Alloc>
class ft::map {
	
public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	typedef Key												key_type;
	typedef T												mapped_type;
	typedef std::pair<const key_type, mapped_type>		value_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef ptrdiff_t										difference_type;
	typedef size_t											size_type;
	
	class value_compare: std::binary_function<value_type, value_type, bool> {
	protected:
		key_compare comp;
		value_compare (key_compare c) : comp(c) {}
	public:
		bool operator() (const value_type & x, const value_type & y) const {
			return comp(x.first, y.first);
		}
	};
	
private:
	const static bool black = true;
	const static bool red = false;
	
	struct Node {
		Node		*parent;
		Node		*left;
		Node		*right;
		bool		color;
		value_type	*data;
	};
	
	typedef typename allocator_type::template rebind<Node>::other _alloc_rebind_type;
	
	_alloc_rebind_type	_allocRebind;
	allocator_type		_alloc;
	Compare				_comp;
	size_type			_size;
	Node				*_rootNode;
	Node				*_abstractNode;
	
	Node *createNode(Node *parent, const_reference value, bool color) {
		Node *newNode = _allocRebind.allocate(1);
		_allocRebind.construct(newNode);
		if (parent != NULL && parent->left == _abstractNode)
			newNode->left = NULL;
		if (parent != NULL && parent->right == _abstractNode)
			newNode->right = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = parent;
		newNode->data = _alloc.allocate(1);
		_alloc.construct(newNode->data, value);
		newNode->color = color;
		return newNode;
	};
	
	Node *createAbstractNode() {
		Node *newNode = _allocRebind.allocate(1);
		_allocRebind.construct(newNode);
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = NULL;
		newNode->color = black;
		newNode->data = _alloc.allocate(1);
		_alloc.construct(newNode->data, std::make_pair(0, 0));
		return newNode;
	};
	
	void destroyAndDeallocNode(Node *node) {
		_alloc.destroy(node->data);
		_alloc.deallocate(node->data, 1);
		_allocRebind.destroy(node);
		_allocRebind.deallocate(node, 1);
	};
	
	void createRootNode (const_reference value) {
		_rootNode = createNode(NULL, value, black);
		_rootNode->left = _abstractNode;
		_rootNode->right = _abstractNode;
		_abstractNode->left = _rootNode;
		_abstractNode->right = _rootNode;
		_size += 1;
	};
	
	Node *findGrandparent(Node *node) {
		if (node != NULL && node->parent != NULL)
			return node->parent->parent;
		else
			return NULL;
	};
	
	Node *findUncle(Node *node) {
		Node *grandparent = findGrandparent(node);
		if (grandparent == NULL)
			return NULL;
		if (node->parent == grandparent->right) {
			return grandparent->left;
		} else
			return grandparent->right;
	};
	
	Node *findNodePosition(const_reference value) {
		Node *neededNode = _rootNode;
		while (1) {
			if (value.first == neededNode->data->first)
				return neededNode;
			if (neededNode->left == NULL && neededNode->right == NULL)
				return neededNode;
			if ((neededNode->left == _abstractNode && neededNode->right == NULL) || (neededNode->left == NULL && neededNode->right == _abstractNode))
				return neededNode;
			else if (value.first < neededNode->data->first) {
				if (neededNode->left == NULL || neededNode->left == _abstractNode)
					return neededNode;
				else
					neededNode = neededNode->left;
			} else {
				if (neededNode->right == NULL || neededNode->right == _abstractNode)
					return neededNode;
				else
					neededNode = neededNode->right;
			}
		}
		return NULL;
	};
	
	Node *findNodePositionKey(const key_type & key) const {
		Node *tmp = _rootNode;
		while (tmp != NULL && tmp != _abstractNode) {
			if (key == tmp->data->first)
				return tmp;
			else
				tmp = (tmp->data->first < key) ? tmp->right : tmp->left;
		}
		return NULL;
	};
	
	void rotateLeft(Node *node) {
		Node *newRoot = node->right;
		newRoot->parent = node->parent;
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = newRoot;
			else
				node->parent->right = newRoot;
		}
		node->right = newRoot->left;
		if (newRoot->left != NULL)
			newRoot->left->parent = node;
		node->parent = newRoot;
		newRoot->left = node;
		if (newRoot->parent == NULL)
			_rootNode = newRoot;
	};
	
	void rotateRight(Node *node) {
		Node *newRoot = node->left;
		newRoot->parent = node->parent;
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = newRoot;
			else
				node->parent->right = newRoot;
		}
		node->left = newRoot->right;
		if (newRoot->right != NULL)
			newRoot->right->parent = node;
		node->parent = newRoot;
		newRoot->right = node;
		if (newRoot->parent == NULL)
			_rootNode = newRoot;
	};
	
	void baseCheck(Node *n) {
		if (n->parent == NULL)
			n->color = black;
		else {
			if (n->parent->color == black)
				return;
			else {
				Node *u = findUncle(n);
				Node *g;
				if ((u != NULL) && (u->color == red)) {
					n->parent->color = black;
					u->color = black;
					g = findGrandparent(n);
					g->color = red;
					baseCheck(g);
				} else
					rotateOperations(n);
			}
		}
	};
	
	void rotateOperations(Node *n)	{
		Node *g = findGrandparent(n);
		if ((n == n->parent->right) && (n->parent == g->left)) {
			rotateLeft(n->parent);
			n = n->left;
		} else if ((n == n->parent->left) && (n->parent == g->right)) {
			rotateRight(n->parent);
			n = n->right;
		}
		g = findGrandparent(n);
		n->parent->color = black;
		g->color = red;
		if ((n == n->parent->left) && (n->parent == g->left)) {
			rotateRight(g);
		} else
			rotateLeft(g);
	};
	
	void balanceTree(Node *node) {
		baseCheck(node);
	};
	
	void balanceTreeDeleted(Node *x) {
		while (x != _rootNode && x->color == black) {
			if (x == x->parent->left) {
				Node *w = x->parent->right;
				if (w->color == red) {
					w->color = black;
					x->parent->color = red;
					rotateLeft (x->parent);
					w = x->parent->right;
				}
				if ((w->left == NULL || w->left->color == black) && (w->right == NULL || w->right->color == black)) {
					w->color = red;
					x = x->parent;
				} else {
					if (w->right == NULL || w->right->color == black) {
						w->left->color = black;
						w->color = red;
						rotateRight (w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = black;
					w->right->color = black;
					rotateLeft (x->parent);
					x = _rootNode;
				}
			} else {
				Node *w = x->parent->left;
				if (w->color == red) {
					w->color = black;
					x->parent->color = red;
					rotateRight (x->parent);
					w = x->parent->left;
				}
				if ((w->right == NULL || w->right->color == black) && (w->left == NULL || w->left->color == black)) {
					w->color = red;
					x = x->parent;
				} else {
					if (w->left == NULL || w->left->color == black) {
						w->right->color = black;
						w->color = red;
						rotateLeft (w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = black;
					w->left->color = black;
					rotateRight (x->parent);
					x = _rootNode;
				}
			}
		}
		x->color = black;
	};
	
	static Node *findLeftmost(Node *n) {
		if (n == NULL)
			return NULL;
		while (n->left != NULL && n->left != n->left->left)
			n = n->left;
		return n;
	};
	
	static Node *findRightmost(Node *n) {
		if (n == NULL)
			return NULL;
		while (n->right != NULL && n->right != n->right->right)
			n = n->right;
		return n;
	};
	
	void reassignNodeLinks(Node *n1, Node *n2) {
		n1->left = n2->left;
		n1->right = n2->right;
		n1->parent = n2->parent;
		if (n2->left != NULL && n2->left != _abstractNode)
			n2->left->parent = n1;
		if (n2->right != NULL && n2->right != _abstractNode) {
			n2->right->parent = n1;
		}
		if (n2->parent != NULL) {
			if (n2 == n2->parent->left)
				n2->parent->left = n1;
			else if (n2 == n2->parent->right)
				n2->parent->right = n1;
		}
	};
	
	void swapNode(Node* node, Node* repl) {
		
		Node tmp;
		if (node == _rootNode) {
			_rootNode = repl;
		}
		bool nodeColor = node->color;
		node->color = repl->color;
		repl->color = nodeColor;
		reassignNodeLinks(&tmp, node);
		reassignNodeLinks(node, repl);
		reassignNodeLinks(repl, &tmp);
		if (node->left == _abstractNode)
			_abstractNode->left = repl;
		if (node->right == _abstractNode)
			_abstractNode->right = repl;
	};
	
	//MARK: - PUBLIC
public:
	class iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		Node *_data;
	public:
		explicit iterator(Node *inputData = 0): _data(inputData) {};
		iterator(const iterator & copy) { *this = copy; };
		~iterator() {};
		iterator & operator=(const iterator & right) { _data = right._data; return *this; };
		iterator & operator++() { _data = nextNodePlus(_data); return *this; }
		iterator & operator--() {_data = nextNodeMinus(_data); return *this; }
		iterator operator++(int) { iterator tmp(_data); operator++(); return tmp; }
		iterator operator--(int) { iterator tmp(_data); operator--(); return tmp; }
		value_type & operator*() const { return *(_data->data); };
		value_type * operator->() const {return _data->data; };
		bool operator==(const iterator & right) const { return _data == right._data; };
		bool operator!=(const iterator & right) const { return _data != right._data; };
		bool operator==(const const_iterator & right) const { return _data == right.getData(); };
		bool operator!=(const const_iterator & right) const { return _data != right.getData(); };
		Node *getData() const { return _data; }
		
	private:
		Node *nextNodePlus(Node *n) {
			if (n->right != NULL && n->right->right == n) {
				if (n->left != NULL && n == n->left->left) {
					return n->right;
				}
				if (n->parent == NULL && n == n->left->left && n == n->right->right)
					return n;
				return n->right;
			}
			if (n->right != NULL)
				return findLeftmost(n->right);
			while (n == n->parent->right)
				n = n->parent;
			return n->parent;
		};
		
		Node *nextNodeMinus(Node *n) {
			if (n->right != NULL && n->right->right == n && n->parent == NULL)
				return n->right;
			if (n->left != NULL && n->left->left == n) {
				if (n->parent == NULL)
					return n;
				return n->left;
			}
			if (n->left != NULL)
				return findRightmost(n->left);
			while (n == n->parent->left)
				n = n->parent;
			return n->parent;
		};
	};
	
	class const_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type const> {
	private:
		Node *_data;
	public:
		explicit const_iterator(Node *inputData = 0): _data(inputData) {};
		const_iterator(const const_iterator & copy) { *this = copy; };
		const_iterator(const iterator & copy) { *this = copy; };
		~const_iterator() {};
		const_iterator & operator=(const const_iterator & right) { _data = right._data; return *this; };
		const_iterator & operator=(const iterator & right) { _data = right.getData(); return *this; };
		const_iterator & operator++() {_data = nextNodePlus(_data); return *this; }
		const_iterator & operator--() {_data = nextNodeMinus(_data); return *this; }
		const_iterator operator++(int) { const_iterator tmp(_data); operator++(); return tmp; }
		const_iterator operator--(int) { const_iterator tmp(_data); operator--(); return tmp; }
		const value_type & operator*() const { return *(_data->data); };
		const value_type * operator->() const {return _data->data; };
		bool operator==(const const_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_iterator & right) const { return _data != right._data; };
		bool operator==(const iterator & right) const { return _data == right.getData(); };
		bool operator!=(const iterator & right) const { return _data != right.getData(); };
		Node *getData() const { return _data; };
		
	private:
		Node *nextNodePlus(Node *n) {
			if (n->right != NULL && n->right->right == n) {
				if (n->left != NULL && n == n->left->left)
					return n->right;
				if (n->parent == NULL && n == n->left->left && n == n->right->right)
					return n;
				return n->right;
			}
			if (n->right != NULL)
				return findLeftmost(n->right);
			while (n == n->parent->right)
				n = n->parent;
			return n->parent;
		};
		
		Node *nextNodeMinus(Node *n) {
			if (n->right != NULL && n->right->right == n && n->parent == NULL)
				return n->right;
			if (n->left != NULL && n->left->left == n) {
				if (n->parent == NULL)
					return n;
				return n->left;
			}
			if (n->left != NULL)
				return findRightmost(n->left);
			while (n == n->parent->left)
				n = n->parent;
			return n->parent;
		};
	};
	
	class reverse_iterator: public ft::reverse_iterator<map::iterator> {
	private:
		Node *_data;
	public:
		explicit reverse_iterator(Node *inputData = 0): _data(inputData) {};
		reverse_iterator(const reverse_iterator & copy) { *this = copy; };
		~reverse_iterator() {};
		reverse_iterator & operator=(const reverse_iterator & right) { _data = right._data; return *this; };
		reverse_iterator & operator++() {_data = nextNodeMinus(_data); return *this; }
		reverse_iterator & operator--() {_data = nextNodePlus(_data); return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(_data); operator++(); return tmp; }
		reverse_iterator operator--(int) { reverse_iterator tmp(_data); operator--(); return tmp; }
		const value_type & operator*() const { return *(_data->data); };
		const value_type * operator->() const {return _data->data; };
		bool operator==(const reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const reverse_iterator & right) const { return _data != right._data; };
		Node *getData() const { return _data; };
		
	private:
		Node *nextNodePlus(Node *n) {
			if (n->right != NULL && n->right->right == n) {
				if (n->left != NULL && n == n->left->left) {
					return n->left;
				}
				if (n->parent == NULL && n == n->left->left && n == n->right->right)
					return n;
				return n->right;
			}
			if (n->right != NULL)
				return findLeftmost(n->right);
			while (n == n->parent->right)
				n = n->parent;
			return n->parent;
		};
		
		Node *nextNodeMinus(Node *n) {
			if (n->right != NULL && n->right->right == n && n->parent == NULL)
				return n->right;
			if (n->left != NULL && n->left->left == n) {
				if (n->parent == NULL)
					return n;
				return n->left;
			}
			if (n->left != NULL)
				return findRightmost(n->left);
			while (n == n->parent->left)
				n = n->parent;
			return n->parent;
		};
	};
	
	class const_reverse_iterator: public ft::reverse_iterator<map::iterator> {
	private:
		Node *_data;
	public:
		explicit const_reverse_iterator(Node *inputData = 0): _data(inputData) {};
		const_reverse_iterator(const const_reverse_iterator & copy) { *this = copy; };
		const_reverse_iterator(const reverse_iterator & copy) { *this = copy; };
		~const_reverse_iterator() {};
		const_reverse_iterator & operator=(const const_reverse_iterator & right) { _data = right._data; return *this; };
		const_reverse_iterator & operator=(const reverse_iterator & right) { _data = right.getData(); return *this; };
		const_reverse_iterator & operator++() {_data = nextNodeMinus(_data); return *this; }
		const_reverse_iterator & operator--() {_data = nextNodePlus(_data); return *this; }
		const_reverse_iterator operator++(int) { const_reverse_iterator tmp(_data); operator++(); return tmp; }
		const_reverse_iterator operator--(int) { const_reverse_iterator tmp(_data); operator--(); return tmp; }
		const value_type & operator*() const { return *(_data->data); };
		const value_type * operator->() const {return _data->data; };
		bool operator==(const const_reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_reverse_iterator & right) const { return _data != right._data; };
		bool operator==(const reverse_iterator & right) const { return _data == right.getData(); };
		bool operator!=(const reverse_iterator & right) const { return _data != right.getData(); };
		Node *getData() const { return _data; };
		
	private:
		Node *nextNodePlus(Node *n) {
			if (n->right != NULL && n->right->right == n) {
				if (n->left != NULL && n == n->left->left) {
					return n->right;
				}
				if (n->parent == NULL && n == n->left->left && n == n->right->right)
					return n;
				return n->right;
			}
			if (n->right != NULL)
				return findLeftmost(n->right);
			while (n == n->parent->right)
				n = n->parent;
			return n->parent;
		};
		
		Node *nextNodeMinus(Node *n) {
			if (n->right != NULL && n->right->right == n && n->parent == NULL)
				return n->right;
			if (n->left != NULL && n->left->left == n) {
				if (n->parent == NULL)
					return n;
				return n->left;
			}
			if (n->left != NULL)
				return findRightmost(n->left);
			while (n == n->parent->left)
				n = n->parent;
			return n->parent;
		};
	};
	
	//MARK: -- Public methods
	
	//MARK: --- Constructors:
	
	explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()): _alloc(alloc), _comp(comp), _size(0), _rootNode(NULL) {
		_abstractNode = createAbstractNode();
	};
	
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _size(0), _rootNode(NULL) {
		_abstractNode = createAbstractNode();
		insert(first, last);
	};

	map (const map & x) {
		_size = 0;
		_abstractNode = createAbstractNode();
		*this = x;
	};
	
	map & operator=(const map & x) {
		if (this == &x)
			return *this;
		if (_size != 0)
			clear();
		insert(x.begin(), x.end());
		return *this;
	};
	
	
	//MARK: --- Iterators:
	iterator begin() {
		return iterator(_abstractNode->left);
	};
	
	const_iterator begin() const {
		return const_iterator(_abstractNode->left);
	};
	
	iterator end() {
		return iterator(_abstractNode);
	};
	
	const_iterator end() const {
		return const_iterator(_abstractNode);
	};
	
	reverse_iterator rbegin() {
		return reverse_iterator(_abstractNode->right);
	};
	
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(_abstractNode->right);
	};
	
	reverse_iterator rend() {
		return reverse_iterator(_abstractNode);
	};
	
	const_reverse_iterator rend() const {
		return const_reverse_iterator(_abstractNode);
	};
	
	//MARK: --- Capacity:
	bool empty() const {
		return _size == 0;
	};
	
	size_type size() const {
		return _size;
	};
	
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(_rootNode);
	};
	
	//MARK: --- Element access:
	mapped_type & operator[] (const key_type &k) {
		const value_type val = std::make_pair(k, mapped_type());
		return (*(insert(val)).first).second;
	};
	
	//MARK: --- Modifiers:
	std::pair<iterator, bool> insert(const value_type & val) {
		Node *newNode = _rootNode;
		if (_size == 0) {
			createRootNode(val);
			newNode = _rootNode;
		}
		else {
			Node *position = findNodePosition(val);
			if (position->data->first == val.first)
				return std::make_pair(iterator(position), false);
			newNode = createNode(position, val, red);
			if (val.first < position->data->first) {
				newNode->left = position->left;
				if (position->left == _abstractNode)
					_abstractNode->left = newNode;
				position->left = newNode;
				_size += 1;
			} else {
				newNode->right = position->right;
				if (position->right == _abstractNode)
					_abstractNode->right = newNode;
				position->right = newNode;
				_size += 1;
			}
			balanceTree(newNode);
		}
		return std::make_pair(iterator(newNode), true);
	};
	
	iterator insert(iterator position, const value_type& val) {
		(void)position;
		return iterator(insert(val));
	};
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last, typename ft::enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
		for (; first != last; first++) {
			insert(*first);
		}
	};
	
	void erase (iterator position) {
		erase((*position).first);
	};
	
	void erase (iterator first, iterator last) {
		for (; first != last;) {
			iterator tmp = first;
			++first;
			erase(tmp);
		}
	};
	
	size_type erase (const key_type & k) {
		Node *n = findNodePositionKey(k);
		if (n == NULL)
			return 0;
		if (n == _rootNode && n->left != NULL && n == n->left->left && n->right != NULL && n == n->right->right) {
			_abstractNode->left = _abstractNode;
			_abstractNode->right = _abstractNode;
			_size = 0;
			destroyAndDeallocNode(n);
			return 1;
		}
		_abstractNode->left->left = NULL;
		_abstractNode->right->right = NULL;
		Node tmp;
		tmp.color = black;
		tmp.left = &tmp;
		tmp.right = &tmp;
		tmp.parent = NULL;
		_size -= 1;
		Node *x, *y;
		if (n->left == NULL || n->right == NULL )
			y = n;
		else
			y = findLeftmost(n->right);
		if (y->left != NULL)
			x = y->left;
		else if (y->right != NULL)
			x = y->right;
		else
			x = &tmp;
		x->parent = y->parent;
		if (y->parent)
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
			else
				_rootNode = x;
		bool isNode = false;
		if (y != n)
			isNode = true;
		if (n->color == black)
			balanceTreeDeleted (x);
		if (isNode)
			swapNode(n, y);
		if (tmp.parent != NULL && &tmp == tmp.parent->left)
			tmp.parent->left = NULL;
		else if (tmp.parent != NULL && &tmp == tmp.parent->right)
			tmp.parent->right = NULL;
		if (n->parent != NULL && n == n->parent->left)
			n->parent->left = NULL;
		else if (n->parent != NULL && n == n->parent->right)
			n->parent->right = NULL;
		destroyAndDeallocNode(n);
		Node *limit = findLeftmost(_rootNode);
		if (limit == NULL)
			_abstractNode->left = _abstractNode;
		else
			_abstractNode->left = limit;
		limit->left = _abstractNode;
		limit = findRightmost(_rootNode);
		if (limit == NULL)
			_abstractNode->right = _abstractNode;
		else
			_abstractNode->right = limit;
		limit->right = _abstractNode;
		return 1;
	};
	
	void swap (map& x) {
		Node *tmpRootNode = _rootNode;
		Node *tmpAbstNode = _abstractNode;
		size_type tmpSize = _size;
		_rootNode = x._rootNode;
		_abstractNode = x._abstractNode;
		_size = x._size;
		x._rootNode = tmpRootNode;
		x._abstractNode = tmpAbstNode;
		x._size = tmpSize;
	};
	
	void clear() {
		erase(this->begin(), this->end());
	};
	
	//MARK: --- Observers:
	key_compare key_comp() const {
		return _comp;
	};
	
	value_compare value_comp() const {
		return value_compare(_comp);
	};
	
	//MARK: --- Operations:
	iterator find(const key_type & k) {
		Node *tmp = findNodePositionKey(k);
		return (tmp == NULL) ? end() : iterator(tmp);
	};
	
	const_iterator find(const key_type & k) const {
		Node *tmp = findNodePositionKey(k);
		return (tmp == NULL) ? end() : const_iterator(tmp);
	};
	
	size_type count(const key_type & k) const {
		Node *tmp = findNodePositionKey(k);
		return (tmp == NULL) ? 0 : 1;
	};
	
	iterator lower_bound(const key_type & k) {
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; it++) {
			if (_comp(it->first, k) == false)
				return it;
		}
		return it;
	};
	
	const_iterator lower_bound (const key_type & k) const {
		const_iterator it = begin();
		const_iterator ite = end();
		for (; it != ite; it++) {
			if (_comp(it->first, k) == false)
				return it;
		}
		return it;
	};
	
	iterator upper_bound (const key_type& k) {
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; it++) {
			if (_comp(k, it->first) == true)
				return it;
		}
		return it;
	};
	
	const_iterator upper_bound (const key_type& k) const {
		const_iterator it = begin();
		const_iterator ite = end();
		for (; it != ite; it++) {
			if (_comp(k, it->first) == true)
				return it;
		}
		return it;
	};
	
	std::pair<const_iterator, const_iterator> equal_range(const key_type & k) const {
		const_iterator first = lower_bound(k);
		const_iterator second = upper_bound(k);
		return std::make_pair(first, second);
	};
	
	std::pair<iterator, iterator> equal_range(const key_type & k) {
		iterator first = lower_bound(k);
		iterator second = upper_bound(k);
		return std::make_pair(first, second);
	};
	
	//MARK: --- Destructor
	~map() {
		clear();
		destroyAndDeallocNode(_abstractNode);
	};

};

#endif
