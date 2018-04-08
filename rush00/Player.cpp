#include "Player.hpp"

Player::Player(void) : GameObject(Vector2(150, 60), 1, 'W', 100, 15) {
	this->timeout = 2;
	this->countTime = 0;
	this->scope = 0;
	this->ammo = 1000;
	this->life = 3;
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
	if (this->hp == 0 && this->life > 0) {
		life--;
		this->hp = 100;
	}
}


int 		Player::getScope() {
	return (this->scope);
}
int 		Player::getLife() {
	return (this->life);
}
int 		Player::getAmmo() {
	return (this->ammo);
}

void 		Player::setScope(int scope) {
	this->scope = scope;
}
void 		Player::setLife(int life) {
	this->life = life;
}

void 		Player::recharge(void) {
	this->countTime++;
}

bool 		Player::attack() {
	if (this->countTime >= 3 && this->ammo > 0) {
		countTime = 0;
		this->ammo--;
		return (true);
	}
	return (false);
}
