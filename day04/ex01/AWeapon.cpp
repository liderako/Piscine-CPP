#include "AWeapon.hpp"

AWeapon::AWeapon( void ){
	this->damage = 0;
	this->apCost = 0;
	this->name = "default Aweapon";
}

AWeapon::AWeapon( AWeapon const & aWeapon) {
	*this = aWeapon;
}

AWeapon::AWeapon(std::string const & name, int apCost, int damage)  {
	this->damage = damage;
	this->apCost = apCost;
	this->name = name;
}

AWeapon::~AWeapon( void ) {
	return ;
}

AWeapon & AWeapon::operator=( AWeapon const & aWeapon ) {
	this->name = aWeapon.getName();
	this->damage = aWeapon.getDamage();
	this->apCost = aWeapon.getAPCost();
	return *this;
}

std::string	AWeapon::getName() const {
	return (this->name);
}

int 		AWeapon::getAPCost() const {
	return (this->apCost);
}

int 		AWeapon::getDamage() const {
	return (this->damage);
}
