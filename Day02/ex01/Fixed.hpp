/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:24:38 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/27 19:34:58 by asvirido         ###   ########.fr       */
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
		Fixed( void ); /* canonical */
		Fixed( Fixed const & f ); /* canonical */
		~Fixed( void ); /* canonical */
		/* gets */
			int getRawBits( void ) const ;
		/* sets */
			void setRawBits( int r );
		/* operator */	
		Fixed & operator=( Fixed const & f );

};

#endif
