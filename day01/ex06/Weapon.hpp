/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:26:52 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/26 16:53:35 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string 	type;
	public:
		std::string	&	getType( void ) const ;
		void			setType( std::string );
		Weapon( void );
		~Weapon( void );
		Weapon( std::string type );
};
#endif
