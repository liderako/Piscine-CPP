#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy {

protected:
	int 		hp;
	std::string type;
	public:
		Enemy(void); /* canonical */
		Enemy(Enemy const & f); /* canonical */
		Enemy(int hp, std::string const & type);
		virtual ~Enemy(void); /* canonical */

		// gets
		std::string	getType() const;
		int 		getHp() const;

		/* operator */	
		Enemy & operator=( Enemy const & f ); // canonical
		// action 
		virtual void takeDamage(int);
};

#endif