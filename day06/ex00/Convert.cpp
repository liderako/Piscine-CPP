#include "Convert.hpp"
#include <iomanip>

Convert::Convert() {

}

Convert::~Convert() {

}

void 	Convert::run(std::string s) {
	printChar(s);
	printInt(s);
	printFloat(s);
	printDouble(s);
}

void 	Convert::printChar(std::string s) {
	try {
		this->a = static_cast<char>(std::stoi(s));
		if ((this->a >= 32) && (this->a <= 126)) {
			std::cout << "char: '" << this->a <<"'" << std::endl;
		}
		else { 
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	catch(std::exception &e) {
		std::cout << "char: impossible\n";
	}
}


void 	Convert::printInt(std::string s) {
	try {
		this->b = static_cast<int>(std::stoi(s));
		std::cout << "int: " << this->b<< std::endl;
	}
	catch(std::exception &e) {
		std::cout << "int: impossible\n";
	}
}

void 	Convert::printDouble(std::string s) {
	try {
		int len = getLenDecimals(s);
		this->d = static_cast<double>(std::stod(s));
		std::cout << "double: " << std::fixed << std::setprecision(len) << this->d << "\n";
	}
	catch(std::exception &e) {
		std::cout << "double: nan\n";
	}
}

void 	Convert::printFloat(std::string s) {
	try {
		int len = getLenDecimals(s);
		this->c = static_cast<float>(std::stof(s));
		std::cout << "float: " << std::fixed << std::setprecision(len) << this->c << "f\n";
	}
	catch(std::exception &e) {
		std::cout << "float: nanf\n";
	}
}

int 	Convert::getLenDecimals(std::string s) {
	size_t 	len;

	len = 1;
	for (size_t i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			len = 0;
			for (size_t j = i + 1; j < s.length(); j++) {
				if (s[j] >= '0' && s[j] <= '9')
					len++;
				else
					break;
			}
			break ;
		}
	}
	return (static_cast<int>(len));
}