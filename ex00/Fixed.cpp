#include "Fixed.hpp"

Fixed::Fixed( void ) : decimals(8) {
	std::cout << "Default constructor called" << "\n";
	this->rawBits = 0;
}

Fixed::Fixed( Fixed const & fixed) : decimals(8) {
	std::cout << "Copy constructor called" << "\n";
	*this = fixed;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << "\n";
	return ;
}

Fixed & Fixed::operator=( Fixed const & fixed ) {
	std::cout << "Assignation operator called" << "\n";
	this->rawBits = fixed.getRawBits();
	return *this;
}

int 	Fixed::getRawBits( void ) const {
 	std::cout << "getRawBits member function called" << "\n";
	return ( this->rawBits );
}

void	Fixed::setRawBits( int rawBits ) {
    std::cout << "setRawBits member function called" << "\n";
	this->rawBits = rawBits;
}
