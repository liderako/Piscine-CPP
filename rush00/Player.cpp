#include "Player.hpp"

Player::Player(void) : GameObject(Vector2(150, 60), 1, 'H', 100, 0) {
	this->damage = 5;
	this->timeout = 5;
	this->countTime = 0;
}

Player::~Player(void) {
}

Player::Player( Player const & f ) {
	*this = f;
}

Player & Player::operator=( Player const & f ) {
	this->setPosition(f.getPosition());
	return *this;
}

bool 		Player::moveRigth() {
	int x;

	x = this->position.getX();
	if (x + 3 <= this->frame.getEndX() ) {
			this->position.setX(x + this->getSpeed());
			return (true);
	}
	return false;
}

bool		Player::moveLeft() {
	int x;

	x = this->position.getX();
	if (x - 3 >= this->frame.getStartX() ) {
			this->position.setX(x - this->getSpeed());
			return (true);
	}
	return false;
}

bool		Player::moveDown() {
	int y;

	y = this->position.getY();
	if (y + 3 <= this->frame.getEndY() ) {
			this->position.setY(y + this->getSpeed());
			return (true);
	}
	return false;
}

bool		Player::moveUp() {
	int y;

	y = this->position.getY();
	if (y - 7 >= this->frame.getStartY() ) {
			this->position.setY(y - this->getSpeed());
			return (true);
	}
	return false;
}


void 		Player::takeDamage(int damage) {
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


void 		Player::recharge(void) {
	this->countTime++;
}

bool 		Player::attack() {
	if (this->countTime >= 3) {
		countTime = 0;
		return (true);
	}
	return (false);
}
