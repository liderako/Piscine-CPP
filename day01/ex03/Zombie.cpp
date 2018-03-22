#include "Zombie.hpp"

Zombie::Zombie( void ) {
	this->name = "default";
	this->type = "default";	
}

Zombie::~Zombie( void ) {
	return ;
}

Zombie::Zombie( std::string name, std::string type ) {
	this->name = name;
	this->type = type;
}

Zombie::Zombie( Zombie const & zombie ) {
	*this=zombie;
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

void	Zombie::setType( std::string type ) {
	this->type = type;
}

std::string		Zombie::getName( void ) const {
	return ( this->name );
}

std::string		Zombie::getType( void ) const {
	return ( this->type );
}

void			Zombie::announce( void ) {
	std::cout << "<" << this->name << " (" << this->type << ")" << "> " << "Braiiiiiiinnnssss...\n";
}

Zombie &		Zombie::operator=(Zombie const & z) {
	this->name = z.getName();
	this->type = z.getType();
	return *this;
}	
