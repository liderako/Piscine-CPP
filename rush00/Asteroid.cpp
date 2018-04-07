#include "Asteroid.hpp"
#include "ncurses.h"
Asteroid::Asteroid(void) : GameObject(Vector2(0, 0), 1, '#', 10, 15) {
	return ;
}

Asteroid::Asteroid(int xSpawn, int ySpawn) : GameObject(Vector2(xSpawn, ySpawn), 1, '#', 10, 15) {
	return ;
}

Asteroid::~Asteroid(void) {
	return ;
}

Asteroid::Asteroid( Asteroid const & f ) {
	*this = f;
}

Asteroid & Asteroid::operator=( Asteroid const & f ) {
	this->setPosition(f.getPosition());
	return *this;
}

bool		Asteroid::moveDown() {
	int y;

	y = this->position.getY();
	if (y + 1 <= this->frame.getEndY()) {
		this->position.setY(y + this->getSpeed());
		if (this->position.getY() >= this->frame.getEndY()){
			this->setPosX(rand() % 30);
			this->setPosY((rand() % 2) + 3);
		}
		return (true);
	}
	return false;
}

void 	Asteroid::setPosX(int const x) {
	int j = 1;
		if (x < this->frame.getStartX() || x > this->frame.getEndX()) {
			while (1) {
				int res = rand() % j;
				if (res > this->frame.getStartX() && res < this->frame.getEndX()) {
					this->position.setX(res);
					break ;
				}
				j+= 100;
				if (j < 0)
				j = 10;
			}
		}
		else if (x >= this->frame.getStartX() && x <= this->frame.getEndX()) {
			this->position.setX(x);
		}
}

void	Asteroid::dead(void) {
	this->setPosX(rand() % 30);
	this->setPosY((rand() % 2) + 3);
}

void 	Asteroid::setPosY(int const x) {
	this->position.setY(x);
}

bool 		Asteroid::moveRigth() {
	return false;
}

bool		Asteroid::moveLeft() {
	return false;
}

bool		Asteroid::moveUp() {
	return false;
}

void 		Asteroid::takeDamage(int damage) {
	if (damage < 0) {
		return ;
	}
	if (this->getHp() > 0)
	{
		if (this->hp - damage <= 0) {
			this->hp = 0;
			this->dead();
		}
		else {
			this->hp -= damage;
		}
	}
}
