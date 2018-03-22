#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( void ) {
	this->count = 0;
}

ZombieHorde::ZombieHorde( size_t size ) {
	this->count = 0;
	while ( this->count < size ) {
//		this->z[this->count] = randomChump();
		this->count++;	
	}
}

ZombieHorde::~ZombieHorde( void ) {
	return ;
}

Zombie		*ZombieHorde::newZombie( std::string name ) {
	Zombie *z = new Zombie( name, "default");
	return (z);
}

Zombie		*ZombieHorde::randomChump( void ) {
	std::string 	base[6];

	base[0] = "Anton";
	base[1] = "Sasha";
	base[2] = "Toni";
	base[3] = "Snow";
	base[4] = "liderako";
	base[5] = "github";
	Zombie *z = ZombieHorde::newZombie( base[this->count % 6] );
	return (z);
}

void		ZombieHorde::announce() {
	for (int i = 0; i < this->count; i++) {
		this->z[i].announce();
	}
}
