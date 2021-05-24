//
//  main.cpp
//  ft_containers
//
//  Created by Shira Broderick on 10/01/2021.
//  Copyright © 2021 Shira Broderick. All rights reserved.
//

#include "list.hpp"
#include "vector.hpp"
#include "ft.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <map>


struct is_odd {
	bool operator() (const int & value) { return (value % 2 ) == 1; }
};

bool same_integral_part (float first, float second) {
	return ( int(first) == int(second) );
}

bool mycomparison (double first, double second) {
	return ( int(first) <= int(second) );
}

int main() {
	
//	{
//		std::vector<int> one(1, 1);
//		std::vector<int> two = one;
//		std::vector<int>::iterator it = two.begin();
//		std::vector<int>::iterator ite = two.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//	}
//	{
//		ft::vector<int> one(1, 1);
//		ft::vector<int> two = one;
//		ft::vector<int>::iterator it = two.begin();
//		ft::vector<int>::iterator ite = two.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//	}
	
//	ft::list<int> myList;
//	myList.push_back(3);
//	myList.push_back(4);
//	myList.push_back(5);
//	ft::list<int>::reverse_iterator it = myList.rbegin();
//	ft::list<int>::reverse_iterator ite = myList.rend();
//	for (; it != ite; it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;

//	FIXME: --LIST
	{
		ft::list<int> testC;
		ft::list<int> testCopy(5, 5);
		ft::list<int>::iterator itcopy = testCopy.begin();
		ft::list<int>::iterator itecopy = testCopy.end();
		for (; itcopy != itecopy; itcopy++) {
			std::cout << *itcopy << " ";
		}
		std::cout << std::endl;
		testC = testCopy;
		itcopy = testC.begin();
		itecopy = testC.end();
		for (; itcopy != itecopy; itcopy++) {
			std::cout << *itcopy << " ";
		}
		std::cout << std::endl;


		ft::list<int> myList;
		std::list<int> original;

		original.insert(original.begin(), 7);
		ft::list<int>::iterator ret = myList.insert(myList.begin(), 7);
		std::cout << "return value: " << *ret << std::endl;
		myList.insert(++(myList.begin()), 5);
		original.insert(++(original.begin()), 5);

		ft::list<int>::iterator it = myList.begin();
		ft::list<int>::iterator ite = myList.end();

		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::list<int>::iterator oit = original.begin();
		std::list<int>::iterator oite = original.end();

		for (; oit != oite; oit++) {
			std::cout << *oit << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "--------insert in range--------" << std::endl << std::endl;

		myList.insert(++(myList.begin()), 3, 3);
		original.insert(++(original.begin()), 3, 3);
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		oit = original.begin();
		oite = original.end();
		for (; oit != oite; oit++) {
			std::cout << *oit << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-------insert with iter-------" << std::endl << std::endl;

		ft::list<int> myList2;
		myList2.insert(myList2.begin(), 2, 2);
		myList2.insert(++(myList2.begin()), myList.begin(), myList.end());
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-------init whith value------" << std::endl << std::endl;

		ft::list<int> myList3(3, 4);
		it = myList3.begin();
		ite = myList3.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-------init whith iter-------" << std::endl << std::endl;

		ft::list<int> myList4(myList3.begin(), myList3.end());

		it = myList4.begin();
		ite = myList4.end();

		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "------------erase------------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		it++;
		myList.insert(it, 4);
		myList.insert(it, 4);
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		it = myList.begin();
		it++;
		ret = myList.erase(it);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "return value: " << *ret << std::endl;

		std::cout << std::endl << "--------erase in rang-------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		it = myList.begin();
		it++;
		ite = myList.end();
		ite--; ite--;
		ret = myList.erase(it, ite);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "return value: " << *ret << std::endl;
		std::cout << std::endl << "-----------assign----------" << std::endl << std::endl;
		myList2 = myList;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-----------copy------------" << std::endl << std::endl;
		myList3 = myList;
		it = myList3.begin();
		ite = myList3.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-----------front-----------" << std::endl << std::endl;
		std::cout << "front : " << myList3.front() << std::endl;
		const int value = myList3.front();
		std::cout << "const front : " << value << std::endl;

		std::cout << std::endl << "-----------back------------" << std::endl << std::endl;
		std::cout << "back : " << myList3.back() << std::endl;
		const int value2 = myList3.back();
		std::cout << "const back : " << value2 << std::endl;

		std::cout << std::endl << "--------size/empty---------" << std::endl << std::endl;
		std::cout << "size  : " << myList3.size() << std::endl;
		std::cout << "empty : " << (myList3.empty() ? "true" : "false") << std::endl;
		std::list<std::string> t;
		t.push_back("123");
		t.push_back("123");
		ft::list<std::string> t1;
		t1.push_back("123");
		t.push_back("123");
		std::cout << "max size original: " << t.max_size() << std::endl;
		std::cout << "max size my      : " << t1.max_size() << std::endl;
		std::cout << std::endl << "-----------assign------------" << std::endl << std::endl;
		myList2.insert(myList2.begin(), 3, 89);
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		myList.assign(it, ite);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-------assign with val-------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		myList.assign(4, 11);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "----------push front----------" << std::endl << std::endl;
		myList.push_front(55);
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << " * pop * " << std::endl;
		myList.pop_front();
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << std::endl << "----------push back-----------" << std::endl << std::endl;
		myList.push_back(55);
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << " * pop * " << std::endl;
		myList.pop_back();
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << std::endl << "------------swap-------------" << std::endl << std::endl;
		ft::list<int> first (3,100);
		ft::list<int> second (5,200);
		it = first.begin();
		ite = first.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		it = second.begin();
		ite = second.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "after swap: " << std::endl;
		first.swap(second);
		it = first.begin();
		ite = first.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		it = second.begin();
		ite = second.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "------resize smaller------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		myList.resize(2);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << std::endl << "------resize greater------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		myList.resize(5, 44);
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << std::endl << "--------splice all-------" << std::endl << std::endl;
		std::cout << "befor list 1: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << "befor list 2: " << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList2.size() << std::endl;
		it = myList.begin();
		it++; it++;
		myList.splice(it, myList2);
		std::cout << "position = 3: " << std::endl;
		std::cout << "after list 1: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << "after list 2: " << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList2.size() << std::endl;
		std::cout << std::endl << "--------splice one-------" << std::endl << std::endl;
		std::cout << "befor list 1: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << "befor list 2: " << std::endl;
		myList2.insert(myList2.begin(), 5, 66);
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList2.size() << std::endl;
		it = myList2.begin();
		it++; it++;
		ite = myList.begin();
		ite++; ite++;
		myList2.splice(it, myList, ite);
		std::cout << "position = 3: " << std::endl;
		std::cout << "after list 1: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList.size() << std::endl;
		std::cout << "after list 2: " << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "size  : " << myList2.size() << std::endl;
		std::cout << std::endl << "---------remove----------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		myList2.remove(66);
		std::cout << "after: " << std::endl;
		it = myList2.begin();
		ite = myList2.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "---remove pred (is odd)--" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		myList.remove_if(is_odd());
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "---------unique----------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		ft::list<float> myListFloat;
		myListFloat.push_back(3.1);
		myListFloat.push_back(3.44);
		myListFloat.push_back(3.44);
		myListFloat.push_back(7.34);
		myListFloat.push_back(8.1);
		myListFloat.push_back(8.1);
		myListFloat.push_back(8.1);
		myListFloat.push_back(8.1);
		myListFloat.push_back(11.1);
		myListFloat.push_back(3.1);
		myListFloat.push_back(11.1);
		myListFloat.push_back(11.1);
		ft::list<float>::iterator itf = myListFloat.begin();
		ft::list<float>::iterator itef = myListFloat.end();;
		for (; itf != itef; itf++) {
			std::cout << *itf << " ";
		}
		std::cout << std::endl;
		myListFloat.unique();
		std::cout << "after: " << std::endl;
		itf = myListFloat.begin();
		itef = myListFloat.end();
		for (; itf != itef; itf++) {
			std::cout << *itf << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-------unique pred------" << std::endl << std::endl;
		std::cout << "befor: " << std::endl;
		myListFloat.clear();
		myListFloat.push_back(2.72);
		myListFloat.push_back(3.14);
		myListFloat.push_back(12.15);
		myListFloat.push_back(12.77);
		myListFloat.push_back(15.3);
		myListFloat.push_back(72.25);
		myListFloat.push_back(73.0);
		myListFloat.push_back(73.35);
		itf = myListFloat.begin();
		itef = myListFloat.end();;
		for (; itf != itef; itf++) {
			std::cout << *itf << " ";
		}
		std::cout << std::endl;
		myListFloat.unique(same_integral_part);
		std::cout << "after: " << std::endl;
		itf = myListFloat.begin();
		itef = myListFloat.end();
		for (; itf != itef; itf++) {
			std::cout << *itf << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "---------merge----------" << std::endl << std::endl;
		ft::list<double> myDoubFirst;
		ft::list<double> myDoubSecond;
		myDoubFirst.push_back (3.1);
		myDoubFirst.push_back (2.2);
		myDoubFirst.push_back (2.9);
		myDoubSecond.push_back (3.7);
		myDoubSecond.push_back (7.1);
		myDoubSecond.push_back (1.4);
		std::cout << "befor myDoubFirst: " << std::endl;
		ft::list<double>::iterator itd = myDoubFirst.begin();
		ft::list<double>::iterator ited = myDoubFirst.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		std::cout << "befor myDoubSecond: " << std::endl;
		itd = myDoubSecond.begin();
		ited = myDoubSecond.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		myDoubFirst.merge(myDoubSecond);
		std::cout << "after myDoubFirst: " << std::endl;
		itd = myDoubFirst.begin();
		ited = myDoubFirst.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		std::cout << "after myDoubSecond: " << std::endl;
		itd = myDoubSecond.begin();
		ited = myDoubSecond.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl << "--merge comp with sort--" << std::endl << std::endl;
		myDoubFirst.clear();
		myDoubSecond.clear();
		myDoubFirst.push_back (3.1);
		myDoubFirst.push_back (2.2);
		myDoubFirst.push_back (2.9);
		myDoubSecond.push_back (3.7);
		myDoubSecond.push_back (7.1);
		myDoubSecond.push_back (1.4);
		myDoubFirst.sort();
		myDoubSecond.sort();
		std::cout << "befor myDoubFirst: " << std::endl;
		itd = myDoubFirst.begin();
		ited = myDoubFirst.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		std::cout << "befor myDoubSecond: " << std::endl;
		itd = myDoubSecond.begin();
		ited = myDoubSecond.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		myDoubFirst.merge(myDoubSecond, mycomparison);
		std::cout << "after myDoubFirst: " << std::endl;
		itd = myDoubFirst.begin();
		ited = myDoubFirst.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl;
		std::cout << "after myDoubSecond: " << std::endl;
		itd = myDoubSecond.begin();
		ited = myDoubSecond.end();
		for (; itd != ited; itd++) {
			std::cout << *itd << " ";
		}
		std::cout << std::endl << "---------sort---------" << std::endl << std::endl;
		myList.clear();
		myList.push_back(4);
		myList.push_back(9);
		myList.push_back(1);
		myList.push_back(0);
		myList.push_back(4);
		myList.push_back(8);
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		ft::list<int>::iterator pos = myList.begin();
		pos++;
		std::cout << "iterator val: " << *pos << std::endl;
		myList.sort();
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "iterator val: " << *pos << std::endl;
		std::cout << std::endl << "---------revers---------" << std::endl << std::endl;
		myList.clear();
		for (int i = 1; i < 10; i++) {
			myList.push_back(i);
		}
		std::cout << "befor: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		myList.reverse();
		std::cout << "after: " << std::endl;
		it = myList.begin();
		ite = myList.end();
		for (; it != ite; it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "-----operator == ------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 == myList3) ? "true" : "false") << std::endl;
		myList2.pop_back();
		myList2.push_back(5);
		std::cout << ((myList2 == myList3) ? "true" : "false") << std::endl;
		myList2.pop_back();
		myList2.push_back(4);
		myList2.push_back(6);
		std::cout << ((myList2 == myList3) ? "true" : "false") << std::endl;
		std::cout << std::endl << "-----operator != ------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 != myList3) ? "true" : "false") << std::endl;
		myList2.pop_back();
		myList2.push_back(5);
		std::cout << ((myList2 != myList3) ? "true" : "false") << std::endl;
		myList2.pop_back();
		myList2.push_back(4);
		myList2.push_back(6);
		std::cout << ((myList2 != myList3) ? "true" : "false") << std::endl;

		std::cout << std::endl << "-----operator < -------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 < myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(3);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 < myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(7);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 < myList3) ? "true" : "false") << std::endl;
		std::cout << std::endl << "-----operator <= ------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 <= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(3);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 <= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(7);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 <= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		myList3.push_back(5);
		std::cout << ((myList2 <= myList3) ? "true" : "false") << std::endl;
		std::cout << std::endl << "-----operator > -------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 > myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(3);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 > myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(7);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 > myList3) ? "true" : "false") << std::endl;
		std::cout << std::endl << "-----operator >= ------" << std::endl << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 >= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(3);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 >= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(7);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 >= myList3) ? "true" : "false") << std::endl;
		myList2.clear();
		myList3.clear();
		myList2.push_back(2);
		myList2.push_back(4);
		myList2.push_back(6);
		myList3.push_back(2);
		myList3.push_back(4);
		std::cout << ((myList2 >= myList3) ? "true" : "false") << std::endl;
		std::cout << std::endl << "-----swap non func-----" << std::endl << std::endl;
		ft::list<char> swapfirst (3,'A');
		ft::list<char> swapsecond (5,'B');
		ft::list<char>::iterator itch = swapfirst.begin();
		ft::list<char>::iterator itech = swapfirst.end();
		for (; itch != itech; itch++) {
			std::cout << *itch << " ";
		}
		std::cout << std::endl;
		itch = swapsecond.begin();
		itech = swapsecond.end();
		for (; itch != itech; itch++) {
			std::cout << *itch << " ";
		}
		std::cout << std::endl;
		std::cout << "after swap: " << std::endl;
		swap(swapfirst, swapsecond);
		itch = swapfirst.begin();
		itech = swapfirst.end();
		for (; itch != itech; itch++) {
			std::cout << *itch << " ";
		}
		std::cout << std::endl;
		itch = swapsecond.begin();
		itech = swapsecond.end();
		for (; itch != itech; itch++) {
			std::cout << *itch << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl << "--------splice man-------" << std::endl << std::endl;
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator its;
		for (int i=1; i<=4; ++i)
		   mylist1.push_back(i);

		for (int i=1; i<=3; ++i)
		   mylist2.push_back(i*10);

		its = mylist1.begin();
		++its;

		mylist1.splice (its, mylist2);
		mylist2.splice (mylist2.begin(),mylist1, its);
		its = mylist1.begin();
		std::advance(its,3);
		mylist1.splice ( mylist1.begin(), mylist1, its, mylist1.end());
		std::cout << "mylist1 contains:";
		for (its=mylist1.begin(); its!=mylist1.end(); ++its)
		  std::cout << ' ' << *its;
		std::cout << std::endl;
		std::cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << std::endl;
		std::cout << std::endl << "-------sort string------" << std::endl << std::endl;
		ft::list<std::string> listStr;
		listStr.push_back("ABC");
		listStr.push_back("ABA");
		listStr.push_back("ABB");
		listStr.push_back("CBC");
		listStr.push_back("BBC");
		listStr.sort();
		ft::list<std::string>::iterator itStr = listStr.begin();
		ft::list<std::string>::iterator iteStr = listStr.end();
		for (; itStr != iteStr; itStr++) {
			std::cout << *itStr << " ";
		}
		std::cout << std::endl;
	}
	
	//FIXME: --VECTOR
//	{
//		std::cout << std::endl << "----------resize---------" << std::endl << std::endl;
//		ft::vector<int> myVec(5, 1);
//		ft::vector<int>::iterator it = myVec.begin();
//		ft::vector<int>::iterator ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		myVec.resize(10);
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		const ft::vector<int> myVec2(5, 1);
//		ft::vector<int>::const_iterator itc = myVec2.begin();
//		ft::vector<int>::const_iterator itec = myVec2.end();
//		for (; itc != itec; itc++) {
//			std::cout << *itc << " ";
//		}
//		std::cout << std::endl;
//		std::cout << std::endl;
//		std::cout << "revers iterator: " << std::endl;
//		ft::vector<int>::reverse_iterator itr = myVec.rbegin();
//		ft::vector<int>::reverse_iterator iter = myVec.rend();
//		for (; itr != iter; itr++) {
//			std::cout << *itr << " ";
//		}
//		std::cout << std::endl;
//		it = myVec.begin();
//		it++;
//		ft::vector<int>::iterator test = myVec.insert(it, 7);
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << *test << " ";
//		std::cout << std::endl;
//		it = myVec.begin();
//		std::cout << *(it + 1) << " ";
//		std::cout << std::endl;
//		std::cout << std::endl << "-------operator= --------" << std::endl << std::endl;
//		ft::vector<int> myVec3(3, 1);
//		ft::vector<int> myVec4(6, 2);
//		std::cout << "befor first vec: " << std::endl;
//		it = myVec3.begin();
//		ite = myVec3.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "befor second vec: " << std::endl;
//		it = myVec4.begin();
//		ite = myVec4.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* first = second * " << std::endl;
//		myVec3 = myVec4;
//		std::cout << "after first vec: " << std::endl;
//		it = myVec3.begin();
//		ite = myVec3.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "after second vec: " << std::endl;
//		it = myVec4.begin();
//		ite = myVec4.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "capacity first vector: " << myVec3.capacity() << std::endl;
//		std::cout << "size first vector: " << myVec3.size() << std::endl;
//
//
//		ft::vector<int> myVec5(6, 5);
//		ft::vector<int> myVec6(2, 8);
//		std::cout << "befor first vec: " << std::endl;
//		it = myVec5.begin();
//		ite = myVec5.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "befor second vec: " << std::endl;
//		it = myVec6.begin();
//		ite = myVec6.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* first = second * " << std::endl;
//		myVec5 = myVec6;
//		std::cout << "after first vec: " << std::endl;
//		it = myVec5.begin();
//		ite = myVec5.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "after second vec: " << std::endl;
//		it = myVec6.begin();
//		ite = myVec6.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "capacity first vector: " << myVec5.capacity() << std::endl;
//		std::cout << "size first vector: " << myVec5.size() << std::endl;
//		std::cout << "* insert element at 3 position * " << std::endl;
//		it = (myVec5.begin() + 2);
//		myVec5.insert(it, 9);
//		myVec5.insert(it, 9);
//		myVec5.insert(it, 9);
//		myVec5.insert(it, 9);
//		myVec5.insert(it, 9);
//		it = myVec5.begin();
//		ite = myVec5.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "capacity first vector: " << myVec5.capacity() << std::endl;
//		std::cout << "size first vector: " << myVec5.size() << std::endl;
//		std::cout << std::endl << "---init with input iter---" << std::endl << std::endl;
//		it = myVec5.begin();
//		ite = myVec5.end();
//		ft::vector<int> myVec7(it, ite);
//		it = myVec7.begin();
//		ite = myVec7.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "capacity vector: " << myVec7.capacity() << std::endl;
//		std::cout << "size vector: " << myVec7.size() << std::endl;
//		std::cout << std::endl << "--insert with input iter--" << std::endl << std::endl;
//		std::cout << "* insert 4 element at 2 position * " << std::endl;
//		it = myVec4.begin();
//		ite = myVec4.end();
//		it++;
//		ite -= 1;
//		ft::vector<int>::iterator tmp = myVec7.begin();
//		tmp++;
//		myVec7.insert(tmp, it, ite);
//		it = myVec7.begin();
//		ite = myVec7.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "capacity vector: " << myVec7.capacity() << std::endl;
//		std::cout << "size vector: " << myVec7.size() << std::endl;
//		std::cout << std::endl << "----------max size--------" << std::endl << std::endl;
//		std::vector<float> stdFloat;
//		stdFloat.push_back(4.4);
//		stdFloat.push_back(4.4);
//		stdFloat.push_back(4.4);
//		stdFloat.push_back(4.4);
//		stdFloat.push_back(4.4);
//		ft::vector<float> myFloat;
//		myFloat.push_back(4.1);
//		myFloat.push_back(4.2);
//		myFloat.push_back(4.3);
//		myFloat.push_back(4.4);
//		myFloat.push_back(4.5);
//		std::cout << "capacity standart vector: " << stdFloat.capacity() << std::endl;
//		std::cout << "capacity my vector      : " << myFloat.capacity() << std::endl;
//		std::cout << "max size standart: " << stdFloat.max_size() << std::endl;
//		std::cout << "max size my      : " << myFloat.max_size() << std::endl;
//		myFloat.reserve(3);
//		std::cout << "reserve 3 capacity : " << myFloat.capacity() << std::endl;
//		myFloat.reserve(11);
//		std::cout << "reserve 11 capacity: " << myFloat.capacity() << std::endl;
//		std::cout << std::endl << "-------operator= --------" << std::endl << std::endl;
//		ft::vector<float>::iterator itf = myFloat.begin();
//		ft::vector<float>::iterator itef = myFloat.end();
//		std::cout << "container : " << std::endl;
//		itf = myFloat.begin();
//		itef = myFloat.end();
//		for (; itf != itef; itf++) {
//			std::cout << *itf << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "value [3] : " << " ";
//		std::cout << myFloat[3] << std::endl;
//		std::cout << std::endl << "------------at-----------" << std::endl << std::endl;
//		itf = myFloat.begin();
//		itef = myFloat.end();
//		std::cout << "container : " << std::endl;
//		itf = myFloat.begin();
//		itef = myFloat.end();
//		for (; itf != itef; itf++) {
//			std::cout << *itf << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "size vector: " << myFloat.size() << std::endl;
//		std::cout << "value [2] : " << " ";
//		std::cout << myFloat.at(2) << std::endl;
////		exeption!!!
////		std::cout << myFloat.at(20) << std::endl;
//		std::cout << std::endl << "-------front/back--------" << std::endl << std::endl;
//		const ft::vector<double> myDoub(2, 3);
//		std::cout << "const front in vector(2, 3): " << myDoub.front() << std::endl;
//		std::cout << "const back in vector(2, 3): " << myDoub.back() << std::endl;
//		myVec.clear();
//		myVec.push_back(1);
//		myVec.push_back(2);
//		myVec.push_back(3);
//		myVec.push_back(4);
//		std::cout << "vector: ";
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "front in vector: " << myVec.front() << std::endl;
//		std::cout << "back in vector: " << myVec.back() << std::endl;
//		std::cout << std::endl << "---------assign----------" << std::endl << std::endl;
//		ft::vector<int> first;
//		ft::vector<int> second;
//		ft::vector<int> third;
//		ft::vector<int> fourth(10, 200);
//
//		first.assign(7, 100);
//
//		it = first.begin() + 1;
//		second.assign(it, first.end() - 1);
//		fourth.assign(it, first.end() - 1);
//		int myints[] = {1776, 7, 4};
//		third.assign(myints, myints + 3);
//
//		std::cout << "Size of first: " << int (first.size()) << std::endl;
//		std::cout << "Capacity of first: " << int (first.capacity()) << std::endl;
//		std::cout << "Size of second: " << int (second.size()) << std::endl;
//		std::cout << "Capacity of second: " << int (second.capacity()) << std::endl;
//		std::cout << "Size of third: " << int (third.size()) << std::endl;
//		std::cout << "Capacity of third: " << int (third.capacity()) << std::endl;
//		std::cout << "Size of fourth: " << int (fourth.size()) << std::endl;
//		std::cout << "Capacity of fourth: " << int (fourth.capacity()) << std::endl;
//		std::cout << std::endl << "--------push/pop---------" << std::endl << std::endl;
//		std::cout << "* push 1...5 * " << std::endl;
//		ft::vector<int> popPushVec;
//		popPushVec.push_back(1);
//		popPushVec.push_back(2);
//		popPushVec.push_back(3);
//		popPushVec.push_back(4);
//		popPushVec.push_back(5);
//		it = popPushVec.begin();
//		ite = popPushVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "Size     : " << popPushVec.size() << std::endl;
//		std::cout << "Capacity : " << popPushVec.capacity() << std::endl;
//		std::cout << "* pop 3 times * " << std::endl;
//		popPushVec.pop_back();
//		popPushVec.pop_back();
//		popPushVec.pop_back();
//		it = popPushVec.begin();
//		ite = popPushVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "Size     : " << popPushVec.size() << std::endl;
//		std::cout << "Capacity : " << popPushVec.capacity() << std::endl;
//		std::cout << std::endl << "SANDART VECTOR" << std::endl;
//		std::cout << "* push 1...5 * " << std::endl;
//		std::vector<int> stdPushPop;
//		stdPushPop.push_back(1);
//		stdPushPop.push_back(2);
//		stdPushPop.push_back(3);
//		stdPushPop.push_back(4);
//		stdPushPop.push_back(5);
//		std::cout << "SSize     : " << stdPushPop.size() << std::endl;
//		std::cout << "SCapacity : " << stdPushPop.capacity() << std::endl;
//		stdPushPop.pop_back();
//		stdPushPop.pop_back();
//		stdPushPop.pop_back();
//		std::cout << "* pop 3 times * " << std::endl;
//		std::cout << "SSize     : " << stdPushPop.size() << std::endl;
//		std::cout << "SCapacity : " << stdPushPop.capacity() << std::endl;
//		std::cout << std::endl << "-------erase iter--------" << std::endl << std::endl;
//		myVec.clear();
//		std::cout << "vector befor: " << std::endl;
//		myVec.push_back(1);
//		myVec.push_back(2);
//		myVec.push_back(3);
//		myVec.push_back(4);
//		myVec.push_back(5);
//		myVec.push_back(6);
//		myVec.push_back(7);
//		myVec.push_back(8);
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "Size     : " << myVec.size() << std::endl;
//		std::cout << "Capacity : " << myVec.capacity() << std::endl;
//		std::cout << "erase [2..5): " << std::endl;
//		it = myVec.begin();
//		it++;
//		ite = it;
//		ite = ite + 3;
//		ft::vector<int>::iterator retIter = myVec.erase(it, ite);
//		std::cout << "vector after: " << std::endl;
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "Size     : " << myVec.size() << std::endl;
//		std::cout << "Capacity : " << myVec.capacity() << std::endl;
//		std::cout << "return iterator value: " << *retIter << std::endl;
//		std::cout << std::endl << "----------erase----------" << std::endl << std::endl;
//		std::cout << "vector befor: " << std::endl;
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* erase last element *" << std::endl;
//		ite = myVec.end();
//		ite--;
//		myVec.erase(ite);
//		std::cout << "vector after: " << std::endl;
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* erase first element *" << std::endl;
//		it = myVec.begin();
//		myVec.erase(it);
//		std::cout << "vector after: " << std::endl;
//		it = myVec.begin();
//		ite = myVec.end();
//		for (; it != ite; it++) {
//			std::cout << *it << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "Size     : " << myVec.size() << std::endl;
//		std::cout << "Capacity : " << myVec.capacity() << std::endl;
//		std::cout << std::endl << "----------swap-----------" << std::endl << std::endl;
//		ft::vector<char> firstStr(5, 'A');
//		ft::vector<char> secondStr(2, 'B');
//		std::cout << "vector first befor: " << std::endl;
//		ft::vector<char>::iterator itch = firstStr.begin();
//		ft::vector<char>::iterator itech = firstStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		ft::vector<char>::iterator tmpChar = firstStr.begin();
//		tmpChar += 4;
//		std::cout << "iterator value befor swap: " << *tmpChar << std::endl;
//		std::cout << "vector second befor: " << std::endl;
//		itch = secondStr.begin();
//		itech = secondStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* swap *" << std::endl;
//		firstStr.swap(secondStr);
//		std::cout << "iterator value after swap: " << *tmpChar << std::endl;
//		std::cout << "vector first after: " << std::endl;
//		itch = firstStr.begin();
//		itech = firstStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "vector second after: " << std::endl;
//		itch = secondStr.begin();
//		itech = secondStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "* swap *" << std::endl;
//		firstStr.swap(secondStr);
//		std::cout << "vector first after: " << std::endl;
//		itch = firstStr.begin();
//		itech = firstStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "vector second after: " << std::endl;
//		itch = secondStr.begin();
//		itech = secondStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << std::endl << "-----operator == ------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 == myVec4) ? "true" : "false") << std::endl;
//		myVec3.pop_back();
//		myVec3.push_back(5);
//		std::cout << ((myVec3 == myVec4) ? "true" : "false") << std::endl;
//		myVec3.pop_back();
//		myVec3.push_back(4);
//		myVec3.push_back(6);
//		std::cout << ((myVec3 == myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----operator != ------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 != myVec4) ? "true" : "false") << std::endl;
//		myVec3.pop_back();
//		myVec3.push_back(5);
//		std::cout << ((myVec3 != myVec4) ? "true" : "false") << std::endl;
//		myVec3.pop_back();
//		myVec3.push_back(4);
//		myVec3.push_back(6);
//		std::cout << ((myVec3 != myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----operator < -------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 < myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(3);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 < myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(7);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 < myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----operator <= ------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 <= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(3);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 <= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(7);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 <= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		myVec4.push_back(5);
//		std::cout << ((myVec3 <= myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----operator > -------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 > myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(3);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 > myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(7);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 > myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----operator >= ------" << std::endl << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 >= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(3);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 >= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(7);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 >= myVec4) ? "true" : "false") << std::endl;
//		myVec3.clear();
//		myVec4.clear();
//		myVec3.push_back(2);
//		myVec3.push_back(4);
//		myVec3.push_back(6);
//		myVec4.push_back(2);
//		myVec4.push_back(4);
//		std::cout << ((myVec3 >= myVec4) ? "true" : "false") << std::endl;
//		std::cout << std::endl << "-----swap non func-----" << std::endl << std::endl;
//		firstStr.clear();
//		firstStr.push_back('A');
//		firstStr.push_back('B');
//		firstStr.push_back('C');
//		secondStr.clear();
//		secondStr.push_back('F');
//		secondStr.push_back('G');
//		secondStr.push_back('H');
//		secondStr.push_back('J');
//		secondStr.push_back('K');
//		itch = firstStr.begin();
//		itech = firstStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		itch = secondStr.begin();
//		itech = secondStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "after swap: " << std::endl;
//		swap(firstStr, secondStr);
//		itch = firstStr.begin();
//		itech = firstStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//		itch = secondStr.begin();
//		itech = secondStr.end();
//		for (; itch != itech; itch++) {
//			std::cout << *itch << " ";
//		}
//		std::cout << std::endl;
//	}
	
	//FIXME: --QUEUE
//	{
//		ft::queue<float> myQueue;
//		std::cout << std::endl << "---------empty---------" << std::endl << std::endl;
//		std::cout << "* empty *" << std::endl;
//		std::cout << "Container is empty: " << (myQueue.empty() ? "true" : "false") << std::endl;
//		std::cout << "* not empty *" << std::endl;
//		myQueue.push(1.1);
//		std::cout << "Container is empty: " << (myQueue.empty() ? "true" : "false") << std::endl;
//		std::cout << std::endl << "---------size----------" << std::endl << std::endl;
//		std::cout << "* size: 1 *" << std::endl;
//		std::cout << "Container size: " << myQueue.size() << std::endl;
//		myQueue.push(2.2);
//		myQueue.push(3.3);
//		myQueue.push(4.4);
//		std::cout << "* size: 4 *" << std::endl;
//		std::cout << "Container size: " << myQueue.size() << std::endl;
//		std::cout << "* empty *" << std::endl;
//		myQueue.pop();
//		myQueue.pop();
//		myQueue.pop();
//		myQueue.pop();
//		std::cout << "Container size: " << myQueue.size() << std::endl;
//		std::cout << std::endl << "-------front/back------" << std::endl << std::endl;
//		myQueue.push(1.1);
//		myQueue.push(2.2);
//		myQueue.push(3.3);
//		myQueue.push(4.4);
//		std::cout << "front: " << myQueue.front() << std::endl;
//		std::cout << "back : " << myQueue.back() << std::endl;
//		std::cout << std::endl << "-----operator == ------" << std::endl << std::endl;
//		ft::queue<int> myQueue1;
//		ft::queue<int> myQueue2;
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4) == (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 == myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.push(5);
//		std::cout << "* (2, 4, 5) == (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 == myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.push(4);
//		myQueue1.push(6);
//		std::cout << "* (2, 4) == (2, 4, 6) *" << std::endl;
//		std::cout << ((myQueue1 == myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		std::cout << std::endl << "-----operator != ------" << std::endl << std::endl;
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4) != (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 != myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.push(2);
//		myQueue1.push(5);
//		std::cout << "* (2, 5) != (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 != myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue1.push(6);
//		std::cout << "* (2, 4, 6) != (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 != myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		std::cout << std::endl << "-----operator < -------" << std::endl << std::endl;
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4) < (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 < myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		myQueue2.push(5);
//		std::cout << "* (2, 4) < (2, 4, 5) *" << std::endl;
//		std::cout << ((myQueue1 < myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue1.push(5);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4, 5) < (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 < myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		std::cout << std::endl << "-----operator <= ------" << std::endl << std::endl;
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4) <= (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 <= myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.push(4);
//		std::cout << "* (2, 4, 4) <= (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 <= myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue1.pop();
//		myQueue2.pop();
//		myQueue2.pop();
//		std::cout << std::endl << "-----operator > -------" << std::endl << std::endl;
//		myQueue1.push(2);
//		myQueue1.push(4);
//		myQueue2.push(2);
//		myQueue2.push(4);
//		std::cout << "* (2, 4) > (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 > myQueue2) ? "true" : "false") << std::endl;
//		myQueue1.push(4);
//		std::cout << "* (2, 4, 4) > (2, 4) *" << std::endl;
//		std::cout << ((myQueue1 > myQueue2) ? "true" : "false") << std::endl;
//	}
//	FIXME: --STACK
//	{
//		ft::stack<double> myStack;
//		std::cout << std::endl << "---------empty---------" << std::endl << std::endl;
//		std::cout << "* empty *" << std::endl;
//		std::cout << "Container is empty: " << (myStack.empty() ? "true" : "false") << std::endl;
//		std::cout << "* not empty *" << std::endl;
//		myStack.push(1.1);
//		std::cout << "Container is empty: " << (myStack.empty() ? "true" : "false") << std::endl;
//		std::cout << std::endl << "---------size----------" << std::endl << std::endl;
//		std::cout << "* size: 1 *" << std::endl;
//		std::cout << "Container size: " << myStack.size() << std::endl;
//		myStack.push(2.2);
//		myStack.push(3.3);
//		myStack.push(4.4);
//		std::cout << "* size: 4 *" << std::endl;
//		std::cout << "Container size: " << myStack.size() << std::endl;
//		std::cout << "* empty *" << std::endl;
//		myStack.pop();
//		myStack.pop();
//		myStack.pop();
//		myStack.pop();
//		std::cout << "Container size: " << myStack.size() << std::endl;
//		std::cout << std::endl << "-----------top---------" << std::endl << std::endl;
//		myStack.push(1.1);
//		myStack.push(2.2);
//		myStack.push(3.3);
//		myStack.push(4.4);
//		std::cout << "top: " << myStack.top() << std::endl;
//		std::cout << std::endl << "-----operator == ------" << std::endl << std::endl;
//		ft::queue<int> myStack1;
//		ft::queue<int> myStack2;
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4) == (2, 4) *" << std::endl;
//		std::cout << ((myStack1 == myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.push(5);
//		std::cout << "* (2, 4, 5) == (2, 4) *" << std::endl;
//		std::cout << ((myStack1 == myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.push(4);
//		myStack1.push(6);
//		std::cout << "* (2, 4) == (2, 4, 6) *" << std::endl;
//		std::cout << ((myStack1 == myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		std::cout << std::endl << "-----operator != ------" << std::endl << std::endl;
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4) != (2, 4) *" << std::endl;
//		std::cout << ((myStack1 != myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.push(2);
//		myStack1.push(5);
//		std::cout << "* (2, 5) != (2, 4) *" << std::endl;
//		std::cout << ((myStack1 != myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack1.push(6);
//		std::cout << "* (2, 4, 6) != (2, 4) *" << std::endl;
//		std::cout << ((myStack1 != myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		std::cout << std::endl << "-----operator < -------" << std::endl << std::endl;
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4) < (2, 4) *" << std::endl;
//		std::cout << ((myStack1 < myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		myStack2.push(5);
//		std::cout << "* (2, 4) < (2, 4, 5) *" << std::endl;
//		std::cout << ((myStack1 < myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		myStack2.pop();
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack1.push(5);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4, 5) < (2, 4) *" << std::endl;
//		std::cout << ((myStack1 < myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		std::cout << std::endl << "-----operator <= ------" << std::endl << std::endl;
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4) <= (2, 4) *" << std::endl;
//		std::cout << ((myStack1 <= myStack2) ? "true" : "false") << std::endl;
//		myStack1.push(4);
//		std::cout << "* (2, 4, 4) <= (2, 4) *" << std::endl;
//		std::cout << ((myStack1 <= myStack2) ? "true" : "false") << std::endl;
//		myStack1.pop();
//		myStack1.pop();
//		myStack1.pop();
//		myStack2.pop();
//		myStack2.pop();
//		std::cout << std::endl << "-----operator > -------" << std::endl << std::endl;
//		myStack1.push(2);
//		myStack1.push(4);
//		myStack2.push(2);
//		myStack2.push(4);
//		std::cout << "* (2, 4) > (2, 4) *" << std::endl;
//		std::cout << ((myStack1 > myStack2) ? "true" : "false") << std::endl;
//		myStack1.push(4);
//		std::cout << "* (2, 4, 4) > (2, 4) *" << std::endl;
//		std::cout << ((myStack1 > myStack2) ? "true" : "false") << std::endl;
//
//
//	}
	//FIXME: --MAP
