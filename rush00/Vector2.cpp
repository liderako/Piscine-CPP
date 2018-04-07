#include "Vector2.hpp"

Vector2::Vector2(int x, int y) {
	this->y = y;
	this->x = x;
}

Vector2::Vector2(void) {
	this->x = 0;
	this->y = 0;
}

Vector2::~Vector2(void) {
	return ;
}

void 	Vector2::setX(int x) {
	this->x = x;
}

void 	Vector2::setY(int y) {
	this->y = y;
}

int 	Vector2::getX(void) {
	return (this->x);
}

int 	Vector2::getY(void) {
	return (this->y);
}