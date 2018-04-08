#ifndef WIN_HPP
# define WIN_HPP

#include <iostream>
#include <ncurses.h>
#include "Frame.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"
#include "GameObject.hpp"

#define MAX_SIZE_X 362
#define MAX_SIZE_Y 102
#define COUNT_ASTEROID 150

class Win {
	private:
		// var
		int 		height;
		int 		width;
		int 		maxScope;
		char		map[103][363];
		WINDOW 		*win;
		Frame		frame;
		Frame 		frameStatic;
		Asteroid 	*asteroid;
		// functions
		void 	initMap(void);
		void 	putColor(char c, int color);
		void 	initAsteroid(void);
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
			int getMaxScope() const;
		/* actions */
			void 	updateHorizont(void);
			void 	render(Player &p);

			void 	updatePositionPlayer(Player &p, int key);
			void 	updatePositionObjcet(Player &p);
			void 	winExit(void);

			void 	checkSize();
};

#endif