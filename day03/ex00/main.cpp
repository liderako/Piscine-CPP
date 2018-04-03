#include "FragTrap.hpp"

int main(){
	FragTrap f("asvirido");

	f.meleeAttack("liderako");
	f.rangedAttack("tower");

	std::cout << "Hp " << f.getHitPoints() << '\n';
	f.takeDamage(50);
	std::cout << "HP " << f.getHitPoints() << '\n';
	f.beRepaired(40);
	std::cout << "Hp " << f.getHitPoints() << '\n';
	std::cout << "Energy " << f.getEnergyPoints() << '\n';
	for (int i = 0; i < 5; ++i){
		f.vaulthunter_dot_exe("liderako");
	}
}