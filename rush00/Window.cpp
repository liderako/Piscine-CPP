#include "Window.hpp"
#include <ncurses.h>
#include <sstream>
/* construct and destruct */
Win::Win( void ) : frameStatic(100, 250, 89, 100) {
	getmaxyx(stdscr, this->height, this->width);
	if (this->height != MAX_SIZE_Y || this->width != MAX_SIZE_X){
		endwin();
		std::cout << this->height  << "\n" << this->width;
		std::cout << "Error size window\n";
		std::exit(-1);
	}
	this->win = newwin(this->height, this->width, 0, 0);
	this->asteroid = new Asteroid[COUNT_ASTEROID];
	this->maxScope = 5000;
	this->initAsteroid();
	initMap();
}

Win::Win( Win const & window) {
	*this = window;
}

Win::~Win( void ) {
	delete [] asteroid;
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

int 	Win::getMaxScope() const {
	return (this->maxScope);
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
	this->map[p.getPosition().getY()][p.getPosition().getX()] = p.getSymbol();
	for (int i = 0; i < COUNT_ASTEROID; i++) {
		if ((this->asteroid[i].moveDown()) == true) {
			this->map[this->asteroid[i].getPosition().getY() - 1][this->asteroid[i].getPosition().getX()] = ' ';
			if (this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] == p.getSymbol()) {
				p.takeDamage(this->asteroid[i].attacks());
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = p.getSymbol();
				this->asteroid[i].dead();
			}
			else if (this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] == '^') {
				this->asteroid[i].takeDamage(p.getAttack());
				if (this->asteroid[i].getHp() == 0) {
					this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = ' ';
					this->asteroid[i].dead();
				}
				else {
					this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = this->asteroid[i].getSymbol();
				}
			}
			else
				this->map[this->asteroid[i].getPosition().getY()][this->asteroid[i].getPosition().getX()] = this->asteroid[i].getSymbol();
		}
	}
}

void 	Win::render(Player &p) {
	int 	y;
	int 	x;

	y = 0;
	while (y < this->height) {
		x = 0;
		while (x < this->width) {
			if ((this->frame.endHorizontX(x, y)) == true) {
				this->putColor('_',5);
			}
			else if ((this->frame.endHorizontY(x, y)) == true) {
				this->putColor('|',5);
			}
			else if ((this->frameStatic.endHorizontX(x, y)) == true) {
				this->putColor('_',5);
			}
			else if ((this->frameStatic.endHorizontY(x, y)) == true) {
				this->putColor('|',5);
			}
			else if (y > this->frame.getEndY() - 2 && y < this->frameStatic.getStartY() + 1 && x >= this->frame.getStartX() && x <= this->frame.getEndX()) {
				printw(" ");
			}
			else {
				if (this->map[y][x] == ','){
					this->putColor(',',3);
				}
				else if (this->map[y][x] == '*') {
					this->putColor('*',2);
				}
				else if (this->map[y][x] == '.') {
					this->putColor('.',1);
				}
				else if (y >= this->frameStatic.getStartY() && y < this->frameStatic.getEndY() && x >= this->frameStatic.getStartX() && x <= this->frameStatic.getEndX()) {
					if (x - 2 == this->frameStatic.getStartX() && y - 2 == this->frameStatic.getStartY()) {
						printw("Scope: %13d",p.getScope());
						x += 19;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 4 == this->frameStatic.getStartY()) {
						printw("life: %14d",p.getLife());
						x += 19;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 6 == this->frameStatic.getStartY()) {
						printw("Hp: %16d",p.getHp());
						x += 19;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 8 == this->frameStatic.getStartY()) {
						printw("Ammo: %14d",p.getAmmo());
						x += 19;
					}
					else if (x - 2 == this->frameStatic.getStartX() && y - 10 == this->frameStatic.getStartY()) {
						printw("Finish Scope: %6d",this->maxScope);
						x += 19;
					}
					else if (x - 44 == this->frameStatic.getStartX() && y - 4 == this->frameStatic.getStartY()) {
						printw("W A S D : Move");
						x += 13;
					}
					else if (x - 44 == this->frameStatic.getStartX() && y - 6 == this->frameStatic.getStartY()) {
						printw("Space: Fire");
						x += 10;
					}
					else if (x - 44 == this->frameStatic.getStartX() && y - 8 == this->frameStatic.getStartY()) {
						printw("ESC: Exit");
						x += 8;
					}
					else if (x - 82 == this->frameStatic.getStartX() && y - 6 == this->frameStatic.getStartY()) {
						printw("Target of the game: Stay alive 5000 light years");
						x += 46;
					}
					else {
						printw(" ");
					}
				}
				else {
					if (this->map[y][x] == '#' ||  this->map[y][x] == '$') {
						this->putColor(this->map[y][x], 2);
					}
					else if (this->map[y][x] == '@' ||  this->map[y][x] == '%') {
						this->putColor(this->map[y][x], 1);
					}
					else if (this->map[y][x] == '&' ||  this->map[y][x] == 'B') {
						this->putColor(this->map[y][x], 6);
					}
					else if (this->map[y][x] == p.getSymbol()) {
						attron(A_BOLD);
						printw("%c",p.getSymbol());
						attroff(A_BOLD);
					}
					else 
						printw("%c", this->map[y][x]);
				}
			}
			x++;
		}
		y++;
	}
}

void 	Win::checkSize() {
  	int x = 0;
  	int y = 0;
	getmaxyx(stdscr, y, x);
	if (this->getHeight() != y || this->getWidth() != x) {
		endwin();
		std::cout << "Don't touch window! Pidor\n";
		std::exit(-1);
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


void 	Win::putColor(char c, int color) {
		attron(COLOR_PAIR(color));
		printw("%c", c);
		attroff(COLOR_PAIR(color));
}


void 	Win::initAsteroid(void) {
	char sAsteroid[] = {'#','$', '@', '%', '&', 'B'};
	int  hpAsteroid[] = {15, 15, 30, 30, 45, 45};
	int  damageAsteroid[] = {100, 100, 60, 60, 25, 25};

	for (int i = 0; i < COUNT_ASTEROID; i++) {
		this->asteroid[i].setPosX(i);
		int res = (rand() % (70));
		int randX = rand() % 6;
		this->asteroid[i].setPosY(res);
		this->asteroid[i].setSymbol(sAsteroid[randX]);
		this->asteroid[i].setMaxHp(hpAsteroid[randX]);
		this->asteroid[i].setHp(hpAsteroid[randX]);
		this->asteroid[i].setAttack(damageAsteroid[randX]);
	}
}