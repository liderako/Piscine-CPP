#include "Pony.hpp"

Pony::Pony( void ) {
	this->name = "I don't know my name";
	this->phrase = "Sorry";
	return ;
}

Pony::~Pony( void ) {
	return ;
}

Pony::Pony( std::string name, std::string phrase ) {
	this->name = name;
	this->phrase = phrase;
}

void	Pony::setName( std::string name) {
	this->name = name;
}

void	Pony::setPhrase( std::string phrase ) {
	this->phrase = phrase;
}

std::string		Pony::getName( void ) {
	return ( this->name );
}

std::string		Pony::getPhrase( void ) {
	return ( this->phrase );
}

void			Pony::say ( void ) {
	std::cout << this->phrase << " "  << this->name << "\n"; 
}

void			Pony::ponyOnTheHeap( void ) {
	say();
}

void			Pony::ponyOnTheStack( void ) {
	say();
}

