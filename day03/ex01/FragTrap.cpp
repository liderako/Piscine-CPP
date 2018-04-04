#include "FragTrap.hpp"

// construct and destruct
FragTrap::FragTrap(void) {
	std::cout << "Yoo hoooooooooo!\n";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->name = "default";
	return ;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "I'm over here!\n";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->name = name;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "Rrrrrgh...this isn't working!\n";
	return ;
}

FragTrap::FragTrap(FragTrap const & f) {
	std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\n";
	*this = f;
}

// sets
void 		FragTrap::setHitPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->hitPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->hitPoints = this->getMaxHitPoints();
	else
		this->hitPoints = 0;
}

void 		FragTrap::setMaxHitPoints(int x) {
	this->maxHitPoints = x;
}

void 		FragTrap::setEnergyPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->energyPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->energyPoints = this->getMaxHitPoints();
	else
		this->energyPoints = 0;
}

void 		FragTrap::setMaxEnergyPoints(int x) {
	this->maxEnergyPoints = x;
}

void 		FragTrap::setLevel(int x) {
	this->level = x;
}

void 		FragTrap::setMeleeAttackDamage(int x) {
	this->meleeAttackDamage = x;
}

void 		FragTrap::setRangedAttackDamage(int x) {
	this->rangedAttackDamage = x;
}

void 		FragTrap::setArmorDamageReduction(int x) {
	this->armorDamageReduction = x;
}

void 		FragTrap::setName(std::string s){
	this->name = s;
}

// gets
int 		FragTrap::getHitPoints(void)  const {
	return (this->hitPoints);
}

int 		FragTrap::getMaxHitPoints(void) const  {
	return (this->maxHitPoints);
}

int 		FragTrap::getEnergyPoints(void)  const {
	return (this->energyPoints);
}

int 		FragTrap::getMaxEnergyPoints(void) const  {
	return (this->maxEnergyPoints);
}

int 		FragTrap::getLevel(void)  const {
	return (this->level);
}

int 		FragTrap::getMeleeAttackDamage(void)  const {
	return (this->meleeAttackDamage);
}

int 		FragTrap::getRangedAttackDamage(void)  const {
	return (this->rangedAttackDamage);
}

int 		FragTrap::getArmorDamageReduction(void)  const {
	return (this->armorDamageReduction);
}

std::string FragTrap::getName(void) const {
	return (this->name);
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
		std::cout << "Wow! You're not dead?\n";
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