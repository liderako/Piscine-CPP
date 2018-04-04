#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class NinjaTrap : public virtual ClapTrap{
	public:
// construct and destruct
		NinjaTrap(void);
		~NinjaTrap(void);
		NinjaTrap(NinjaTrap const & f);
		NinjaTrap(std::string name);

// operator 
	NinjaTrap & operator=(NinjaTrap const & f);
// action
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);

void 				ninjaShoebox(void);
}; 

#endif