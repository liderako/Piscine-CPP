#ifndef WIN_HPP
# define WIN_HPP

#include <iostream>
#include <ncurses.h>

#define MAX_SIZE_X 364
#define MAX_SIZE_Y 84

class Win {
	private:
		int 	height;
		int 	width;
		int 	startXFlame;
		int 	endXFlame;
		int 	startYFlame;
		int 	endYFlame;
		char	map[85][385];
		WINDOW *win;
		void 	initMap(void);
		bool 	endHorizontX(int x, int y);
		bool 	endHorizontY(int x, int y);	
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
			void 	updateHorizont(void);
			void 	updateDisplay(void);
};

#endif