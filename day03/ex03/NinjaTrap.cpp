#include "NinjaTrap.hpp"

// construct and destruct
NinjaTrap::NinjaTrap(void) : ClapTrap(50, 50, 120, 120, 1, 60, 5, 0, "default") {
	std::cout << "NinjaTrap: Yoo hoooooooooo!\n";
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(50, 50, 120, 120, 1, 60, 5, 0, name) {
	std::cout << "NinjaTrap: I'm over here!\n";
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "NinjaTrap: Rrrrrgh...this isn't working!\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & f) {
	std::cout << "NinjaTrap: I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\n";
	*this = f;
}

// operator
NinjaTrap & NinjaTrap::operator=(NinjaTrap const & f) {
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

void 	NinjaTrap::rangedAttack(std::string const & target){
	std::cout << "NinjaTrap:" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at range, causing" << " <" << this->getMeleeAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << "NinjaTrap:" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at melle, causing" << " <" << this->getRangedAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	NinjaTrap::takeDamage(unsigned int amount) {
	amount -= this->getArmorDamageReduction();
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "NinjaTrap:" << " <" << this->getName() << "> ";
	std::cout << "received" << " <" << amount << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	NinjaTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() <= 0)
		return ;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - amount);
	std::cout << "NinjaTrap:" << " <" << this->getName() << "> ";
	std::cout << "beRepaired" << " <" << amount << "> ";
	std::cout << "hit of points !" << '\n';
}


void 				NinjaTrap::ninjaShoebox(NinjaTrap const & target) {
	if (this->getEnergyPoints() < 25) {
		std::cout << "NinjaTrap: Wow! WTF\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 25);
	std::cout << "NinjaTrap" << " <" << this->getName() << "> ";
	std::cout << "ninja Shoe box NinjaTrap " << target.getName() << '\n';
}

void 				NinjaTrap::ninjaShoebox(FragTrap const & target) {
	if (this->getEnergyPoints() < 25) {
		std::cout << "NinjaTrap: Wow! WTF\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 25);
	std::cout << "NinjaTrap" << " <" << this->getName() << "> ";
	std::cout << "ninja Shoe box FragTrap " << target.getName() << '\n';
}

void 				NinjaTrap::ninjaShoebox(ScavTrap const & target) {
	if (this->getEnergyPoints() < 25) {
		std::cout << "NinjaTrap: Wow! WTF\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 25);
	std::cout << "NinjaTrap" << " <" << this->getName() << "> ";
	std::cout << "ninja Shoe box ScavTrap " << target.getName() << '\n';
}