#ifndef VECTOR2_HPP
# define VECTOR2_HPP

class Vector2 {

private:
	int x;
	int y;
public:
	Vector2(int const x, int const y);
	Vector2(void);
	~Vector2(void);
	Vector2( Vector2 const & f ); /* canonical */
	Vector2 & operator=( Vector2 const & f ); 
	void 	setX(int const x);
	void 	setY(int const y);
	int 	getX(void) const ;
	int 	getY(void) const ;
};

#endif