#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main() {
	PlasmaRifle rifle;
	PowerFist 	fist;
	
	std::cout << "test weapon \n";

	rifle.attack();
	fist.attack();
	std::cout << "end test weapon\n";
}