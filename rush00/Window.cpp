#include "Window.hpp"
#include <ncurses.h>

/* construct and destruct */
Win::Win( void ) {
	getmaxyx(stdscr, this->height, this->width);
	if (this->height != MAX_SIZE_Y || this->width != MAX_SIZE_X){
		endwin();
		std::cout << "Error size window\n";
		std::exit(-1);
	}
	this->win = newwin(this->height, this->width, 0, 0);
	this->startXFlame = 100;
	this->endXFlame = 250;
	this->startYFlame = 0;
	this->endYFlame = 80;
	initMap();
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
	getmaxyx(this->win, this->width, this->height);
}

void 	Win::updateDisplay() {
	int 	y;
	int 	x;

	y = 0;
	while (y < this->height) {
		x = 0;
		while (x < this->width) {
			if (this->endHorizontX(x,y)) {
				printw("_");
			}
			else if (endHorizontY(x,y)) {
				printw("|");
			}
			else {
				printw("%c", this->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

/////////////////////////////////////////
/*
// private method
*/
/////////////////////////////////////////

void 	Win::initMap() {
	int 	y;
	int 	x;

	y = 0;
	while (y < this->height) {
		x = 0;
		while (x < this->width) {
			this->map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

bool 	Win::endHorizontX(int x, int y) {
	if (x > this->startXFlame && x < this->endXFlame && (y == this->startYFlame || y == this->endYFlame)) {
		return (true);
	}
	return (false);
}

bool 	Win::endHorizontY(int x, int y) {
	if ((x == this->startXFlame || x == this->endXFlame) && (y > this->startYFlame && y < this->endYFlame)) {
		return (true);
	}
	return (false);
}