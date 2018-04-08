#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "GameObject.hpp"
#include "Frame.hpp"

class Player : public GameObject{
private:
	Frame 	frame;
	int 	countTime;
	int 	damage;
	int 	timeout;
public:
	Player(void);
	~Player(void);
	Player( Player const & f ); /* canonical */
	Player & operator=( Player const & f );
// actions

	bool 		moveRigth();
	bool		moveLeft();
	bool		moveDown();
	bool		moveUp();
	int 		getDamage();
	void 		takeDamage(int damage);
	void 		recharge();
	bool 		attack();
};

#endif