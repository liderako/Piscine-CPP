#include <iostream>

int main() {
	std::string text = "HI THIS IS BRAIN";
	std::string &ref = text;
	std::string *point;
	
	point = &text;
	std::cout << text << "\n";
	std::cout << *point << "\n";
	std::cout << ref << "\n";
}
