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
