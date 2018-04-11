#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	if (rand() % 13 == 2) {
		return (new A());
	}
	else if (rand() % 2 != 0) {
		return (new B());	
	}
	return new C;
}

void 	identify_from_pointer( Base * p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "identify_from_pointer A\n";
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "identify_from_pointer B\n";
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "identify_from_pointer C\n";
	}
}

void identify_from_reference( Base & p ) {
	if (dynamic_cast<A*>(&p) != NULL) {
		std::cout << "identify_from_reference A\n";
	}
	else if (dynamic_cast<B*>(&p) != NULL) {
		std::cout << "identify_from_reference B\n";
	}
	else if (dynamic_cast<C*>(&p) != NULL) {
		std::cout << "identify_from_reference C\n";
	}
}

int main(void) {
	std::srand(std::time(NULL));
	for (int i = 0; i < 150; i++) {
		Base *a = generate();
		identify_from_pointer(a);
		identify_from_reference(*a);
		delete a;
	}
}