//
//  vector.hpp
//  ft_containers
//
//  Created by Shira Broderick on 28/01/2021.
//  Copyright © 2021 Shira Broderick. All rights reserved.
//


#ifndef vector_hpp
#define vector_hpp

#include "ft.hpp"

template <class T, class Alloc>
class ft::vector {
	
	//MARK: - PUBLIC
public:
	
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef ptrdiff_t 									difference_type;
	typedef size_t										size_type;
	
	
	class iterator: public ft::iterator<std::random_access_iterator_tag, value_type> {
	private:
		value_type *_data;
	public:
		explicit iterator(value_type *inputData = 0): _data(inputData) {};
		iterator(const iterator & copy) { *this = copy; };
		~iterator() {};
		iterator & operator=(const iterator & right) {_data = right._data; return *this; };
		
		iterator & operator++() { _data++; return *this; }
		iterator & operator--() { _data--;  return *this; }
		iterator operator++(int) { iterator tmp(_data); operator++(); return tmp; }
		iterator operator--(int) { iterator tmp(_data); operator--(); return tmp; }
		T & operator*() const { return *_data; };
		T * operator->() const {return *_data; };
		bool operator==(const iterator & right) const { return _data == right._data; };
		bool operator!=(const iterator & right) const { return _data != right._data; };
		bool operator==(const const_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_iterator & right) const { return _data != right._data; };
		bool operator>(const iterator & right) const { return _data > right._data; };
		bool operator<(const iterator & right) const { return _data < right._data; };
		bool operator>=(const iterator & right) const { return _data >= right._data; };
		bool operator<=(const iterator & right) const { return _data <= right._data; };
		bool operator>(const const_iterator & right) const { return _data > right._data; };
		bool operator<(const const_iterator & right) const { return _data < right._data; };
		bool operator>=(const const_iterator & right) const { return _data >= right._data; };
		bool operator<=(const const_iterator & right) const { return _data <= right._data; };
		T & operator[](size_type index) const {
			iterator tmp(_data);
			for (size_type i = 0; i < index; i++) {
				tmp++;
			}
			return *tmp;
		};
		iterator & operator+(int num) { _data += num; return *this; }
		iterator & operator+=(int num) { _data += num; return *this; }
		iterator & operator-(int num) { _data -= num; return *this; }
		iterator & operator-=(int num) { _data -= num; return *this; }
	};
	
	class const_iterator: public ft::iterator<std::random_access_iterator_tag, value_type const> {
	private:
		value_type *_data;
	public:
		explicit const_iterator(value_type *inputData = 0): _data(inputData) {};
		const_iterator(const const_iterator & copy) { *this = copy; };
		~const_iterator() {};
		const_iterator & operator=(const const_iterator & right) {_data = right._data; return *this; };
		
		const_iterator & operator++() { _data++; return *this; }
		const_iterator & operator--() { _data--;  return *this; }
		const_iterator operator++(int) { const_iterator tmp(_data); operator++(); return tmp; }
		const_iterator operator--(int) { const_iterator tmp(_data); operator--(); return tmp; }
		const T & operator*() const { return *_data; };
		const T * operator->() const {return *_data; };
		bool operator==(const iterator & right) const { return _data == right._data; };
		bool operator!=(const iterator & right) const { return _data != right._data; };
		bool operator==(const const_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_iterator & right) const { return _data != right._data; };
		bool operator>(const const_iterator & right) const { return _data > right._data; };
		bool operator<(const const_iterator & right) const { return _data < right._data; };
		bool operator>=(const const_iterator & right) const { return _data >= right._data; };
		bool operator<=(const const_iterator & right) const { return _data <= right._data; };
		bool operator>(const iterator & right) const { return _data > right._data; };
		bool operator<(const iterator & right) const { return _data < right._data; };
		bool operator>=(const iterator & right) const { return _data >= right._data; };
		bool operator<=(const iterator & right) const { return _data <= right._data; };
		const T & operator[](size_type index) const {
			const_iterator tmp(_data);
			for (size_type i = 0; i < index; i++) {
				tmp++;
			}
			return *tmp;
		};
		const_iterator & operator+(int num) { _data += num; return *this; }
		const_iterator & operator+=(int num) { _data += num; return *this; }
		const_iterator & operator-(int num) { _data -= num; return *this; }
		const_iterator & operator-=(int num) { _data -= num; return *this; }
	};
	
