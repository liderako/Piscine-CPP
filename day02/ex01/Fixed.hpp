/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:24:38 by asvirido          #+#    #+#             */
/*   Updated: 2018/04/02 13:49:30 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int rawBits;
		static int const decimals = 8;
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
		/* operator */
		Fixed & operator=(Fixed const & f);
};

std::ostream & operator<<(std::ostream & o, Fixed const & b);

#endif
