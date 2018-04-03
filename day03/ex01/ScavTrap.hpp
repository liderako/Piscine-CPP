#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

#include <iostream>

class ScavTrap{
	private:
		size_t hitPoints;
		size_t maxHitPoints;
		size_t energyPoints;
		size_t maxEnergyPoints;
		size_t level;
		size_t meleeAttackDamage;
		size_t rangedAttackDamage;
		size_t armorDamageReduction;
		std::string name;
	public:
// construct and destruct
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & f);
		ScavTrap(std::string name);
// sets
		void 		setHitPoints(int const x);
		void 		setMaxHitPoints(int const x);
		void 		setEnergyPoints(int const x);
		void 		setMaxEnergyPoints(int const x);
		void 		setLevel(int const x);
		void 		setMeleeAttackDamage(int const x);
		void 		setRangedAttackDamage(int const x);
		void 		setArmorDamageReduction(int const x);
		void 		setName(std::string const s);
// gets
		int 		getHitPoints(void) const ;
		int 		getMaxHitPoints(void) const ;
		int 		getEnergyPoints(void) const ;
		int 		getMaxEnergyPoints(void) const ;
		int 		getLevel(void) const ;
		int 		getMeleeAttackDamage(void) const ;
		int 		getRangedAttackDamage(void) const ;
		int 		getArmorDamageReduction(void) const ;
		std::string getName(void) const ;
// operator 
	ScavTrap & operator=(ScavTrap const & f);
// action
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);

void 				challengeNewcomer(void);
// void 				vaulthunter_dot_exe(std::string const & target);
}; 

#endif