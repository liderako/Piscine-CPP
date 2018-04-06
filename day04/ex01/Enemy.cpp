#include "Enemy.hpp"

Enemy::Enemy( void ) {
	this->hp = 0;
	this->name = "default Enemy";
}

Enemy::Enemy( Enemy const & Enemy) {
	*this = Enemy;
}

Enemy::Enemy(int hp, std::string const & type)  {
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy( void ) {
	return ;
}

Enemy & Enemy::operator=( Enemy const & enemy ) {
	this->type = Enemy.getType();
	this->hp = Enemy.getHp();
	return *this;
}

std::string	Enemy::getType() const {
	return (this->type);
}

int 		Enemy::getHp() const {
	return (this->apCost);
}

void 	Enemy::takeDamage(int damage) {
	if (damage < 0) {
		return ;
	}
	if (this->getHp() > 0)
	{
		if (this->hp - damage <= 0) {
			this->hp = 0;
		}
		else {
			this->hp -= damage;
		}
	}
}