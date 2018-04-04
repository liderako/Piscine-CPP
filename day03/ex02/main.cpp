#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	ScavTrap d("asvirido");

	d.meleeAttack("liderako");
	d.rangedAttack("tower");

	std::cout << "Hp " << d.getHitPoints() << '\n';
	d.takeDamage(50);
	std::cout << "HP " << d.getHitPoints() << '\n';
	d.beRepaired(40);
	std::cout << "Hp " << d.getHitPoints() << '\n';
	std::cout << "Energy " << d.getEnergyPoints() << '\n';
	for (int i = 0; i < 5; ++i){
		d.challengeNewcomer();
	}
}