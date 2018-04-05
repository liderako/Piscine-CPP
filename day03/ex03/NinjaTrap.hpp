#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap{
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

void 				ninjaShoebox(NinjaTrap const & target);
void 				ninjaShoebox(FragTrap const & target);
void 				ninjaShoebox(ScavTrap const & target);

}; 

#endif