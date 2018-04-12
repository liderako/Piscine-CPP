#include <iostream>
#include "span.hpp"

int main() {
	Span s(10);
	srand(time(NULL));

	for (size_t i = 0; i < s.getSize() + 10; ++i) {
		try {
			s.addNumber(rand() % 15);
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	for (size_t i = 0; i < s.getSize(); ++i) {
		std::cout << s.getNumber(i) << std::endl;
	}
	std::cout << "END firsts test\n";
	// s.shortestSpan();
	std::cout << "longestSpan " << s.longestSpan() << std::endl;
	std::cout << "shortesSpan " << s.shortestSpan() << std::endl;
}