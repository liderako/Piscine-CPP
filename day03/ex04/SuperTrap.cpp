#include "SuperTrap.hpp"

// construct and destruct
SuperTrap::SuperTrap(void) : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, "default") {
	std::cout << "SuperTrap: Yoo hoooooooooo!\n";
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, name) {
	std::cout << "SuperTrap: I'm over here!\n";
}

SuperTrap::~SuperTrap(void) {
	std::cout << "SuperTrap: Rrrrrgh...this isn't working!\n";
}

SuperTrap::SuperTrap(SuperTrap const & f) {
	std::cout << "SuperTrap: I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\n";
	*this = f;
}

// operator
SuperTrap & SuperTrap::operator=(SuperTrap const & f) {
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

void 	SuperTrap::rangedAttack(std::string const & target){
	FragTrap::rangedAttack(target);
}

void 	SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}

void 	SuperTrap::takeDamage(unsigned int amount) {
	amount -= this->getArmorDamageReduction();
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "SuperTrap:" << " <" << this->getName() << "> ";
	std::cout << "received" << " <" << amount << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	SuperTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() <= 0)
		return ;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - amount);
	std::cout << "SuperTrap:" << " <" << this->getName() << "> ";
	std::cout << "beRepaired" << " <" << amount << "> ";
	std::cout << "hit of points !" << '\n';
}
