#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int 	main() {
	Zombie z("Anton", "default");
	z.announce();

	ZombieEvent factory;	
	factory.setZombieType("alone");

	Zombie *tmp = factory.newZombie("clone");
	tmp->announce();
	factory.setZombieType("fromFactory");
	Zombie *random[9];
	for (int i = 0; i < 9; ++i) {
		random[i] = factory.randomChump();
	}
	for (int i = 0; i < 9; ++i) {
		delete (random[i]);
	}
		delete tmp;
}
