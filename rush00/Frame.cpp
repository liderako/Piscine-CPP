#include "Frame.hpp"

Frame::Frame(int const xStart, int const xEnd, int const yStart, int const yEnd) {
	this->startX = xStart;
	this->endX = xEnd;
	this->startY = yStart;
	this->endY = yEnd;
}

Frame::Frame(void) {
	this->startX = 100;
	this->endX = 250;
	this->startY = 0;
	this->endY = 83;
}

Frame::Frame( Frame const & f ) {
	*this = f;
}

Frame::~Frame(void) {
	return ;
}

Frame & Frame::operator=( Frame const & f ) {
	this->startX = f.getStartX();
	this->endX = f.getEndX();
	this->startY = f.getStartY();
	this->endY = f.getEndY();
	return *this;
}

void 	Frame::setStartX(int const n) {
	this->startX = n;
}

void 	Frame::setEndX(int const n) {
	this->endX = n;
}

void 	Frame::setStartY(int const n) {
	this->startY = n;
}

void 	Frame::setEndY(int const y) {
	this->endY = y;
}

int 	Frame::getStartX(void) const {
	return (this->startX);
}

int 	Frame::getStartY(void) const {
	return (this->startY );
}

int 	Frame::getEndX(void) const {
	return (this->endX);
}

int 	Frame::getEndY(void) const {
	return (this->endY);
}

bool 	Frame::endHorizontX(int x, int y) {
	if (x > this->startX && x < this->endX && (y == this->startY || y == this->endY)) {
		return (true);
	}
	return (false);
}

bool 	Frame::endHorizontY(int x, int y) {
	if ((x == this->startX || x == this->endX) && (y > this->startY && y < this->endY)) {
		return (true);
	}
	return (false);
}