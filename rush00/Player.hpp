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
	bool 		moveRigth();
	bool		moveLeft();
	bool		moveDown();
	bool		moveUp();

	int 		getDamage();
	int 		getCountTime();
	void 		takeDamage(int damage);
	void 		setCountTime(int c);
};

#endif