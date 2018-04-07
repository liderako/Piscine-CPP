#ifndef NCURSES_HPP
#define NCURSES_HPP
#include <ncurses.h>

class Ncurses {
	public:
int someVarForCanonical;
		/* construct and destruct */
		Ncurses( void ); /* canonical */
		Ncurses( Ncurses const & f ); /* canonical */
		~Ncurses( void ); /* canonical */
		/* operator */	
		Ncurses & operator=( Ncurses const & f ); /* canonical */
		/* actions */
		void 	updateWindow(WINDOW *w);
		int 	getCh();
};

#endif