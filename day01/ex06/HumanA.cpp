#include "HumanA.hpp"

HumanA::HumanA( void ) {
	this->name = "null";
}
HumanA::~HumanA( void ) {
	return ;
}

HumanA::HumanA( std::string name, Weapon &weapon ) {
	this->name = name;
	this->weapon = &weapon;
}


void 		HumanA::attack( void ) {
	std::cout << this->name << " attacks with his " << this->weapon->getType() << "\n";
}
