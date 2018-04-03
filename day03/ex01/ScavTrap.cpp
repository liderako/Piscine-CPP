#include "ScavTrap.hpp"

// construct and destruct
ScavTrap::ScavTrap(void) {
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

ScavTrap::ScavTrap(std::string name) {
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

ScavTrap::~ScavTrap(void) {
	std::cout << "Rrrrrgh...this isn't working!\n";
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & f) {
	std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot. Ooh, ooh, here we go!\n";
	*this = f;
}

// sets
void 		ScavTrap::setHitPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->hitPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->hitPoints = this->getMaxHitPoints();
	else
		this->hitPoints = 0;
}

void 		ScavTrap::setMaxHitPoints(int x) {
	this->maxHitPoints = x;
}

void 		ScavTrap::setEnergyPoints(int x) {
	if (x >= 0 && x <= this->getMaxHitPoints())
		this->energyPoints = x;
	else if (x >= this->getMaxHitPoints())
		this->energyPoints = this->getMaxHitPoints();
	else
		this->energyPoints = 0;
}

void 		ScavTrap::setMaxEnergyPoints(int x) {
	this->maxEnergyPoints = x;
}

void 		ScavTrap::setLevel(int x) {
	this->level = x;
}

void 		ScavTrap::setMeleeAttackDamage(int x) {
	this->meleeAttackDamage = x;
}

void 		ScavTrap::setRangedAttackDamage(int x) {
	this->rangedAttackDamage = x;
}

void 		ScavTrap::setArmorDamageReduction(int x) {
	this->armorDamageReduction = x;
}

void 		ScavTrap::setName(std::string s){
	this->name = s;
}

// gets
int 		ScavTrap::getHitPoints(void)  const {
	return (this->hitPoints);
}

int 		ScavTrap::getMaxHitPoints(void) const  {
	return (this->maxHitPoints);
}

int 		ScavTrap::getEnergyPoints(void)  const {
	return (this->energyPoints);
}

int 		ScavTrap::getMaxEnergyPoints(void) const  {
	return (this->maxEnergyPoints);
}

int 		ScavTrap::getLevel(void)  const {
	return (this->level);
}

int 		ScavTrap::getMeleeAttackDamage(void)  const {
	return (this->meleeAttackDamage);
}

int 		ScavTrap::getRangedAttackDamage(void)  const {
	return (this->rangedAttackDamage);
}

int 		ScavTrap::getArmorDamageReduction(void)  const {
	return (this->armorDamageReduction);
}

std::string ScavTrap::getName(void) const {
	return (this->name);
}

// operator
ScavTrap & ScavTrap::operator=(ScavTrap const & f) {
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

void 	ScavTrap::rangedAttack(std::string const & target){
	std::cout << "SC4V-TP" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at range, causing" << " <" << this->getMeleeAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "SC4V-TP" << " <" << this->getName() << "> ";
	std::cout << "attacks" << " <" << target << "> ";
	std::cout << "at melle, causing" << " <" << this->getRangedAttackDamage() << "> ";
	std::cout << "points of damage !" << '\n';
}

// Когда вы наносите урон, вы должны учитывать снижение урона брони.
void 	ScavTrap::takeDamage(unsigned int amount) {
	amount -= this->getArmorDamageReduction();
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "SC4V-TP" << " <" << this->getName() << "> ";
	std::cout << "received" << " <" << amount << "> ";
	std::cout << "points of damage !" << '\n';
}

void 	ScavTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() <= 0)
		return ;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - amount);
	std::cout << "SC4V-TP" << " <" << this->getName() << "> ";
	std::cout << "beRepaired" << " <" << amount << "> ";
	std::cout << "hit of points !" << '\n';
}


void 				ScavTrap::challengeNewcomer(void) {
	std::string list[] = {"jump", "fuck", "dead", "sit down", "super rush"};
	if (this->getEnergyPoints() < 25) {
		std::cout << "Wow! WTF\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 25);
	size_t list_size = 5;
	size_t randI = rand() % list_size;
	std::cout << "ScavTrap" << " <" << this->getName() << "> ";
	std::cout << list[randI] << "\n";
}