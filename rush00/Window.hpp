#ifndef WIN_HPP
# define WIN_HPP

#include <iostream>
#include <ncurses.h>

class Win {
	private:
		int 	height;
		int 	width;
		WINDOW *win;
	public:
		/* construct and destruct */
		Win( void ); /* canonical */
		Win( Win const & f ); /* canonical */
		~Win( void ); /* canonical */
		/* operator */	
		Win & operator=( Win const & f ); /* canonical */
		/* gets */
			int getHeight( void ) const ;
			int getWidth( void ) const ;
			WINDOW *getWINDOW( void ) const ;
		/* sets */
			void setWidth( int const r );
			void setHeight( int const r );
			// void setWINDOW( WINDOW *w );
		/* actions */
			void updateHorizont();
};

#endif