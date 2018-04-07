#include "Window.hpp"
#include <ncurses.h>

/* construct and destruct */
Win::Win( void ) {
	getmaxyx(stdscr, this->width, this->height);
	this->win = newwin(this->width, this->height, 0, 0);
}

Win::Win( Win const & window) {
	*this = window;
}

Win::~Win( void ) {
	return ;
}

// /* operator */
Win & Win::operator=( Win const & window ) {
	this->width = window.getWidth();
	this->height = window.getHeight();
	return *this;
}

// /* gets */ 
int 	Win::getHeight(void) const {
	return (this->height);
}

int 	Win::getWidth(void) const {
	return (this->width);
}

WINDOW *Win::getWINDOW(void) const {
	return (this->win);
}

// /* sets */
void 	Win::setWidth( int const r ) {
	this->width = r;
}
void 	Win::setHeight( int const r ) {
	this->height = r;
}

// /* actions */
void 	Win::updateHorizont() {
	getmaxyx(stdscr, this->width, this->height);
}