#include <iostream>

#ifndef FRAME_HPP
# define FRAME_HPP

class Frame {

private:
	int 	startX;
	int 	endX;
	int 	startY;
	int 	endY;
public:
	Frame(int const xStart, int const xEnd, int const yStart, int const yEnd);
	Frame(void);
	~Frame(void);
	Frame( Frame const & f ); /* canonical */
	Frame & operator=( Frame const & f ); 
	void 	setStartX(int const n);
	void 	setEndX(int const n);
	void 	setStartY(int const n);
	void 	setEndY(int const y);

	int 	getStartX(void) const;
	int 	getStartY(void) const;
	int 	getEndX(void) const;
	int 	getEndY(void) const;

	bool 	endHorizontX(int x, int y);
	bool 	endHorizontY(int x, int y);	

};

#endif