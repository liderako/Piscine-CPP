#include "HumanB.hpp"

HumanB::HumanB( void ) {
	this->name = "null";
	this->weapon = new Weapon();
}

HumanB::~HumanB( void ) {
	return ;
}

HumanB::HumanB( std::string name ) {
	this->name = name;
	this->weapon = new Weapon();
}

void	HumanB::setWeapon( Weapon & weapon) {
	// delete this->weapon;
	this->weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::cout << this->name << " attacks with his " << this->weapon->getType() << "\n";
}
