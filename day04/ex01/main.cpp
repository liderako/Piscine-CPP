#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

int main() {
	PlasmaRifle rifle;
	PowerFist 	fist;
	
	std::cout << "test weapon \n";
	std::cout << "name "<<rifle.getName() << "\n";
	std::cout << "apCost "<<rifle.getAPCost() << "\n";
	std::cout << "damage " << rifle.getDamage() << "\n";
	rifle.attack();
	
	std::cout << "name "<<fist.getName() << "\n";
	std::cout << "apCost "<<fist.getAPCost() << "\n";
	std::cout << "damage " << fist.getDamage() << "\n";
	fist.attack();
	std::cout << "end test weapon\n";

	std::cout << "test enemy\n";
	SuperMutant superMutant;
	RadScorpion radScorpion;

	std::cout << "type "<< superMutant.getType() << "\n";
	std::cout << "hp " << superMutant.getHP() << "\n";
	superMutant.takeDamage(10);
	std::cout << "hp " << superMutant.getHP() << "\n";
	
	std::cout << "type "<< radScorpion.getType() << "\n";
	std::cout << "hp "<< radScorpion.getHP() << "\n";
	radScorpion.takeDamage(10);
	std::cout << "hp "<< radScorpion.getHP() << "\n";
	std::cout << "end test enemy\n";
}