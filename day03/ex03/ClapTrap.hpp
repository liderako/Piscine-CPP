#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
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
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(ClapTrap const & f);
		ClapTrap(std::string name);
		ClapTrap(size_t hitPoints, size_t maxHitPoints, size_t energyPoints, size_t maxEnergyPoints, size_t level, size_t meleeAttackDamage, size_t rangedAttackDamage, size_t armorDamageReduction, std::string name);
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
	ClapTrap & operator=(ClapTrap const & f);
}; 

#endif