	class reverse_iterator: public ft::reverse_iterator<vector::iterator> {
	private:
		value_type *_data;
	public:
		explicit reverse_iterator(value_type *inputData = 0): _data(inputData) {};
		reverse_iterator(const reverse_iterator & copy) { *this = copy; };
		~reverse_iterator() {};
		reverse_iterator & operator=(const reverse_iterator & right) {_data = right._data; return *this; };
		
		reverse_iterator & operator++() { _data--; return *this; }
		reverse_iterator & operator--() { _data++;  return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(_data); operator++(); return tmp; }
		reverse_iterator operator--(int) { reverse_iterator tmp(_data); operator--(); return tmp; }
		const T & operator*() const { return *_data; };
		const T * operator->() const {return *_data; };
		bool operator==(const reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const reverse_iterator & right) const { return _data != right._data; };
		bool operator==(const const_reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_reverse_iterator & right) const { return _data != right._data; };
		bool operator>(const reverse_iterator & right) const { return _data > right._data; };
		bool operator<(const reverse_iterator & right) const { return _data < right._data; };
		bool operator>=(const reverse_iterator & right) const { return _data >= right._data; };
		bool operator<=(const reverse_iterator & right) const { return _data <= right._data; };
		bool operator>(const const_reverse_iterator & right) const { return _data > right._data; };
		bool operator<(const const_reverse_iterator & right) const { return _data < right._data; };
		bool operator>=(const const_reverse_iterator & right) const { return _data >= right._data; };
		bool operator<=(const const_reverse_iterator & right) const { return _data <= right._data; };
		const T & operator[](size_type index) const {
			reverse_iterator tmp(_data);
			for (size_type i = 0; i < index; i++) {
				tmp--;
			}
			return *tmp;
		};
		const_iterator & operator+(int num) { _data -= num; return *this; }
		const_iterator & operator+=(int num) { _data -= num; return *this; }
		const_iterator & operator-(int num) { _data += num; return *this; }
		const_iterator & operator-=(int num) { _data += num; return *this; }
	};
	
	class const_reverse_iterator: public ft::reverse_iterator<vector::iterator> {
	private:
		value_type *_data;
	public:
		explicit const_reverse_iterator(value_type *inputData = 0): _data(inputData) {};
		const_reverse_iterator(const const_reverse_iterator & copy) { *this = copy; };
		~const_reverse_iterator() {};
		const_reverse_iterator & operator=(const const_reverse_iterator & right) {_data = right._data; return *this; };
		
		const_reverse_iterator & operator++() { _data--; return *this; }
		const_reverse_iterator & operator--() { _data++;  return *this; }
		const_reverse_iterator operator++(int) { reverse_iterator tmp(_data); operator++(); return tmp; }
		const_reverse_iterator operator--(int) { reverse_iterator tmp(_data); operator--(); return tmp; }
		const T & operator*() const { return *_data; };
		const T * operator->() const {return *_data; };
		bool operator==(const reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const reverse_iterator & right) const { return _data != right._data; };
		bool operator==(const const_reverse_iterator & right) const { return _data == right._data; };
		bool operator!=(const const_reverse_iterator & right) const { return _data != right._data; };
		bool operator>(const const_reverse_iterator & right) const { return _data > right._data; };
		bool operator<(const const_reverse_iterator & right) const { return _data < right._data; };
		bool operator>=(const const_reverse_iterator & right) const { return _data >= right._data; };
		bool operator<=(const const_reverse_iterator & right) const { return _data <= right._data; };
		bool operator>(const reverse_iterator & right) const { return _data > right._data; };
		bool operator<(const reverse_iterator & right) const { return _data < right._data; };
		bool operator>=(const reverse_iterator & right) const { return _data >= right._data; };
		bool operator<=(const reverse_iterator & right) const { return _data <= right._data; };
		const T & operator[](size_type index) const {
			const_reverse_iterator tmp(_data);
			for (size_type i = 0; i < index; i++) {
				tmp--;
			}
			return *tmp;
		};
		const_reverse_iterator & operator+(int num) { _data -= num; return *this; }
		const_reverse_iterator & operator+=(int num) { _data -= num; return *this; }
		const_reverse_iterator & operator-(int num) { _data += num; return *this; }
		const_reverse_iterator & operator-=(int num) { _data += num; return *this; }
	};
	
