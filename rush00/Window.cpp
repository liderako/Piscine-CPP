#include "Window.hpp"
#include <ncurses.h>
#include <sstream>
/* construct and destruct */
Win::Win( void ) : frameStatic(100, 250, 90, 100) {
	char s[] = {'#','$', '@', '%', '&', 'B', 'D'};
	getmaxyx(stdscr, this->height, this->width);
	if (this->height != MAX_SIZE_Y || this->width != MAX_SIZE_X){
		endwin();
		std::cout << this->height  << "\n" << this->width;
		std::cout << "Error size window\n";
		std::exit(-1);
	}
	this->win = newwin(this->height, this->width, 0, 0);
	
	this->downWin = newwin(250, 100, 100, 90);

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
		this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
	}
	else if (key == 's' && (p.moveDown()) == true) {
		this->map[p.getPosition().getY() - p.getSpeed()][p.getPosition().getX()] = ' ';
		this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
	}
	else if (key == 'a' && (p.moveLeft()) == true) {
		this->map[p.getPosition().getY()][p.getPosition().getX() + p.getSpeed()] = ' ';
		this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
	}
	else if (key == 'd' && (p.moveRigth()) == true) {
		this->map[p.getPosition().getY()][p.getPosition().getX() - p.getSpeed()] = ' ';
		this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
	}
	else if (key == ' ') {
		if (p.attack() == true) {
			this->map[p.getPosition().getY() - 1][p.getPosition().getX()] = '^';
		}
	}
}


void 	Win::updatePositionObjcet(Player &p) {
	for (int y = 1; y < this->height; y++) {
		for (int x = 1; x < this->width; x++) {
			if (this->map[y][x] == '^' && y < 10)
				this->map[y][x] = ' ';
			else if (this->map[y][x] == '^' && this->map[y - 1][x] == ' ') {
				this->map[y - 1][x] = '^';
				this->map[y][x] = ' ';
			}
		}
	}
	for (int i = 0; i < COUNT_ASTEROID; i++) {
		if ((this->asteroid[i].moveDown()) == true) {
			this->map[this->asteroid[i].getPosition().getY() - 1][this->asteroid[i].getPosition().getX()] = ' ';
			if (this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] == p.getSymbol()) {
				p.takeDamage(this->asteroid[i].attacks());
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = p.getSymbol();
				this->asteroid[i].dead();
			}
			else if (this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] == '^') {
				this->asteroid[i].dead();
			}
			else
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = this->asteroid[i].getSymbol();
		}
	}
}

void 	Win::render() {
	int 	y;
	int 	x;
	int 	flag = 0;

	y = 0;
	while (y < this->height) {
		x = 0;
		while (x < this->width) {
			if ((this->frame.endHorizontX(x, y)) == true) {
				attron(COLOR_PAIR(5));
				printw("_");
				attroff(COLOR_PAIR(5));
			}
			else if ((this->frame.endHorizontY(x, y)) == true) {
				attron(COLOR_PAIR(5));
				printw("|");
				attroff(COLOR_PAIR(5));
			}
			else if ((this->frameStatic.endHorizontX(x, y)) == true ) {
				printw("_");
			}
			else if ((this->frameStatic.endHorizontY(x, y)) == true) {
				printw("|");
			}
			else if (y > this->frame.getEndY() - 2 && y < this->frameStatic.getStartY() + 1 && x >= this->frame.getStartX() && x <= this->frame.getEndX()) {
				printw(" ");
			}
			else {
				if (this->map[y][x] == ','){
					attron(COLOR_PAIR(3));
					printw("%c", this->map[y][x]);
					attroff(COLOR_PAIR(3));
				}
				else if (this->map[y][x] == '*') {
					attron(COLOR_PAIR(2));
					printw("%c", this->map[y][x]);
					attroff(COLOR_PAIR(2));
				}
				else if (this->map[y][x] == '.') {
					attron(COLOR_PAIR(1));
					printw("%c", this->map[y][x]);
					attroff(COLOR_PAIR(1));
				}
				else if (y >= this->frameStatic.getStartY() && y < this->frameStatic.getEndY() && x >= this->frameStatic.getStartX() && x <= this->frameStatic.getEndX()) {
					if (x - 2 == this->frameStatic.getStartX() && y - 2 == this->frameStatic.getStartY()) {
						printw("Scope: %10d",10);
						x += 16;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 4 == this->frameStatic.getStartY()) {
						printw("life: %11d",10);
						x += 16;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 6 == this->frameStatic.getStartY()) {
						printw("Hp: %13d",10);
						x += 16;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 8 == this->frameStatic.getStartY()) {
						printw("Ammo: %11d",10);
						x += 16;
					}
					else {
						printw(" ");
					}
				}
				else {
					printw("%c", this->map[y][x]);
				}
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
				if (rand() % 125 == 0) {
					this->map[y][x] = '.';
				}
				else if (rand() % 666 == 0) {
					this->map[y][x] = '*';
				}
				else if (rand() % 444 == 0) {
					this->map[y][x] = ',';
				}
				else if (rand() % 133 == 0) {
					this->map[y][x] = '.';
				}
			}
			x++;
		}
		y++;
	}
}














