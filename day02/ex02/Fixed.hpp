/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:24:38 by asvirido          #+#    #+#             */
/*   Updated: 2018/04/02 15:50:01 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int rawBits;
		int const decimals;
	public:
		Fixed(void); /* canonical */
		Fixed(Fixed const & f); /* canonical */
		~Fixed(void); /* canonical */
		Fixed(int const x);
		Fixed(float const x);
		
		float 	toFloat(void) const;
		int		toInt(void) const;
		/* gets */
		int getRawBits(void) const;

		/* sets */
		void setRawBits( int const r );
		/* overload operators */
		Fixed & operator=(Fixed const & f);
		
		bool 	operator>(Fixed const & f) const;
		bool	operator<(Fixed const & f) const;
		bool	operator>=(Fixed const & f) const;
		bool	operator<=(Fixed const & f) const;
		bool	operator==(Fixed const & f) const;
		bool	operator!=(Fixed const & f) const;

		Fixed 	operator+(Fixed const & f) const;
		Fixed	operator-(Fixed const & f) const;
		Fixed	operator*(Fixed const & f) const;
		Fixed	operator/(Fixed const & f) const;

		Fixed	operator++(int);//post-increment
		Fixed	operator++(void);//pre-increment
		Fixed	operator--(int);//post-decrement
		Fixed	operator--(void);//pre-decrement

		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed const & max(Fixed const &a, Fixed const &b);
		static Fixed & max(Fixed &a, Fixed &b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & b);

#endif
