#include <iostream>
#include "Bureaucrat.hpp"

int 	main(void) {
	Bureaucrat b("hightException", 149);
	Bureaucrat a("lowException", 1);
	Bureaucrat a1("normalDown", 1);
	Bureaucrat a2("normalUp", 15);

	std::cout << b;
	b-= 10;
	std::cout << b;

	std::cout << a;
	a+= 10;
	std::cout << a;

	std::cout << a1;
	a1-= 10;
	std::cout << a1;

	std::cout << a2;
	a2+= 10;
	std::cout << a2;
}