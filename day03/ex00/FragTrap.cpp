#include "FragTrap.hpp"

// construct and destruct
FragTrap::FragTrap(void) {
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
	return ;
}

FragTrap::FragTrap(FragTrap const & f) {
	*this = f;
}

// sets
void 		FragTrap::setHitPoints(size_t x) {
	this->hitPoints = x;
}
void 		FragTrap::setMaxHitPoints(size_t x) {
	this->maxHitPoints = x;
}
void 		FragTrap::setEnergyPoints(size_t x) {
	this->energyPoints = x;
}
void 		FragTrap::setMaxEnergyPoints(size_t x) {
	this->maxEnergyPoints = x;
}
void 		FragTrap::setLevel(size_t x) {
	this->level = x;
}
void 		FragTrap::setMeleeAttackDamage(size_t x) {
	this->meleeAttackDamage = x;
}
void 		FragTrap::setRangedAttackDamage(size_t x) {
	this->rangedAttackDamage = x;
}
void 		FragTrap::setArmorDamageReduction(size_t x) {
	this->armorDamageReduction = x;
}
void 		FragTrap::setName(std::string s){
	this->name = s;
}

// gets
size_t 		FragTrap::getHitPoints(void)  const {
	return (this->hitPoints);
}
size_t 		FragTrap::getMaxHitPoints(void) const  {
	return (this->maxHitPoints);
}
size_t 		FragTrap::getEnergyPoints(void)  const {
	return (this->energyPoints);
}
size_t 		FragTrap::getMaxEnergyPoints(void) const  {
	return (this->maxEnergyPoints);
}
size_t 		FragTrap::getLevel(void)  const {
	return (this->level);
}
size_t 		FragTrap::getMeleeAttackDamage(void)  const {
	return (this->meleeAttackDamage);
}
size_t 		FragTrap::getRangedAttackDamage(void)  const {
	return (this->rangedAttackDamage);
}
size_t 		FragTrap::getArmorDamageReduction(void)  const {
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
void 	FlagTrap::rangedAttack(std::string const & target){

}
void 	FlagTrap::meleeAttack(std::string const & target){

}
void 	FlagTrap::takeDamage(unsigned int amount){

}
void 	FlagTrap::beRepaired(unsigned int amount){

}