	//MARK: -- Public methods
	
	//MARK: --- Constructors:
	explicit vector (const allocator_type& alloc = allocator_type()): _ptr(0), _size(0), _capacity(0), _allocator(alloc) {};
	
	explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()): _size(n), _capacity(n), _allocator(alloc) {
		_ptr = _allocator.allocate(n);
		_allocator.construct(_ptr);
		T *tmp = _ptr;
		for (size_type i = 0; i < n; i++) {
			*tmp = val;
			tmp++;
		}
	};

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<is_input_iterator<InputIterator>::value>::type* = 0): _size(0), _capacity(0), _allocator(alloc) {
		InputIterator tmp = first;
		for (; tmp != last; tmp++)
			_size++;
		_capacity = _size;
		_ptr = _allocator.allocate(_capacity);
		_allocator.construct(_ptr);
		T *tmpPtr = _ptr;
		for (; first != last; first++) {
			*tmpPtr = *first;
			tmpPtr++;
		}
	};
	
	vector & operator = (const vector& x) {
		if (this == &x)
			return *this;
		clear();
		_ptr = _allocator.allocate(x._capacity);
		_allocator.construct(_ptr);
		insert(begin(), x.begin(), x.end());
		return *this;
	};
	


	
	vector (const vector & x) {
		*this = x;
	};
	
	//MARK: --- Destructor
	~vector() {
		clear();
		_allocator.deallocate(_ptr, _capacity);
	};
	
	//MARK: --- Iterators:
	iterator begin() {
		return iterator(_ptr);
	};
	
	const_iterator begin() const {
		return const_iterator(_ptr);
	};
	
	iterator end() {
		return iterator(_ptr + _size);
	};
	
	const_iterator end() const {
		return const_iterator(_ptr + _size);
	};
	
	reverse_iterator rbegin() {
		return reverse_iterator(_ptr + _size - 1);
	};
	
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(_ptr + _size - 1);
	};
	
	reverse_iterator rend() {
		return reverse_iterator(_ptr - 1);
	};
	
	const_reverse_iterator rend() const {
		return const_reverse_iterator(_ptr - 1);
	};
	
	//MARK: --- Capacity:
	size_type size() const {
		return _size;
	};
	
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / (sizeof(_ptr) / 2);
	};
	
	void resize (size_type n, value_type val = value_type()) {
		if (n <= _capacity) {
			value_type *ptrTmp = _ptr;
			for (size_type i = 0; i < n; i++) {
				if (i > _size)
					*ptrTmp = val;
				ptrTmp++;
			}
			_size = n;
		} else {
			value_type *newPtr = _allocator.allocate(n);
			_allocator.construct(newPtr);
			value_type *ptrTmp = _ptr;
			value_type *tmp = newPtr;
			for (size_type i = 0; i < n; i++) {
				if (i < _size) {
					*tmp = *ptrTmp;
					ptrTmp++;
				}
				else
					*tmp = val;
				tmp++;
			}
			clear();
			_allocator.deallocate(_ptr, _capacity);
			_size = n;
			_capacity = n;
			_ptr = newPtr;
		}
	};
	
	size_type capacity() const {
		return _capacity;
	};
	
	bool empty() const {
		return (_size == 0);
	};
	
	void reserve(size_type n) {
		if (n > max_size())
			throw std::length_error("ft::vector::_M_fill_insert");
		if (n <= _capacity)
			return;
		value_type *newPtr = _allocator.allocate(n);
		_allocator.construct(newPtr);
		value_type *ptrTmp = _ptr;
		value_type *tmp = newPtr;
		for (size_type i = 0; i < n; i++) {
			if (i < _size) {
				*tmp = *ptrTmp;
				ptrTmp++;
				tmp++;
			}
		}
		size_type s = _size;
		clear();
		_allocator.deallocate(_ptr, _capacity);
		_size = s;
		_capacity = n;
		_ptr = newPtr;
	};
	
	//MARK: --- Element access:
	reference operator[] (size_type n) {
		iterator it = begin();
		return it[n];
	};
	
	const_reference operator[] (size_type n) const {
		const_iterator it = begin();
		//FIXME: MB const T value = it[n];
		return it[n];
	};
	
	reference at(size_type n) {
		if (empty())
			throw std::out_of_range("ft::vector");
		if (n >= _size)
			throw std::out_of_range("ft::vector");
		iterator it = begin();
		return it[n];
	};
	
	const_reference at(size_type n) const {
		if (empty())
			throw std::out_of_range("ft::vector");
		if (n >= _size)
			throw std::out_of_range("ft::vector");
		const_iterator it = begin();
		return it[n];
	};

	reference front() {
		iterator it = begin();
		return *it;
	};
	
	const_reference front() const {
		const_iterator it = begin();
		return *it;
	};
	
	reference back() {
		iterator ite = end();
		ite--;
		return *ite;
	};
	
	const_reference back() const {
		const_iterator ite = end();
		ite--;
		return *ite;
	};
	
	//MARK: --- Modifiers:
	
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename ft::enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
		InputIterator tmp = first;
		size_type newSize = 0;
		for (; tmp != last; tmp++)
			newSize++;
		if (newSize > _capacity) {
			value_type *newPtr = _allocator.allocate(newSize);
			_allocator.construct(newPtr);
			clear();
			_allocator.deallocate(_ptr, _capacity);
			value_type *tmpPtr = newPtr;
			for (; first != last; first++) {
				*tmpPtr = *first;
				tmpPtr++;
			}
			_capacity = newSize;
			_ptr = newPtr;
		} else {
			clear();
			value_type *tmpPtr = _ptr;
			for (; first != last; first++) {
				*tmpPtr = *first;
				tmpPtr++;
			}
		}
		_size = newSize;
	};
	
	void assign (size_type n, const value_type& val) {
		if (n > _capacity) {
			value_type *newPtr = _allocator.allocate(n);
			_allocator.construct(newPtr);
			clear();
			_allocator.deallocate(_ptr, _capacity);
			value_type *tmpPtr = newPtr;
			for (size_type i = 0; i < n; i++) {
				*tmpPtr = val;
				tmpPtr++;
			}
			_capacity = n;
			_ptr = newPtr;
		} else {
			clear();
			value_type *tmpPtr = _ptr;
			for (size_type i = 0; i < n; i++) {
				*tmpPtr = val;
				tmpPtr++;
			}
		}
		_size = n;
	};
	
	void push_back (const value_type& val) {
		insert(end(), val);
	};
	
	void pop_back() {
		if (_size == 0)
			return;
		T *tmp = _ptr + _size - 1;
		_allocator.destroy(tmp);
		_size--;
	};
	
	iterator insert (iterator position, const value_type& val) {
		vector::iterator retit;
		if (_size == _capacity) {
			value_type *newPtr = _allocator.allocate((_capacity != 0) ? _capacity * 2 : 1);
			_allocator.construct(newPtr);
			vector::iterator it = begin();
			vector::iterator ite = end();
			value_type *tmp = newPtr;
			for (; it != position; it++) {
				*tmp = *it;
				tmp++;
			}
			retit = iterator(tmp);
			*tmp = val;
			tmp++;
			for (; it != ite; it++) {
				*tmp = *it;
				tmp++;
			}
			size_type size = _size;
			size_type capacity = _capacity;
			clear();
			_allocator.deallocate(_ptr, _capacity);
			_size = size + 1;
			_capacity = (capacity != 0) ? capacity * 2 : 1;
			_ptr = newPtr;
		} else {
			vector::iterator ite = end();
			retit = position;
			for (; ite != position; ite--) {
				iterator tmp = ite;
				*ite = *(tmp - 1);
			}
			*position = val;
			_size++;
		}
		return retit;
	};
	
	void insert (iterator position, size_type n, const value_type& val) {
		for (size_type i = 0; i < n; i++) {
			insert(position, val);
		}
	};
	
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last) {
		for (; first != last; first++) {
			position = insert(position, *first);
			position++;
		}
	};
	
	iterator erase (iterator position) {
		iterator ite = position;
		ite++;
		return erase(position, ite);
	};
	
	iterator erase (iterator first, iterator last) {
		iterator tmp = first;
		size_type rangeCount = 0;
		for (; tmp != last; tmp++) {
			rangeCount++;
		}
		tmp = last;
		iterator ret = first;
		for (; tmp != end(); tmp++) {
			*first = *tmp;
			first++;
			_allocator.destroy(&(*tmp));
		}
		_size -= rangeCount;
		return ret;
	};
	
	void swap (vector& x) {
		size_type size = _size;
		size_type capacity = _capacity;
		T *tmp = _ptr;
		_ptr = x._ptr;
		_size = x._size;
		_capacity = x.capacity();
		x._ptr = tmp;
		x._size = size;
		x._capacity = capacity;
	};
	
	void clear() {
		T *tmp = _ptr;
		for (size_type i = 0; i < _size; i++) {
			_allocator.destroy(tmp);
			tmp++;
		}
		_size = 0;
	};
	
	//MARK: - PRIVATE
