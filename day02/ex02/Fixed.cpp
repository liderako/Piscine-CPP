#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed(void) : decimals(8) {
	this->rawBits = 0;
}

Fixed::Fixed(float const value) : decimals(8) {
	this->setRawBits(roundf(value * (float)(1 << this->decimals)));
}

Fixed::Fixed(int const value) : decimals(8) {
	this->rawBits = value << this->decimals;
}

Fixed::Fixed(Fixed const & fixed) : decimals(8) {
	*this = fixed;
}

Fixed::~Fixed(void) {
	return ;
}

float 	Fixed::toFloat(void) const {
	return ((float)this->rawBits / (float)(1 << this->decimals));
}

int 	Fixed::toInt(void) const {
	return (this->rawBits >> this->decimals);
}

int 	Fixed::getRawBits(void) const {
	return ( this->rawBits );
}

void	Fixed::setRawBits(int const rawBits) {
	this->rawBits = rawBits;
}

/* operator */
Fixed & Fixed::operator=(Fixed const & fixed) {
	this->rawBits = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & f) const {
	if (this->toFloat() > f.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & f) const {
	if (this->toFloat() < f.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & f) const {
	if (this->toFloat() >= f.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & f) const {
	if (this->toFloat() <= f.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & f) const {
	if (this->toFloat() == f.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & f) const {
	if (this->toFloat() != f.toFloat())
		return (true);
	return (false);
}


/* math */
Fixed 	Fixed::operator+(Fixed const & f) {
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed 	Fixed::operator-(Fixed const & f) {
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed 	Fixed::operator*(Fixed const & f) {
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed 	Fixed::operator/(Fixed const & f) {
	return (Fixed(this->toFloat() / f.toFloat()));
}

/* pre increment/decrement */
Fixed 	Fixed::operator++(void) {
	float 	i;

	i = (1 / (float)(1 << this->decimals));
	this->setRawBits(((this->toFloat() + i) * (1 << this->decimals)));
	return (*this);
}

Fixed 	Fixed::operator--(void) {
	float 	i;

	i = (1 / (float)(1 << this->decimals));
	this->setRawBits(((this->toFloat() - i) * (1 << this->decimals)));
	return (*this);
}

/* post increment/decrement */
Fixed 	Fixed::operator++(int) {
	float 	i;
	Fixed 	old = Fixed(*this);

	i = (1 / (float)(1 << this->decimals));
	this->setRawBits(((this->toFloat() + i) * (1 << this->decimals)));
	return (old);
}

Fixed 	Fixed::operator--(int) {
	float 	i;
	Fixed 	old = Fixed(*this);

	i = (1 / (float)(1 << this->decimals));
	this->setRawBits(((this->toFloat() - i) * (1 << this->decimals)));
	return (old);
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & b) {
	return (o << b.toFloat());
}
