#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void) {
	std::list<int> list1;
	std::vector<int> list2;

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(14);
	list1.push_back(4);

	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(14);
	list2.push_back(4);
	try {
		easyfind(list1, 140);
		std::cout << "find\n";
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(list2, 4);
		std::cout << "find\n";
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}