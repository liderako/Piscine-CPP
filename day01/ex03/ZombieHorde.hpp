/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:24:29 by asvirido          #+#    #+#             */
/*   Updated: 2018/03/22 18:40:06 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde {
	private:
		int count;
		Zombie *z;
		Zombie *newZombie( std::string name );
		Zombie *randomChump( void );
	public:
		ZombieHorde( size_t size);
		ZombieHorde( void );
		~ZombieHorde( void );
		void	announce( void );
};

#endif 
