#include <iostream>
#include "Fixed.hpp"

int		main()
{
	Fixed		a;
	Fixed const	b ( Fixed( 5.05f ) * Fixed( 2 ));
	Fixed const	c ( 5.05f );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	 std::cout << Fixed::max( a, b) << std::endl;
	 std::cout << Fixed::min( a, b) << std::endl;
	 std::cout << Fixed::max( b, c) << std::endl;
	 std::cout << Fixed::min( b, c) << std::endl;

	return 0;
}
