#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> a(13);
	Array<int> b;

	std::cout << a.size() << std::endl;
	a[5] = 13;
	std::cout << a[5] << std::endl;
	try {
		std::cout << a[1414];
	}
	catch(std::exception &e) {
		std::cout << e.what();
	}
	
	for (int i = 0; i < 13; i++) {
		a[i] = i;
		std::cout << a[i] << " ";
	}
	std::cout << '\n';
	b = a;
	for (int i = 0; i < 13; i++) {
		std::cout << b[i] << " ";
	}
}