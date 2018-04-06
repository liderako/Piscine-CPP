#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy {

	public:
		RadScorpion(void); /* canonical */
		RadScorpion(RadScorpion const & f); /* canonical */
		~RadScorpion(void); /* canonical */

		/* operator */	
		RadScorpion & operator=( RadScorpion const & f ); // canonical
		// action 
		void 	takeDamage(int damage);
};

#endif