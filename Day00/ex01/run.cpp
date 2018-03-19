#include <iostream>
#include "Contact.class.hpp"

std::string		getText() {
	std::string 	input;

	if (std::getline( std::cin, input )) {
		return input;
	}
	std::cout << "Error read input\n";
	std::exit(-1);
}

int 	chooseCommand(std::string command) {
	if (command == "EXIT") {
		return (-1);
	}
	else if (command == "ADD" ) {
		std::cout << "some code\n";
	}
	else if (command == "SEARCH" ) {
		std::cout << "some code\n";
	}
	else {
		std::cout << "Unknown сommand, ";
		std::cout << "choose command [ADD] OR [SEARCH] OR [EXIT]\n";
	}
	return (1);
}

int main( void ) {
	std::string command;
	int 		res;

	while ( 1 ) {
		command = getText();
		res = chooseCommand(command);
		if (res == -1) {
			return (1);
		}
	}
}
