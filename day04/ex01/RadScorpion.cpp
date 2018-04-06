#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *\n";
	return ;
}

RadScorpion::RadScorpion( RadScorpion const & RadScorpion) {
	std::cout << "* click click click *\n";
	*this = RadScorpion;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "* SPROTCH *\n";
	return ;
}

RadScorpion & RadScorpion::operator=( RadScorpion const & radScorpion ) {
	this->type = radScorpion.getType();
	this->hp = radScorpion.getHP();
	return *this;
}
