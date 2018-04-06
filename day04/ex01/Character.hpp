#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"

class Character {

	private:
		int 		actionPoints;
		AWeapon		*weapon;
		std::string name;
	public:
		Character(void); /* canonical */
		Character(Character const & f); /* canonical */
		Character(std::string const & name);
		virtual ~Character(void); /* canonical */

		// gets
		std::string	getName() const;
		std::string getWeaponName() const;
		int 		getAP() const ;
		/* operator */	
		Character & operator=( Character const & f ); // canonical
		// actions
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
};
std::ostream & operator<<(std::ostream & o, Character const & b);
#endif