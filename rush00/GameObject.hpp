#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include "Vector2.hpp"

class GameObject {
protected:
	Vector2 	position;
	int 		speed;
	int 		symbol;
	int 		hp;
	int 		attack;
public:
	GameObject(Vector2 const & position);
	GameObject(Vector2 const & position, int speed, int symbol, int hp, int attack);
	GameObject(void);
	~GameObject(void);
	GameObject( GameObject const & f ); /* canonical */
	GameObject & operator=( GameObject const & f ); 

	Vector2 	getPosition() const ;
	int 		getSpeed() const ;
	int 		getSymbol() const ;
	int 		getHp() const ;

	void 		setHp(int const hp);
	void		setPosition(Vector2 const & p);
	void 		setSymbol(int s);

	virtual void 		takeDamage(int damage) = 0;
	virtual bool 		moveRigth() = 0;
	virtual bool		moveLeft() = 0;
	virtual bool		moveDown() = 0;
	virtual bool		moveUp() = 0;
	int 				attacks();
};

#endif