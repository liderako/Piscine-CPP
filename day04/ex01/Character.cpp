#include "Character.hpp"

Character::Character( void ){
	this->actionPoints = 40;
	this->name = "default Character";
}

Character::Character( Character const & Character) {
	*this = Character;
}

Character::Character(std::string const & name)  {
	this->name = name;
	this->actionPoints = 40;
}

Character::~Character( void ) {
	return ;
}

Character & Character::operator=( Character const & character ) {
	this->name = character.getName();
	this->actionPoints = character.actionPoints;
	return *this;
}

std::string	Character::getName() const {
	return (this->name);
}

void 	Character::equip(AWeapon* w) {
	this->weapon = w;
}

void 	Character::recoverAP(void) {
	if (this->actionPoints + 10 > 40) {
		this->actionPoints = 40;
	}
	else {
		this->actionPoints += 10;
	}
}

void 	Character::attack(Enemy* enemy) {
	if (this->actionPoints >= this->weapon->getAPCost()) {
		this->actionPoints -= this->weapon->getAPCost();
		std::cout << this->name << " attacks " << enemy->getType() << " with a " << this->weapon->getName() << '\n';
		enemy->takeDamage(this->weapon->getDamage());
		if (enemy->getHP() == 0) {
			delete enemy;
		}
	}
}

AWeapon *Character::getWeapon() const {
	return (this->weapon);	
}
int 		Character::getAP() const {
	return (this->actionPoints);
}

std::ostream & operator<<(std::ostream & o, Character const & b) {
	if (b.getWeapon())
		return (o << b.getName() << "has " << b.getAP() << " AP and wields a "  << b.getWeapon()->getName());
	else
		return (o << b.getName() << "has " << b.getAP() << " AP and is unarmed");
}