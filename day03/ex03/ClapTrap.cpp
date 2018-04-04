#include "ClapTrap.hpp"

// construct and destruct
ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap: init\n";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->name = "default";
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap: init\n";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->name = name;
}

ClapTrap::ClapTrap(size_t hitPoints, size_t maxHitPoints, size_t energyPoints, size_t maxEnergyPoints, size_t level, size_t meleeAttackDamage, size_t rangedAttackDamage, size_t armorDamageReduction, std::string name) {
	std::cout << "ClapTrap: init\n";
	this->hitPoints = hitPoints;
	this->maxHitPoints = maxHitPoints;
	this->energyPoints = energyPoints;
	this->maxEnergyPoints = maxEnergyPoints;
	this->level = level;
	this->meleeAttackDamage = meleeAttackDamage;
	this->rangedAttackDamage = rangedAttackDamage;
	this->armorDamageReduction = armorDamageReduction;
	this->name = name;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap: dead\n";
}

ClapTrap::ClapTrap(ClapTrap const & f) {
	std::cout << "ClapTrap: init\n";
	*this = f;
}


// sets
void 		ClapTrap::setHitPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->hitPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->hitPoints = this->getMaxHitPoints();
	else
		this->hitPoints = 0;
}

void 		ClapTrap::setMaxHitPoints(int x) {
	this->maxHitPoints = x;
}

void 		ClapTrap::setEnergyPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->energyPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->energyPoints = this->getMaxHitPoints();
	else
		this->energyPoints = 0;
}

void 		ClapTrap::setMaxEnergyPoints(int x) {
	this->maxEnergyPoints = x;
}

void 		ClapTrap::setLevel(int x) {
	this->level = x;
}

void 		ClapTrap::setMeleeAttackDamage(int x) {
	this->meleeAttackDamage = x;
}

void 		ClapTrap::setRangedAttackDamage(int x) {
	this->rangedAttackDamage = x;
}

void 		ClapTrap::setArmorDamageReduction(int x) {
	this->armorDamageReduction = x;
}

void 		ClapTrap::setName(std::string s){
	this->name = s;
}

// gets
int 		ClapTrap::getHitPoints(void)  const {
	return (this->hitPoints);
}

int 		ClapTrap::getMaxHitPoints(void) const  {
	return (this->maxHitPoints);
}

int 		ClapTrap::getEnergyPoints(void)  const {
	return (this->energyPoints);
}

int 		ClapTrap::getMaxEnergyPoints(void) const  {
	return (this->maxEnergyPoints);
}

int 		ClapTrap::getLevel(void)  const {
	return (this->level);
}

int 		ClapTrap::getMeleeAttackDamage(void)  const {
	return (this->meleeAttackDamage);
}

int 		ClapTrap::getRangedAttackDamage(void)  const {
	return (this->rangedAttackDamage);
}

int 		ClapTrap::getArmorDamageReduction(void)  const {
	return (this->armorDamageReduction);
}

std::string ClapTrap::getName(void) const {
	return (this->name);
}

// operator
ClapTrap & ClapTrap::operator=(ClapTrap const & f) {
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