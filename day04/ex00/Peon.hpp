#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim{
	public:
		Peon(void); /* canonical */
		Peon(Peon const & f); /* canonical */
		Peon(std::string name);
		~Peon(void); /* canonical */
		/* operator */	
		Peon & operator=( Peon const & f ); // canonical
		void	getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & o, Peon const & b);
#endif