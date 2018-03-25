/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:08 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/22 19:51:24 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {
	private:
		std::string 	name;
		std::string		type;

	public:
						Zombie( void );
						Zombie( Zombie const & zombie);
						Zombie( std::string name, std::string type );
						~Zombie( void );
		void 			announce( void );
		void			setName( std::string name );
		void			setType( std::string type );
		std::string		getName( void ) const ;
		std::string		getType( void ) const ;
		Zombie & 		operator=(Zombie const & z);
};

#endif
