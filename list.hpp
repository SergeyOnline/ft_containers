//
//  list.hpp
//  ft_containers
//
//  Created by Сергей on 24.01.2021.
//

#ifndef list_hpp
#define list_hpp

#include "ft.hpp"

template <class T>
struct listNode {
	T			*data;
	listNode	*prev;
	listNode	*next;
};

template <class T, class Alloc>
class ft::list {
	
	//MARK: - PUBLIC
public:
	
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	typedef T																	value_type;
	typedef Alloc																allocator_type;
	typedef value_type&														reference;
	typedef const value_type&													const_reference;
	typedef value_type*														pointer;
	typedef const value_type*													const_pointer;
	typedef size_t 																size_type;
	typedef typename std::allocator<T>::template rebind<listNode<T> >::other	allocator_node;
	
	class iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		listNode<T> *_data;
	public:
		explicit iterator(listNode<T> *inputData = 0): _data(inputData) {};
		iterator(const iterator & copy) { *this = copy; };
		~iterator() {};
		iterator & operator=(const iterator & right) { _data = right._data; return *this; };
		iterator & operator++() {_data = _data->next; return *this; }
		iterator & operator--() {_data = _data->prev; return *this; }
		iterator operator++(int) { iterator tmp(_data); operator++(); return tmp; }
		iterator operator--(int) { iterator tmp(_data); operator--(); return tmp; }
		T & operator*() const { return *(_data->data); };
		T * operator->() const {return _data->data; };
		bool operator==(const iterator & right) const { return _data == right._data; };
		bool operator!=(const iterator & right) const { return _data != right._data; };
		bool operator==(const const_iterator & right) const { return _data == right.getData(); };
		bool operator!=(const const_iterator & right) const { return _data != right.getData(); };
		listNode<T> *getData() const { return _data; }
	};
	
	class const_iterator: public ft::iterator<std::bidirectional_iterator_tag, value_type const> {
	private:
		listNode<T> *_data;
	public:
		explicit const_iterator(listNode<T> *inputData = 0): _data(inputData) {};
		const_iterator(const const_iterator & copy) { *this = copy; };
		const_iterator(const iterator & copy) { *this = copy; };
		~const_iterator() {};
		const_iterator & operator=(const const_iterator & right) { _data = right._data; return *this; };
		const_iterator & operator=(const iterator & right) { _data = right.getData(); return *this; };
		const_iterator & operator++() {_data = _data->next; return *this; }
		const_iterator & operator--() {_data = _data->prev; return *this; }
		const_iterator operator++(int) { const_iterator tmp(_data); operator++(); return tmp; }
		const_iterator operator--(int) { const_iterator tmp(_data); operator--(); return tmp; }
		const T & operator*() const { return *(_data->data); };
		const T * operator->() const {return _data->data; };
		bool operator==(const const_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_iterator & right) const { return _data != right._data; };
		bool operator==(const iterator & right) const { return _data == right.getData(); };
		bool operator!=(const iterator & right) const { return _data != right.getData(); };
		listNode<T> *getNode() const { return _data; }
	};
	
	class reverse_iterator: public ft::reverse_iterator<list::iterator> {
	private:
		listNode<T> *_data;
		reverse_iterator(): _data() {};
	public:
		reverse_iterator(listNode<T> *inputData): _data(inputData) {};
		reverse_iterator(const reverse_iterator & copy) { *this = copy; };
		~reverse_iterator() {};
		reverse_iterator & operator=(const reverse_iterator & right) {
			_data = right._data;
			return *this;
		};
		reverse_iterator & operator++() {_data = _data->prev; return *this; }
		reverse_iterator & operator--() {_data = _data->next; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(*this); operator++(); return tmp; }
		reverse_iterator operator--(int) { reverse_iterator tmp(*this); operator--(); return tmp; }
		T & operator*() { return *(_data->data); };
		T * operator->() {return *(_data->data); };
		bool operator==(const reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const reverse_iterator & right) const { return _data != right._data; };
		listNode<T> *getNode() const { return _data; }
	};
	
	class const_reverse_iterator: public ft::reverse_iterator<list::iterator> {
	private:
		listNode<T> *_data;
		const_reverse_iterator(): _data() {};
	public:
		const_reverse_iterator(listNode<T> *inputData): _data(inputData) {};
		const_reverse_iterator(const const_reverse_iterator & copy) { *this = copy; };
		~const_reverse_iterator() {};
		const_reverse_iterator & operator=(const const_reverse_iterator & right) {
			_data = right._data;
			return *this;
		};
		const_reverse_iterator & operator++() {_data = _data->prev; return *this; };
		const_reverse_iterator & operator--() {_data = _data->next; return *this; };
		const_reverse_iterator operator++(int) { const_reverse_iterator tmp(*this); operator++(); return tmp; };
		const_reverse_iterator operator--(int) { const_reverse_iterator tmp(*this); operator--(); return tmp; };
		const T & operator*() const { return *(_data->data); };
		const T * operator->() const {return *(_data->data); };
		bool operator==(const const_reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_reverse_iterator & right) const { return _data != right._data; };
		listNode<T> *getNode() const { return _data; }
	};
	
	//MARK: -- Public methods
	
	//MARK: --- Constructors:
	explicit list (const allocator_type& alloc = allocator_type()): _size(0), _allocator(alloc) {
		allocateNodeBase();
		_node_end = _node_base;
	};
	
	explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(0), _allocator(alloc) {
		allocateNodeBase();
		_node_end = _node_base;
		insert(begin(), n, val);
	};
	
	template <class InputIterator>
	list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<is_input_iterator<InputIterator>::value>::type* = 0): _size(0), _allocator(alloc) {
		allocateNodeBase();
		_node_end = _node_base;
		insert(begin(), first, last);
	};
	
	list (const list& x): _size(0) {
		allocateNodeBase();
		*this = x;
	};
	
	list & operator= (const list & x) {
		if (this == &x)
			return *this;
		clear();
		if (_size == 0) {
			_allocator.destroy(_node_base->data);
			_allocator.deallocate(_node_base->data, 1);
			_allocator_node.destroy(_node_base);
			_allocator_node.deallocate(_node_base, 1);
		}
		allocateNodeBase();
		_node_end = _node_base;
		insert(begin(), x.begin(), x.end());
		return *this;
	};
	
	//MARK: --- Iterators:
	iterator begin() {
		return iterator(_node_base);
	};
	
	iterator end() {
		return iterator(_node_end);
	};
	
	const_iterator begin() const {
		return const_iterator(_node_base);
	};
	
	const_iterator end() const {
		return const_iterator(_node_end);
	};
	
	reverse_iterator rbegin() {
		return reverse_iterator(_node_end->prev);
	};
	
	reverse_iterator rend() {
		return reverse_iterator(_node_base->prev);
	};
	
	const_reverse_iterator rbegin() const {
		return reverse_iterator(end());
	};
	
	const_reverse_iterator rend() const {
		return reverse_iterator(begin());
	};
	
	//MARK: --- Capacity:
	bool empty() const {
		return (_size == 0);
	};
	
	size_type size() const {
		return _size;
	};
	
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(_node_base);
	};
	
	//MARK: --- Element access:
	reference front() {
		return *(begin());
	};
	
	const_reference front() const {
		return *(begin());
	};
	
	reference back() {
		return *(--end());
	};
	
	const_reference back() const {
		return *(--end());
	};
	
	//MARK: --- Modifiers:
	
	iterator insert (iterator position, const value_type& val) {
		listNode<T> *newNode = _allocator_node.allocate(1);
		_allocator_node.construct(newNode);
		newNode->data = _allocator.allocate(1);
		_allocator.construct(newNode->data);
		newNode->prev = (position.getData())->prev;
		newNode->next = position.getData();
		position.getData()->prev = newNode;
		*(newNode->data) = val;
		if (newNode->prev == NULL)
			_node_base = newNode;
		else
			newNode->prev->next = newNode;
		_size += 1;
		return iterator(newNode);
	};
	
	void insert (iterator position, size_type n, const value_type& val) {
		for (size_type i = 0; i < n; i++) {
			insert(position, val);
		}
	};
	
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
		for (; first != last; first++) {
			position = insert(position, *first);
			position++;
		}
	};
	
	iterator erase (iterator position) {
		iterator it = position;
		it++;
		return erase(position, it);
	};
	
	iterator erase (iterator first, iterator last) {
		listNode<T> *nodePrev = (first.getData())->prev;
		listNode<T> *nodeNext = last.getData();
		iterator it = first;
		for (; it != last; ) {
			iterator tmp = it;
			it++;
			_allocator.destroy((tmp.getData())->data);
			_allocator.deallocate((tmp.getData())->data, 1);
			_allocator_node.destroy(tmp.getData());
			_allocator_node.deallocate(tmp.getData(), 1);
			_size -= 1;
		}
		if (nodePrev == NULL) {
			_node_base = nodeNext;
		}
		else
			nodePrev->next = nodeNext;
		nodeNext->prev = nodePrev;
		return iterator(nodeNext);
	};
	
	void clear() {
		if (_size == 0)
			return;
		erase(begin(), end());
	};
	
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_input_iterator<InputIterator>::value>::type* = 0) {
		clear();
		insert(begin(), first, last);
	};
	
	void assign (size_type n, const value_type& val) {
		clear();
		insert(begin(), n, val);
	};
	
	void push_front (const value_type& val) {
		insert(begin(), val);
	};
	
	void pop_front() {
		erase(begin());
	};
	
	void push_back (const value_type& val) {
		iterator it = end();
		insert(it, val);
	};
	
	void pop_back() {
		iterator it = end();
		it--;
		erase(it);
	};
	
	void swap (list & x) {
		listNode<T> *tmp = _node_base;
		_node_base = x._node_base;
		x._node_base = tmp;
		tmp = _node_end;
		_node_end = x._node_end;
		x._node_end = tmp;
		size_type s = _size;
		_size = x._size;
		x._size = s;
	};
	
	void resize (size_type n, value_type val = value_type()) {
		if (n < _size) {
			iterator it = begin();
			for (size_type i = 0; i < n; i++) {
				it++;
			}
			erase(it, end());
		} else {
			iterator it = end();
			for (size_type i = _size; i < n; i++) {
				insert(it, val);
			}
		}
	};
	
	//MARK: --- Operations:
	void splice (iterator position, list& x) {
		splice(position, x, x.begin(), x.end());
	};

	void splice (iterator position, list& x, iterator i) {
		iterator it = i;
		it++;
		splice(position, x, i, it);
	};

	void splice (iterator position, list& x, iterator first, iterator last) {
		listNode<T> *currPrev = (position.getData())->prev;
		listNode<T> *currNext = position.getData();
		listNode<T> *xPrev = (first.getData())->prev;
		listNode<T> *xNext = (last.getData());
		size_type newSize = 0;
		for (; first != last; first++) {
			newSize += 1;
			listNode<T> *tmp = first.getData();
			if (currPrev == NULL)
				_node_base = tmp;
			else
				currPrev->next = tmp;
			tmp->prev = currPrev;
			currPrev = tmp;
		}
		currPrev->next = currNext;
		currNext->prev = currPrev;
		xNext->prev = xPrev;
		if (xPrev == NULL)
			x._node_base = xNext;
		else
			xPrev->next = xNext;
		x._size -= newSize;
		_size += newSize;
	};
	
	void remove (const value_type& val) {
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; it++) {
			if (*it == val)
				erase(it);
		}
	};
	
	template <class Predicate>
	void remove_if (Predicate pred) {
		iterator it = begin();
		iterator ite = end();
		for (; it != ite; it++) {
			if (pred(*it))
				erase(it);
		}
	};
	
	void unique() {
		iterator it = begin();
		iterator ite = end();
		if (it == ite)
			return;
		iterator tmp = it;
		tmp++;
		while (tmp != ite) {
			if (*it == *tmp) {
				tmp = erase(tmp);
			}
			else {
				it = tmp;
				tmp++;
			}
		}
	};
	
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred) {
		iterator it = begin();
		iterator ite = end();
		if (it == ite)
			return;
		iterator tmp = it;
		tmp++;
		while (it != ite) {
			if (binary_pred(*it, *tmp))
				tmp = erase(tmp);
			else {
				it = tmp;
				tmp++;
			}
		}
	};
	
	void merge (list& x) {
		if (&x == this)
			return;
		iterator it = begin();
		iterator ite = end();
		iterator xIt = x.begin();
		iterator xIte = x.end();
		for (; xIt != xIte; ) {
			while (it != ite && isFirstLesssSecond(*it, *xIt))
				it++;
			iterator tmp = xIt;
			xIt++;
			if ((it.getData())->prev == NULL)
				_node_base = tmp.getData();
			else
				(it.getData())->prev->next = tmp.getData();
			(tmp.getData())->prev = (it.getData())->prev;
			(it.getData())->prev = tmp.getData();
			(tmp.getData())->next = it.getData();
		}
		_size += x._size;
		x._size = 0;
		x._node_base = x._node_end;
		(x._node_end)->prev = NULL;
	};

	template <class Compare>
	void merge (list& x, Compare comp) {
		if (&x == this)
			return;
		iterator it = begin();
		iterator ite = end();
		iterator xIt = x.begin();
		iterator xIte = x.end();
		for (; xIt != xIte; ) {
			while (it != ite && comp(*it, *xIt))
				it++;
			iterator tmp = xIt;
			xIt++;
			if ((it.getData())->prev == NULL)
				_node_base = tmp.getData();
			else
				(it.getData())->prev->next = tmp.getData();
			(tmp.getData())->prev = (it.getData())->prev;
			(it.getData())->prev = tmp.getData();
			(tmp.getData())->next = it.getData();
		}
		_size += x._size;
		x._size = 0;
		x._node_base = x._node_end;
		(x._node_end)->prev = NULL;
	};

	void sort() {
		bool notSorted = true;
		while (notSorted) {
			notSorted = false;
			listNode<T> *curr = _node_base;
			listNode<T> *currNext = curr;
			currNext = currNext->next;
			while (currNext != _node_end) {
				if (*curr->data > *currNext->data) {
					listNode<T> *cPrev = curr->prev;
					listNode<T> *nNext = currNext->next;
					if (cPrev == NULL) {
						_node_base = currNext;
						currNext->prev = NULL;
					} else {
						currNext->prev = cPrev;
						cPrev->next = currNext;
					}
					currNext->next = curr;
					curr->prev = currNext;
					curr->next = nNext;
					nNext->prev = curr;
					notSorted = true;
					break;
				}
				currNext = currNext->next;
				curr = curr->next;
			}
		}
	};
	
	template <class Compare>
	void sort (Compare comp) {
		bool notSorted = true;
		while (notSorted) {
			notSorted = false;
			listNode<T> *curr = _node_base;
			listNode<T> *currNext = curr;
			currNext = currNext->next;
			while (currNext != _node_end) {
				if (comp(*curr->data, *currNext->data)) {
					listNode<T> *cPrev = curr->prev;
					listNode<T> *nNext = currNext->next;
					if (cPrev == NULL) {
						_node_base = currNext;
						currNext->prev = NULL;
					} else {
						currNext->prev = cPrev;
						cPrev->next = currNext;
					}
					currNext->next = curr;
					curr->prev = currNext;
					curr->next = nNext;
					nNext->prev = curr;
					notSorted = true;
					break;
				}
				currNext = currNext->next;
				curr = curr->next;
			}
		}
	};
	
	void reverse() {
		listNode<T> *curr = _node_base;
		listNode<T> *currEnd = _node_end->prev;
		for (size_type i = 0; i < _size / 2; i++) {
			listNode<T> *cPrev = curr->prev;
			listNode<T> *cNext = curr->next;
			listNode<T> *nNext = currEnd->next;
			listNode<T> *nPrev = currEnd->prev;
			if (cPrev == NULL) {
				_node_base = currEnd;
				currEnd->prev = NULL;
			} else {
				currEnd->prev = cPrev;
				cPrev->next = currEnd;
			}
			currEnd->next = cNext;
			cNext->prev = currEnd;
			nPrev->next = curr;
			curr->prev = nPrev;
			curr->next = nNext;
			nNext->prev = curr;
			curr = cNext;
			currEnd = nPrev;
		}
		if (_size % 2 == 0) {
			curr->next = currEnd;
			currEnd->prev = curr;
		}
	};
	
	//MARK: --- Destructor
	~list() {
		erase(begin(), end());
		_allocator.destroy(_node_base->data);
		_allocator.deallocate(_node_base->data, 1);
		_allocator_node.destroy(_node_base);
		_allocator_node.deallocate(_node_base, 1);
	};
	
	//MARK: - PRIVATE
