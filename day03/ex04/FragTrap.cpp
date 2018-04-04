#include "FragTrap.hpp"

// construct and destruct
FragTrap::FragTrap(void) : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, "default"){
	std::cout << "FragTrap: Yoo hoooooooooo!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, name){
	std::cout << "FragTrap: I'm over here!\n";
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap: Rrrrrgh...this isn't working!\n";
}

FragTrap::FragTrap(FragTrap const & f) {
	std::cout << "FragTrap: I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\n";
	*this = f;
}

// operator
FragTrap & FragTrap::operator=(FragTrap const & f) {
	this->setHitPoints(f.getHitPoints());
	this->setMaxHitPoints(f.getMaxHitPoints());
	this->setEnergyPoints(f.getEnergyPoints());
	this->setMaxEnergyPoints(f.getMaxEnergyPoints());
	this->setLevel(f.getLevel());
	this->setMeleeAttackDamage(f.getMeleeAttackDamage());
	this->setRangedAttackDamage(f.getRangedAttackDamage());
	this->setArmorDamageReduction(f.getArmorDamageReduction());
	this->setName(f.getName());
	return *this;
}

// actions

void 	FragTrap::rangedAttack(std::string const & target){
	std::cout << "FR4G-TP" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at range, causing" << " <" << this->getMeleeAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at melle, causing" << " <" << this->getRangedAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	FragTrap::takeDamage(unsigned int amount) {
	amount -= this->getArmorDamageReduction();
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "FR4G-TP" << " <" << this->getName() << "> ";
	std::cout << "received" << " <" << amount << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	FragTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() <= 0)
		return ;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - amount);
	std::cout << "FR4G-TP" << " <" << this->getName() << "> ";
	std::cout << "beRepaired" << " <" << amount << "> ";
	std::cout << "hit of points !" << '\n';
}


void 				FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string list[] = {"fire-ball", "show-ball", "ice-ball", "crazy-ball", "super rush"};
	size_t 		listDamage[] = {42,21,30,50,99};
	if (this->getEnergyPoints() < 25) {
		std::cout << "FragTrap: Wow! You're not dead?\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 25);
	size_t list_size = 5;
	size_t randI = rand() % list_size;
	std::cout << "FR4G-TP" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << list[randI] << " <" << listDamage[randI] << "> ";
	std::cout << "points of damage !" << '\n';
}