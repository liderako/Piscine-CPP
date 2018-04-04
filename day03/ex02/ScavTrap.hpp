#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

#include <iostream>

class ScavTrap : public ClapTrap{
	public:
// construct and destruct
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & f);
		ScavTrap(std::string name);

// operator 
	ScavTrap & operator=(ScavTrap const & f);
// action
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);

void 				challengeNewcomer(void);
}; 

#endif