#include "Ncurses.hpp"

/* construct and destruct */
Ncurses::Ncurses( void ) {
	initscr();
	return ;
}

Ncurses::Ncurses( Ncurses const & Ncurses) {
	initscr();
	*this = Ncurses;
}

Ncurses::~Ncurses( void ) {
	endwin();
}

/* operator */
Ncurses & Ncurses::operator=( Ncurses const & ncurses ) {
	this->someVarForCanonical = ncurses.someVarForCanonical;
	return *this;
}

void 	Ncurses::getCh() {
	getch();
}

void 	Ncurses::updateWindow(WINDOW *w) {
	wrefresh(w);
}
