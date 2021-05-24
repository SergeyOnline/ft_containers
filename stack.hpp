//
//  stack.hpp
//  ft_containers_new
//
//  Created by Сергей on 02.02.2021.
//

#ifndef stack_h
#define stack_h

#include "ft.hpp"

template <class T, class Container>
class ft::stack {
	
	//MARK: - PUBLIC
public:
	typedef	T				value_type;
	typedef Container		container_type;
	typedef size_t			size_type;
	
	//MARK: -- Public methods
	
	//MARK: --- Constructors:
	explicit stack (const container_type& ctnr = container_type()) {
		_ctnr = ctnr;
	};
	
	//MARK: --- Destructor
	~stack() {};
	
	bool empty() const {
		return _ctnr.empty();
	};
	
	size_type size() const {
		return _ctnr.size();
	};
	
	value_type & top() {
		return _ctnr.back();
	};
	
	const value_type & top() const {
		return _ctnr.back();
	};
	
	void push (const value_type& val) {
		_ctnr.push_back(val);
	};
	
	void pop() {
		_ctnr.pop_back();
	};
	
	container_type getContainer() const {
		return _ctnr;
	}
	
	//MARK: - PRIVATE
private:
	container_type _ctnr;
};

template <class T, class Container> bool ft::operator==(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() == rhs.getContainer();
};

template <class T, class Container> bool ft::operator!=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() != rhs.getContainer();
};

template <class T, class Container> bool ft::operator<(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() < rhs.getContainer();
};

template <class T, class Container> bool ft::operator<=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() <= rhs.getContainer();
};

template <class T, class Container> bool ft::operator>(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() > rhs.getContainer();
};
template <class T, class Container> bool ft::operator>=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
	return lhs.getContainer() >= rhs.getContainer();
};

#endif
