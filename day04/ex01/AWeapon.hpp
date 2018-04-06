#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon {
protected:
	int 		apCost;
	int 		damage;
	std::string name;
	public:
		AWeapon(void); /* canonical */
		AWeapon(AWeapon const & f); /* canonical */
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon(void); /* canonical */

		// gets
		std::string	getName() const;
		int 		getAPCost() const;
		int 		getDamage() const;

		/* operator */	
		AWeapon & operator=( AWeapon const & f ); // canonical
		// action 
		virtual void attack() const = 0;
};

#endif