/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:05:08 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/26 17:11:28 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB( void );
		~HumanB( void );
		HumanB( std::string name );
		void 	setWeapon( Weapon &weapon );
		void	attack( void );
};

#endif 
