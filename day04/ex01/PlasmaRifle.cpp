#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21) {
	return ;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & PlasmaRifle) {
	*this = PlasmaRifle;
}

PlasmaRifle::~PlasmaRifle( void ) {
	return ;
}

PlasmaRifle & PlasmaRifle::operator=( PlasmaRifle const & PlasmaRifle ) {
	this->name = PlasmaRifle.getName();
	this->damage = PlasmaRifle.getDamage();
	this->apCost = PlasmaRifle.getAPCost();
	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *\n";
}
