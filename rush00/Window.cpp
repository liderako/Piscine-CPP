#include "Window.hpp"
#include <ncurses.h>

/* construct and destruct */
Win::Win( void ) {
	char s[] = {'#','$', '@', '%', '&', '*', 'D'};
	getmaxyx(stdscr, this->height, this->width);
	if (this->height != MAX_SIZE_Y || this->width != MAX_SIZE_X){
		endwin();
		std::cout << "Error size window\n";
		std::exit(-1);
	}
	this->win = newwin(this->height, this->width, 0, 0);
	this->asteroid = new Asteroid[COUNT_ASTEROID];
	for (int i = 0; i < COUNT_ASTEROID; i++) {
		this->asteroid[i].setPosX(i);
		int res = (rand() % (70));
		this->asteroid[i].setPosY(res);
		this->asteroid[i].setSymbol(s[rand() % 6]);
	}
	initMap();
}

Win::Win( Win const & window) {
	*this = window;
}

Win::~Win( void ) {
	return ;
}

void Win::winExit(void) {
	endwin();
	std::exit(-1);
}

/* operator */
Win & Win::operator=( Win const & window ) {
	this->width = window.getWidth();
	this->height = window.getHeight();
	return *this;
}

/* gets */ 
int 	Win::getHeight(void) const {
	return (this->height);
}

int 	Win::getWidth(void) const {
	return (this->width);
}

Asteroid 	*Win::getAsteroids(void) const {
	return (this->asteroid);
}

WINDOW *Win::getWINDOW(void) const {
	return (this->win);
}

/* sets */
void 	Win::setWidth( int const r ) {
	this->width = r;
}
void 	Win::setHeight( int const r ) {
	this->height = r;
}

/* actions */
void 	Win::updateHorizont() {
	getmaxyx(this->win, this->width, this->height);
}

void 	Win::updatePositionPlayer(Player &p, int key) {
	if (key == 'w' && (p.moveUp()) == true) {
		this->map[p.getPosition().getY() + p.getSpeed()][p.getPosition().getX()] = ' ';
	}
	else if (key == 's' && (p.moveDown()) == true) {
		this->map[p.getPosition().getY() - p.getSpeed()][p.getPosition().getX()] = ' ';
	}
	else if (key == 'a' && (p.moveLeft()) == true) {
		this->map[p.getPosition().getY()][p.getPosition().getX() + p.getSpeed()] = ' ';
	}
	else if (key == 'd' && (p.moveRigth()) == true) {
		this->map[p.getPosition().getY()][p.getPosition().getX() - p.getSpeed()] = ' ';
	}
	this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
}


void 	Win::updatePositionObjcet(Player &p) {
	for (int i = 0; i < COUNT_ASTEROID; i++) {
		if ((this->asteroid[i].moveDown()) == true) {
			this->map[this->asteroid[i].getPosition().getY() - 1][this->asteroid[i].getPosition().getX()] = ' ';
			if (this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] == p.getSymbol()) {
				p.takeDamage(this->asteroid[i].attacks());
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = p.getSymbol();
				this->asteroid[i].dead();
			}
			else
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = this->asteroid[i].getSymbol();
		}
	}

}

void 	Win::updateDisplay() {
	int 	y;
	int 	x;

	y = 0;
	while (y < this->height) {
		x = 0;
		while (x < this->width) {
			if ((this->frame.endHorizontX(x, y)) == true) {
				printw("_");
			}
			else if ((this->frame.endHorizontY(x, y)) == true) {
				printw("|");
			}
			else if (y > this->frame.getEndY() - 2 && x >= this->frame.getStartX()) {
				printw(" ");
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
	y = 0;
	x = 0;
	while (y < this->height) {
		x = 1;
		while (x < this->width) {
			if (x < this->frame.getStartX() || x > this->frame.getEndX()) {
				if (rand() % 125 == 0)
					this->map[y][x] = '.';
				else if (rand() % 666 == 0) {
					this->map[y][x] = '*';
				}
				else if (rand() % 444 == 0) {
					this->map[y][x] = ',';
				}
			}
			x++;
		}
		y++;
	}
}














