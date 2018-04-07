#ifndef VECTOR2_HPP
# define VECTOR2_HPP

class Vector2 {

private:
	int x;
	int y;
public:
	Vector2(int x, int y);
	Vector2(void);
	~Vector2(void);
	void 	setX(int x);
	void 	setY(int y);
	int 	getX(void);
	int 	getY(void);
};

#endif