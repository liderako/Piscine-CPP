#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

	public:
		PlasmaRifle(void); /* canonical */
		PlasmaRifle(PlasmaRifle const & f); /* canonical */
		~PlasmaRifle(void); /* canonical */

		/* operator */	
		PlasmaRifle & operator=( PlasmaRifle const & f ); // canonical
		// action 
		void attack() const;
};

#endif