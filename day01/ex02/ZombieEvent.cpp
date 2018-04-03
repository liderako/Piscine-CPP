#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) {
	this->type = "default";
	this->count = 1;
}

ZombieEvent::~ZombieEvent( void ) {
	return ;
}

void		ZombieEvent::setZombieType( std::string type ) {
	this->type = type;
}

Zombie		*ZombieEvent::newZombie( std::string name ) {
	Zombie *z = new Zombie( name, this->type);
	return (z);
}

Zombie		*ZombieEvent::randomChump( void ) {
	std::string 	base[6];

	base[0] = "Anton";
	base[1] = "Sasha";
	base[2] = "Toni";
	base[3] = "Snow";
	base[4] = "liderako";
	base[5] = "github";
	Zombie *z = ZombieEvent::newZombie( base[this->count % 6] );
	this->count++;
	z->announce();
	return (z);
}
