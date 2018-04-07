#include "Vector2.hpp"

Vector2::Vector2(int const x, int const y) {
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

void 	Vector2::setX(int const x) {
	this->x = x;
}

void 	Vector2::setY(int const y) {
	this->y = y;
}

int 	Vector2::getX(void) const {
	return (this->x);
}

int 	Vector2::getY(void) const {
	return (this->y);
}

Vector2::Vector2( Vector2 const & f ) {
	*this = f;
}

Vector2 & Vector2::operator=( Vector2 const & f ) {
	this->x = f.getX();
	this->y = f.getY();
	return *this;
}