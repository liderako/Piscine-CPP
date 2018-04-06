#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy {

	public:
		SuperMutant(void); /* canonical */
		SuperMutant(SuperMutant const & f); /* canonical */
		~SuperMutant(void); /* canonical */

		/* operator */	
		SuperMutant & operator=( SuperMutant const & f ); // canonical
		// action 
void 	takeDamage(int damage);
};

#endif