//	{
//		ft::map<int, int> myIntMap;
//		ft::map<int, int>::iterator it;
//		ft::map<int, int>::iterator ite;
//
//
//		std::cout << std::endl << "-----insert and iterators-------" << std::endl << std::endl;
//		std::cout << std::endl << "MY <INT, INT> MAP:" << std::endl;
//		for (int i = 1; i < 19; i++) {
//			myIntMap.insert(std::pair<int, int>(i, i));
//		}
//		it = myIntMap.begin();
//		ite = myIntMap.end();
//		std::cout << std::endl << "* iterator++ *" << std::endl << std::endl;
//		for (; it != ite; ++it) {
//			std::cout << (it.getData()->color == false ? "red     :" : "black   :") << it->first << " => " << it->second << std::endl;
//		}
//		std::cout << std::endl << "* backtracking (iterator--) *" << std::endl << std::endl;
//		ite = myIntMap.end();
//		--ite;
//		it = myIntMap.begin();
//		for (; ite != it; --ite) {
//			std::cout << (ite.getData()->color == false ? "red     :" : "black   :") << ite->first << " => " << ite->second << std::endl;
//		}
//		std::cout << (ite.getData()->color == false ? "red     :" : "black   :") << ite->first << " => " << ite->second << std::endl;
//
//		std::cout << std::endl << "--------revers iterator---------" << std::endl << std::endl;
//		ft::map<int, int>::reverse_iterator itr = myIntMap.rbegin();
//		ft::map<int, int>::reverse_iterator iter = myIntMap.rend();
//		for (; itr != iter; ++itr) {
//			std::cout << (itr.getData()->color == false ? "red     :" : "black   :") << itr->first << " => " << itr->second << std::endl;
//		}
//		std::cout << std::endl;
//		std::cout << "* backtracking (revers iterator--) *" << std::endl;
//		itr = myIntMap.rbegin();
//		iter = myIntMap.rend();
//		--iter;
//		for (; itr != iter; --iter) {
//			std::cout << (iter.getData()->color == false ? "red     :" : "black   :") << iter->first << " => " << iter->second << std::endl;
//		}
//		std::cout << (iter.getData()->color == false ? "red     :" : "black   :") << iter->first << " => " << iter->second << std::endl;
//		std::cout << std::endl;
//
//		std::cout << std::endl << "-----------assign----------" << std::endl << std::endl;
//		std::cout << "* after assign *" << std::endl;
//		ft::map<int, int> copyIntMap;
//		copyIntMap = myIntMap;
//		it = copyIntMap.begin();
//		ite = copyIntMap.end();
//		for (; it != ite; ++it) {
//			std::cout << (it.getData()->color == false ? "red     :" : "black   :") << it->first << " => " << it->second << std::endl;
//		}
//		std::cout << std::endl;
//		std::cout << std::endl << "-----------copy------------" << std::endl << std::endl;
//		ft::map<int, int> copyIntMap2(myIntMap);
//		it = copyIntMap2.begin();
//		ite = copyIntMap2.end();
//		for (; it != ite; ++it) {
//			std::cout << (it.getData()->color == false ? "red     :" : "black   :") << it->first << " => " << it->second << std::endl;
//		}
//		std::cout << std::endl;
//
//		std::cout << std::endl << "----empty/size/clear------" << std::endl << std::endl;
//		std::cout << "size: " << copyIntMap2.size() << std::endl;
//		std::cout << "is empty: " << (copyIntMap2.empty() ? "true" : "false") << std::endl;
//		std::cout << std::endl << "* clear map *" << std::endl;
//		copyIntMap2.clear();
//		std::cout << "size: " << copyIntMap2.size() << std::endl;
//		std::cout << "is empty: " << (copyIntMap2.empty() ? "true" : "false") << std::endl;
//
//		std::cout << std::endl << "---------operator[]--------" << std::endl;
//		ft::map<char, float> myCharFloat;
//		myCharFloat['a'] = 1.1;
//		myCharFloat['b'] = 2.2;
//		myCharFloat['c'] = 3.3;
//		std::cout << std::endl << "* add 'a' = 1.1 *" << std::endl;
//		std::cout << "* add 'b' = 2.2 *" << std::endl;
//		std::cout << "* add 'c' = 3.4 *" << std::endl;
//		ft::map<char, float>::iterator itcf = myCharFloat.begin();
//		ft::map<char, float>::iterator itecf = myCharFloat.end();
//		for (; itcf != itecf; ++itcf) {
//			std::cout << itcf->first << " => " << itcf->second << std::endl;
//		}
//
//		std::cout << std::endl << "----------erase-----------" << std::endl << std::endl;
//		myIntMap.erase(6);
//		myIntMap.erase(7);
//		myIntMap.erase(8);
//		myIntMap.erase(10);
//		myIntMap.erase(18);
//		myIntMap.erase(3);
//		myIntMap.erase(4);
//		std::cout << std::endl << "* erase 6, 7, 8, 10, 18, 3, 4 *" << std::endl;
//		it = myIntMap.begin();
//		ite = myIntMap.end();
//		for (; it != ite; ++it) {
//			std::cout << it->first << " => " << it->second << std::endl;
//		}
//		std::cout << std::endl;
//		std::cout << std::endl << "-----------swap-----------" << std::endl << std::endl;
//		ft::map<char, double> s1, s2;
//		s1.insert(std::pair<char, double>('a', 1.1));
//		s1.insert(std::pair<char, double>('b', 1.2));
//		s1.insert(std::pair<char, double>('c', 1.3));
//		s2.insert(std::pair<char, double>('z', 2.1));
//		s2.insert(std::pair<char, double>('x', 2.2));
//		ft::map<char, double>::iterator itcd = s1.begin();
//		ft::map<char, double>::iterator itecd = s1.end();
//		std::cout << std::endl << "* befor map 1 *" << std::endl;
//		for (; itcd != itecd; ++itcd) {
//			std::cout << itcd->first << " => " << itcd->second << std::endl;
//		}
//		itcd = s2.begin();
//		itecd = s2.end();
//		std::cout << std::endl << "* befor map 2 *" << std::endl;
//		for (; itcd != itecd; ++itcd) {
//			std::cout << itcd->first << " => " << itcd->second << std::endl;
//		}
//		s1.swap(s2);
//		itcd = s1.begin();
//		itecd = s1.end();
//		std::cout << std::endl << "* after map 1 *" << std::endl;
//		for (; itcd != itecd; ++itcd) {
//			std::cout << itcd->first << " => " << itcd->second << std::endl;
//		}
//		itcd = s2.begin();
//		itecd = s2.end();
//		std::cout << std::endl << "* after map 2 *" << std::endl;
//		for (; itcd != itecd; ++itcd) {
//			std::cout << itcd->first << " => " << itcd->second << std::endl;
//		}
//
//		std::cout << std::endl << "--------find/count---------" << std::endl << std::endl;
//		std::cout << "* map *" << std::endl;
//		it = myIntMap.begin();
//		ite = myIntMap.end();
//		for (; it != ite; ++it) {
//			std::cout << it->first << " => " << it->second << std::endl;
//		}
//		std::cout << std::endl;
//		it = myIntMap.find(9);
//		std::cout << "find 9: " << std::endl;
//		if (it == myIntMap.end())
//			std::cout << "not FOUND" << std::endl;
//		else
//			std::cout << it->first << " => " << it->second << std::endl;
//		std::cout << "count: " << myIntMap.count(9) << std::endl;
//		std::cout << std::endl;
//		it = myIntMap.find(22);
//		std::cout << "find 22: " << std::endl;
//		if (it == myIntMap.end())
//			std::cout << "not FOUND" << std::endl;
//		else
//			std::cout << it->first << " => " << it->second << std::endl;
//		std::cout << "count: " << myIntMap.count(22) << std::endl;
//
//		std::cout << std::endl << "--------lower_bound--------" << std::endl << std::endl;
//
//		myIntMap.clear();
//		std::cout << "* map *" << std::endl;
//		myIntMap.insert(std::pair<int, int>(10, 10));
//		myIntMap.insert(std::pair<int, int>(20, 20));
//		myIntMap.insert(std::pair<int, int>(30, 30));
//		myIntMap.insert(std::pair<int, int>(40, 40));
//		myIntMap.insert(std::pair<int, int>(50, 50));
//		it = myIntMap.begin();
//		ite = myIntMap.end();
//		for (; it != ite; ++it) {
//			std::cout << it->first << " => " << it->second << std::endl;
//		}
//		it = myIntMap.lower_bound(25);
//		std::cout << "(25) my map  : " << it->first << " => " << it->second << std::endl;
//		std::map<int, int> stdIntMap;
//		stdIntMap.insert(std::pair<int, int>(10, 10));
//		stdIntMap.insert(std::pair<int, int>(20, 20));
//		stdIntMap.insert(std::pair<int, int>(30, 30));
//		stdIntMap.insert(std::pair<int, int>(40, 40));
//		stdIntMap.insert(std::pair<int, int>(50, 50));
//		std::map<int,int>::iterator its = stdIntMap.lower_bound(25);
//		std::cout << "(25) standart: " << its->first << " => " << its->second << std::endl;
//		it = myIntMap.lower_bound(20);
//		std::cout << "(20) my map  : " << it->first << " => " << it->second << std::endl;
//		its = stdIntMap.lower_bound(20);
//		std::cout << "(20) standart: " << its->first << " => " << its->second << std::endl;
//		std::cout << std::endl << "--------upper_bound--------" << std::endl << std::endl;
//		it = myIntMap.upper_bound(45);
//		std::cout << "(45) my map  : " << it->first << " => " << it->second << std::endl;
//		its = stdIntMap.upper_bound(45);
//		std::cout << "(45) standart: " << its->first << " => " << its->second << std::endl;
//		it = myIntMap.upper_bound(30);
//		std::cout << "(30) my map  : " << it->first << " => " << it->second << std::endl;
//		its = stdIntMap.upper_bound(30);
//		std::cout << "(30) standart: " << its->first << " => " << its->second << std::endl;
//		std::cout << std::endl << "--------equal_range--------" << std::endl << std::endl;
//
//		std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ret;
//		ret = myIntMap.equal_range(30);
//		std::cout << "(30) lower bound points to: ";
//		std::cout << ret.first->first << " => " << ret.first->second << '\n';
//		std::cout << "(30) upper bound points to: ";
//		std::cout << ret.second->first << " => " << ret.second->second << '\n';
//	}
//	while (1);

	return 0;
}
