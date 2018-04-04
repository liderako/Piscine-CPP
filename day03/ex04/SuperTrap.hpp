#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

// SuperTrap

class SuperTrap : public FragTrap, public NinjaTrap {
	public:
/* construct and destruct */
		SuperTrap(void); 
		~SuperTrap(void);
		SuperTrap(SuperTrap const & f);
		SuperTrap(std::string name);
/* operator */ 
	SuperTrap & operator=(SuperTrap const & f);
/* action */
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);
void 				ninjaShoebox(void);
void 				vaulthunter_dot_exe(std::string const & target);

}; 

#endif