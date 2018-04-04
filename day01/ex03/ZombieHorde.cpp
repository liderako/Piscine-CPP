#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( void ) {
	this->count = 0;
}

ZombieHorde::ZombieHorde( size_t size ) {

	try {
		this->z = new Zombie[size];
		while ( this->count < size ) {
			this->z[this->count].setName( randomChump() );
			this->z[this->count].setType( "default" );
			this->count += 1;
		}
	}
	catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		std::exit(-1);
	}
	this->count = 0;
}

ZombieHorde::~ZombieHorde( void ) {
	delete [] z;
}

std::string		ZombieHorde::randomChump( void ) {
	std::string 	base[6];

	base[0] = "Anton";
	base[1] = "Sasha";
	base[2] = "Toni";
	base[3] = "Snow";
	base[4] = "liderako";
	base[5] = "github";
	return ( base[this->count % 6] );
}

void		ZombieHorde::announce() {
	for (size_t i = 0; i < this->count; i++) {
		this->z[i].announce();
	}
}
