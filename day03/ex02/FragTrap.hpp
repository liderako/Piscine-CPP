#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
/* construct and destruct */
		FragTrap(void); 
		~FragTrap(void);
		FragTrap(FragTrap const & f);
		FragTrap(std::string name);
/* operator */ 
	FragTrap & operator=(FragTrap const & f);
/* action */
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);

void 				vaulthunter_dot_exe(std::string const & target);
}; 

#endif