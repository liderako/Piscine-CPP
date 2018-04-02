#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed(void) : decimals(8) {
	std::cout << "Default constructor called" << "\n";
	this->rawBits = 0;
}

Fixed::Fixed(float const value) : decimals(8) {
	this->setRawBits(roundf(value * (float)(1 << this->decimals)));
}

Fixed::Fixed(int const value) : decimals(8) {
	this->rawBits = value << this->decimals;
}

Fixed::Fixed(Fixed const & fixed) : decimals(8) {
	std::cout << "Copy constructor called" << "\n";
	*this = fixed;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << "\n";
	return ;
}

float 	Fixed::toFloat(void) const {
	return ((float)this->rawBits / (float)(1 << this->decimals));
}

int 	Fixed::toInt(void) const {
	return (this->rawBits >> this->decimals);
}

int 	Fixed::getRawBits(void) const {
 	std::cout << "getRawBits member function called" << "\n";
	return ( this->rawBits );
}

void	Fixed::setRawBits(int const rawBits) {
    std::cout << "setRawBits member function called" << "\n";
	this->rawBits = rawBits;
}

/* operator */
Fixed & Fixed::operator=(Fixed const & fixed) {
	std::cout << "Assignation operator called" << "\n";
	this->rawBits = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & f) {
	return (true);
}

bool	Fixed::operator<(Fixed const & f) {
	return (true);
}

bool	Fixed::operator>=(Fixed const & f) {
	return (true);
}

bool	Fixed::operator<=(Fixed const & f) {
	return (true);
}

bool	Fixed::operator==(Fixed const & f) {
	return (true);
}

bool	Fixed::operator!=(Fixed const & f) {
	return (true);
}


/* math */
Fixed 	Fixed::operator+(Fixed const & f) {
	// code
}

Fixed 	Fixed::operator-(Fixed const & f) {
	// code
}

Fixed 	Fixed::operator*(Fixed const & f) {
	// code
}

Fixed 	Fixed::operator/(Fixed const & f) {
	// code
}

std::ostream & operator<<(std::ostream & o, Fixed const & b) {
	return (o << b.toFloat());
}
