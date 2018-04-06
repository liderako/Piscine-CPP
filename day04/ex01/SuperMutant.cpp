#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !\n";
	return ;
}

SuperMutant::SuperMutant( SuperMutant const & SuperMutant) {
	std::cout << "Aaargh ...\n";
	*this = SuperMutant;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ...\n";
	return ;
}

SuperMutant & SuperMutant::operator=( SuperMutant const & superMutant ) {
	this->type = superMutant.getType();
	this->hp = superMutant.getHP();
	return *this;
}

void 	SuperMutant::takeDamage(int damage) {
	return (Enemy::takeDamage(damage - 3));
}