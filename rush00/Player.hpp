#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "GameObject.hpp"
#include "Frame.hpp"

class Player : public GameObject{
private:
	Frame 	frame;
	int 	countTime;
	int 	timeout;
	int		life;
	int 	scope;
	int 	ammo;
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

	int 		getScope();
	int 		getLife();
	int 		getAmmo();

	void 		setScope(int scope);
	void 		setLife(int life);

	void 		takeDamage(int damage);
	void 		recharge();
	bool 		attack();
};

#endif