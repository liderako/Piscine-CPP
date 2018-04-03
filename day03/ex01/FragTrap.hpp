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
	FragTrap & operator=(FragTrap const & f);
// action
void 				rangedAttack(std::string const & target);
void 				meleeAttack(std::string const & target);
void 				takeDamage(unsigned int amount);
void 				beRepaired(unsigned int amount);

void 				vaulthunter_dot_exe(std::string const & target);
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