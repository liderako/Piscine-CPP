#ifndef BULLET_HPP
#define BULLET_HPP
#include <iostream>
#include "GameObject.hpp"
#include "Frame.hpp"

class Asteroid : public GameObject{
private:
	Frame frame;
public:
	Asteroid(int xSpawn, int ySpawn);
	Asteroid(void);
	~Asteroid(void);
	Asteroid( Asteroid const & f ); /* canonical */
	Asteroid & operator=( Asteroid const & f );
	bool 		moveRigth();
	bool		moveLeft();
	bool		moveDown();
	bool		moveUp();
	void 		takeDamage(int damage);
	void		dead(void);
	void 		setPosX(int const x);
	void 		setPosY(int const x);
};

#endif