private:
	value_type		*_ptr;
	size_type		_size;
	size_type		_capacity;
	allocator_type _allocator;
	
};

template <class T, class Alloc>
bool ft::operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::const_iterator itLeft = lhs.begin();
	typename ft::vector<T>::const_iterator iteLeft = lhs.end();
	typename ft::vector<T>::const_iterator itRight = rhs.begin();
	typename ft::vector<T>::const_iterator iteRight = rhs.end();
	for (; itLeft != iteLeft; itLeft++) {
		if (*itLeft != *itRight)
			return false;
		itRight++;
	}
	return true;
};

template <class T, class Alloc>
bool ft::operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return !(operator==(lhs, rhs));
};

template <class T, class Alloc>
bool ft::operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	typename ft::vector<T>::const_iterator itLeft = lhs.begin();
	typename ft::vector<T>::const_iterator iteLeft = lhs.end();
	typename ft::vector<T>::const_iterator itRight = rhs.begin();
	typename ft::vector<T>::const_iterator iteRight = rhs.end();
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
bool ft::operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	typename ft::vector<T>::const_iterator itLeft = lhs.begin();
	typename ft::vector<T>::const_iterator iteLeft = lhs.end();
	typename ft::vector<T>::const_iterator itRight = rhs.begin();
	typename ft::vector<T>::const_iterator iteRight = rhs.end();
	for (; itLeft != iteLeft; itLeft++) {
		if (*itLeft > *itRight)
			return false;
		itRight++;
	}
	return true;
};

template <class T, class Alloc>
bool ft::operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return !(operator<=(lhs, rhs));
};

template <class T, class Alloc>
bool ft::operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return !(operator<(lhs, rhs));
};

template <class T, class Alloc>
void ft::swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
	x.swap(y);
};

#endif
