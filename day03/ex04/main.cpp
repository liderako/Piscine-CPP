#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"

int main(){
	FragTrap f("Lolal");

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

	ScavTrap d("Nikita");

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

	NinjaTrap x("asvirido Ninja");

	x.meleeAttack("liderako");
	x.rangedAttack("tower");

	std::cout << "Hp " << x.getHitPoints() << '\n';
	x.takeDamage(50);
	std::cout << "HP " << x.getHitPoints() << '\n';
	x.beRepaired(40);
	std::cout << "Hp " << x.getHitPoints() << '\n';
	std::cout << "Energy " << x.getEnergyPoints() << '\n';
	for (int i = 0; i < 5; ++i){
		x.ninjaShoebox ();
	}

	SuperTrap t("asvirido SuperTrap");

	t.meleeAttack("liderako");
	t.rangedAttack("tower");

	std::cout << "Hp " << t.getHitPoints() << '\n';
	t.takeDamage(50);
	std::cout << "HP " << t.getHitPoints() << '\n';
	t.beRepaired(40);
	std::cout << "Hp " << t.getHitPoints() << '\n';
	std::cout << "Energy " << t.getEnergyPoints() << '\n';
	for (int i = 0; i < 5; ++i){
		t.vaulthunter_dot_exe("liderako");
	}
	t.ninjaShoebox ();
}