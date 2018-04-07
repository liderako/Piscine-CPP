#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "GameObject.hpp"
#include "Frame.hpp"

class Player : public GameObject{
private:
	Frame frame;
public:
	Player(Vector2 const & position);
	Player(void);
	~Player(void);
	Player( Player const & f ); /* canonical */
	Player & operator=( Player const & f );
	bool 		moveRigth();
	bool		moveLeft();
	bool		moveDown();
	bool		moveUp();

	void 		takeDamage(int damage);
};

#endif