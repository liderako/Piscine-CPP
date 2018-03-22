/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:33:38 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/22 18:05:43 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent {
	private:
		std::string type;
		int count;
	public:
		ZombieEvent( void );
		~ZombieEvent( void );
		
		void 	setZombieType( std::string type );
		Zombie	*newZombie( std::string name );
		Zombie	*randomChump( void );
};

#endif 
