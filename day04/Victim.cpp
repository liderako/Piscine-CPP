#include "Victim.hpp"

Victim::Victim( void ) {
	this->name = "default name";
	std::cout << "Some random victim called " << this.getName() << " just popped\n";
}

Victim::Victim( Victim const & Victim) {
	*this = Victim;
	std::cout << "Some random victim called " << this.getName() << " just popped\n";
}

Victim::Victim( std::string name ) {
	this->name = name;
	std::cout << "Some random victim called " << this.getName() << " just popped\n";
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this.getName() << " just died for no apparent reason !\n";
	return ;
}

Victim & Victim::operator=( Victim const & Victim ) {
	this->name = Victim.getName();
	return *this;
}

std::string 	Victim::getName( void ) const {
	return (this->name);
}

void	Victim::setName( std::string const s ) {
	this->name = name;
}

std::ostream & operator<<(std::ostream & o, Victim const & b) {
	return (o << "I'm ", this->getName() << " and I like otters !\n";);
}

void 	Victim::getPolymorphed() const {
	std::cout << this->getName() << " has been turned into a cute little sheep !\n";
}