#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv) {
	Convert convert;
	if (argc != 2) {
		std::cout << "Too many arguments" << std::endl;
		std::cout << "Usage ./convert 0" << std::endl;
		return (0);
	}
	else if (argc == 1) {
		std::cout << "Too many agrc" << std::endl;
		std::cout << "Usage ./convert 0" << std::endl;
		return (0);
	}
	convert.run(argv[1]);
}
