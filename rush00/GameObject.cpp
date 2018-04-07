#include "GameObject.hpp"

GameObject::GameObject(Vector2 const & position) {
	this->position = position;
}

GameObject::GameObject(Vector2 const & position, int speed, int symbol, int hp, int attack) {
	this->position = position;
	this->speed = speed;
	this->symbol = symbol;
	this->hp = hp;
	this->attack = attack;
}

GameObject::GameObject(void) {
	this->position = Vector2();
	this->speed = 1;
	this->symbol = '#';
	this->hp = 10;
}

GameObject::GameObject( GameObject const & f ) {
	*this = f;	
}

GameObject::~GameObject(void) {
	return ;
}

Vector2 	GameObject::getPosition() const {
	return (this->position);
}

int 		GameObject::getSpeed() const {
	return (this->speed);
}

int 		GameObject::getSymbol() const {
	return (this->symbol);
}

int 		GameObject::getHp() const {
	return (this->hp);
}

void 		GameObject::setSymbol(int s) {
	this->symbol = s;
}

void		GameObject::setPosition(Vector2 const & p) {
	this->position = p;
}

void		GameObject::setHp(int const hp) {
	this->hp = hp;
}

GameObject & GameObject::operator=( GameObject const & f ) {
	this->setPosition(f.getPosition());
	this->speed = f.getSpeed();
	this->symbol = f.getSymbol();
	this->hp = f.getHp();
	return (*this);
}