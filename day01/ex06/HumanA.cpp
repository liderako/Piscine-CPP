#include "HumanA.hpp"

HumanA::~HumanA( void ) {
	return ;
}

HumanA::HumanA( std::string name, Weapon &weapon ) : weapon(weapon){
	this->name = name;
}


void 		HumanA::attack( void ) {
	std::cout << this->name << " attacks with his " << this->weapon.getType() << "\n";
}
