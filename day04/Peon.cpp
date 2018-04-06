#include "Peon.hpp"

Peon::Peon( void ){
	std::cout << "Zog zog.\n";
}

Peon::Peon( Peon const & Peon) {
	*this = Peon;
	std::cout << "Zog zog.\n";
}

Peon::Peon( std::string name ) : Victim(name) {
	std::cout << "Zog zog.\n";
}

Peon::~Peon( void ) {
	std::cout << "Bleuark...\n";
}

Peon & Peon::operator=( Peon const & Peon ) {
	this->setName(Peon.getName());
	return *this;
}

std::ostream & operator<<(std::ostream & o, Peon const & b) {
	return (o << "I'm " <<  b.getName() << " and I like otters !\n");
}

// void 	Victim::getPolymorphed(void) const {
	// std::cout << this->getName() << " has been turned into a pink pony !\n";
// }

void 	Peon::getPolymorphed() const {
	std::cout << this->getName() << " has been turned into a pink pony !\n";
}