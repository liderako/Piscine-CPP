#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon {

	public:
		PowerFist(void); /* canonical */
		PowerFist(PowerFist const & f); /* canonical */
		~PowerFist(void); /* canonical */

		/* operator */	
		PowerFist & operator=( PowerFist const & f ); // canonical
		// action 
		void attack() const;
};

#endif