private:
	listNode<T>			*_node_base;
	listNode<T>			*_node_end;
	size_type			_size;
	allocator_type		_allocator;
	allocator_node		_allocator_node;
	
	//MARK: -- Private methods
	void allocateNodeBase() {
		_node_base = _allocator_node.allocate(1);
		_allocator_node.construct(_node_base);
		_node_base->data = _allocator.allocate(1);
		_allocator.construct(_node_base->data);
		_node_base->prev = NULL;
		_node_base->next = NULL;
	};
	
	bool isFirstLesssSecond(T first, T second) { return first < second; };
	
};


template <class T, class Alloc>
bool ft::operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename ft::list<T>::const_iterator itLeft = lhs.begin();
	typename ft::list<T>::const_iterator iteLeft = lhs.end();
	typename ft::list<T>::const_iterator itRight = rhs.begin();
	typename ft::list<T>::const_iterator iteRight = rhs.end();
	for (; itLeft != iteLeft; itLeft++) {
		if (*itLeft != *itRight)
			return false;
		itRight++;
	}
	return true;
}

template <class T, class Alloc>
bool ft::operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(operator==(lhs, rhs));
};

template <class T, class Alloc>
bool ft::operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	typename ft::list<T>::const_iterator itLeft = lhs.begin();
	typename ft::list<T>::const_iterator iteLeft = lhs.end();
	typename ft::list<T>::const_iterator itRight = rhs.begin();
	typename ft::list<T>::const_iterator iteRight = rhs.end();
	for (; itLeft != iteLeft; itLeft++) {
		if (*itLeft > *itRight)
			return false;
		itRight++;
	}
	if (itLeft == iteLeft && itRight == iteRight) {
		itLeft--;
		itRight--;
		if (*itLeft == *itRight)
			return false;
	}
	return true;
};

template <class T, class Alloc>
bool ft::operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	typename ft::list<T>::const_iterator itLeft = lhs.begin();
	typename ft::list<T>::const_iterator iteLeft = lhs.end();
	typename ft::list<T>::const_iterator itRight = rhs.begin();
	typename ft::list<T>::const_iterator iteRight = rhs.end();
	for (; itLeft != iteLeft; itLeft++) {
		if (*itLeft > *itRight)
			return false;
		itRight++;
	}
	return true;
};

template <class T, class Alloc>
bool ft::operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(operator<=(lhs, rhs));
};

template <class T, class Alloc>
bool ft::operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(operator<(lhs, rhs));
};

template <class T, class Alloc>
void ft::swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) {
	x.swap(y);
};

#endif
