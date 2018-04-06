#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ) {
	this->name = "default name";
	this->title = "defalut title";
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !\n";
}

Sorcerer::Sorcerer( Sorcerer const & Sorcerer) {
	*this = Sorcerer;
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !\n";
}

Sorcerer::Sorcerer( std::string name, std::string title ) {
	this->name = name;
	this->title = title;
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !\n";
}

Sorcerer::~Sorcerer( void ) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !\n";
	return ;
}

Sorcerer & Sorcerer::operator=( Sorcerer const & Sorcerer ) {
	this->name = Sorcerer.getName();
	this->title = Sorcerer.getTitle();
	return *this;
}

std::string 	Sorcerer::getName( void ) const {
	return (this->name);
}

std::string 	Sorcerer::getTitle( void ) const {
	return (this->title);
}

void	Sorcerer::setTitle( std::string const s ) {
	this->title = title;
}

void	Sorcerer::setName( std::string const s ) {
	this->name = name;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & b) {
	return (o << "I am ", this->getName() << ", " << this->getTitle() << ", and I like ponies !\n";);
}

// action

void 	Sorcerer::polymorph(Victim const &s) const {
	s.getPolymorphed();
}