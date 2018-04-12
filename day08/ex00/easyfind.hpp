#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>

// template<typename T>
// int 	easyfind(T t, int x) {
// 	size_t len = t.size();
// 	typename T::iterator it = std::find(t.begin(), t.end(), x);
// 	for (int i = 0; i < len; i++) {
// 		typename T::iterator it = t.begin();
// 		std::advance(it, i);
// 		if (*it == x) {
// 			return (i);
// 		}
// 	}
// 	return (-1);
// }

template<typename T>
typename T::iterator easyfind(T t, int x) {
	typename T::iterator it = std::find(t.begin(), t.end(), x);
	if (it == t.end()) {
		throw std::logic_error("No found");
	}
	return (it);
}

#endif