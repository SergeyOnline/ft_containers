//
//  queue.hpp
//  ft_containers_new
//
//  Created by Сергей on 02.02.2021.
//

#ifndef queue_hpp
#define queue_hpp

#include "ft.hpp"

template <class T, class Container >
class ft::queue {
	
	//MARK: - PUBLIC
public:
	typedef	T				value_type;
	typedef Container		container_type;
	typedef size_t			size_type;
	
	//MARK: -- Public methods
	
	//MARK: --- Constructors:
	explicit queue(const container_type & ctnr = container_type()) {
		_ctnr = ctnr;
	};
	
	//MARK: --- Destructor
	~queue() {};
	
	bool empty() const {
		return _ctnr.empty();
	};
	
	size_type size() const {
		return _ctnr.size();
	};
	
	value_type & front() {
		return _ctnr.front();
	};
	
	const value_type & front() const {
		return _ctnr.front();
	};
	
	value_type & back() {
		return _ctnr.back();
	};
	
	const value_type & back() const {
		return _ctnr.back();
	};
	
	void push (const value_type & val) {
		_ctnr.push_back(val);
	};
	
	void pop() {
		_ctnr.pop_front();
	};
	
	container_type getContainer() const {
		return _ctnr;
	}
	
	//MARK: - PRIVATE
private:
	container_type _ctnr;
};

template <class T, class Container> bool ft::operator==(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() == rhs.getContainer();
};

template <class T, class Container> bool ft::operator!=(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() != rhs.getContainer();
};

template <class T, class Container> bool ft::operator<(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() < rhs.getContainer();
};

template <class T, class Container> bool ft::operator<=(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() <= rhs.getContainer();
};

template <class T, class Container> bool ft::operator>(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() > rhs.getContainer();
};

template <class T, class Container> bool ft::operator>=(const ft::queue<T, Container> & lhs, const ft::queue<T, Container> & rhs) {
	return lhs.getContainer() >= rhs.getContainer();
};

#endif
