/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:36:57 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/26 16:51:32 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

	private:
		std::string name;
		Weapon 		weapon;
	public:
		HumanA( void );
		~HumanA( void );
		HumanA( std::string name, Weapon &w);
		void	attack( );
};

#endif
