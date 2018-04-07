#ifndef WIN_HPP
# define WIN_HPP

#include <iostream>
#include <ncurses.h>
#include "Frame.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"
#include "GameObject.hpp"

#define MAX_SIZE_X 364
#define MAX_SIZE_Y 84
#define COUNT_ASTEROID 100

class Win {
	private:
		// var
		int 		height;
		int 		width;
		char		map[85][385];
		WINDOW 		*win;
		Frame		frame;
		Asteroid 	*asteroid;
		// functions
		void 	initMap(void);
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
			Asteroid 	*getAsteroids(void) const;
		/* sets */
			void setWidth( int const r );
			void setHeight( int const r );
			// void setWINDOW( WINDOW *w );
		/* actions */
			void 	updateHorizont(void);
			void 	updateDisplay(void);

			void 	updatePositionPlayer(Player &p, int key);
			void 	updatePositionObjcet(Player &p);
			void 	winExit(void);
};

#endif