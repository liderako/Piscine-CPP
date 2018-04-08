#include "Ncurses.hpp"

/* construct and destruct */
Ncurses::Ncurses( void ) {
	this->init();
	return ;
}

Ncurses::Ncurses( Ncurses const & Ncurses) {
	this->init();
	*this = Ncurses;
}

Ncurses::~Ncurses( void ) {
}

/* operator */
Ncurses & Ncurses::operator=( Ncurses const & ncurses ) {
	this->someVarForCanonical = ncurses.someVarForCanonical;
	return *this;
}

int 	Ncurses::getCh() {
	timeout(150);
	return (getch());
}

void 	Ncurses::updateWindow(WINDOW *w) {
	wrefresh(w);
}

void 	Ncurses::end(void) {
	endwin();
}

void 	Ncurses::init(void) {
	initscr();
	start_color();
  	init_color(5, 233, 51, 55);
  	init_color(6, 27, 204, 210);
  	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, 5, COLOR_BLACK);
	init_pair(6, 6, COLOR_BLACK);
}
