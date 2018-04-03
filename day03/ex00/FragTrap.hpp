#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap{
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
		FragTrap(void);
		~FragTrap(void);
		FragTrap(FragTrap const & f);
		FragTrap(std::string name);
// sets
		void 		setHitPoints(size_t const x);
		void 		setMaxHitPoints(size_t const x);
		void 		setEnergyPoints(size_t const x);
		void 		setMaxEnergyPoints(size_t const x);
		void 		setLevel(size_t const x);
		void 		setMeleeAttackDamage(size_t const x);
		void 		setRangedAttackDamage(size_t const x);
		void 		setArmorDamageReduction(size_t const x);
		void 		setName(std::string const s);
// gets
		size_t 		getHitPoints(void) const ;
		size_t 		getMaxHitPoints(void) const ;
		size_t 		getEnergyPoints(void) const ;
		size_t 		getMaxEnergyPoints(void) const ;
		size_t 		getLevel(void) const ;
		size_t 		getMeleeAttackDamage(void) const ;
		size_t 		getRangedAttackDamage(void) const ;
		size_t 		getArmorDamageReduction(void) const ;
		std::string getName(void) const ;
// operator 
	FragTrap & operator=(FragTrap const & f);
// action
void 	rangedAttack(std::string const & target);
void 	meleeAttack(std::string const & target);
void 	takeDamage(unsigned int amount);
void 	beRepaired(unsigned int amount);
}; 

#endif


/*

• Hit points (100)
• Max hit points (100)
• Energy points (100)
• Max energy points (100)
• Level (1)
• Name (Parameter of constructor)
• Melee attack damage (30)
• Ranged attack damage (20)
• Armor damage reduction (5)


void 	rangedAttack(std::string const & target);
void 	meleeAttack(std::string const & target);
void 	takeDamage(unsigned int amount);
void 	beRepaired(unsigned int amount);

*/