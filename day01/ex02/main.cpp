#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int 	main() {
	Zombie z("Anton", "default");
	z.announce();

	ZombieEvent factory;	
	factory.setZombieType("fromFactory");

	Zombie *tmp = factory.newZombie("clone");
	tmp->announce();
	delete tmp;
	
	int i = 0;
	while (i < 10 )
	{
		tmp = factory.randomChump();
		tmp->announce();
		delete tmp;
		i++;
	}
}
