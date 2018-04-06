#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50) {
	return ;
}

PowerFist::PowerFist( PowerFist const & PowerFist) {
	*this = PowerFist;
}

PowerFist::~PowerFist( void ) {
	return ;
}

PowerFist & PowerFist::operator=( PowerFist const & PowerFist ) {
	this->name = PowerFist.getName();
	this->damage = PowerFist.getDamage();
	this->apCost = PowerFist.getAPCost();
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *\n";
}
