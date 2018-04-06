#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
	private:
		std::string name;
		std::string title;
	public:
		Sorcerer( void ); /* canonical */
		Sorcerer( Sorcerer const & f ); /* canonical */
		Sorcerer(std::string name, std::string title);
		~Sorcerer( void ); /* canonical */
		/* gets */
			std::strign getName( void ) const ;
			std::strign getTitle( void ) const ;
		/* sets */
			void setName( std::string const s );
			void setTitle( std::string const s );
		/* operator */	
		Sorcerer & operator=( Sorcerer const & f ); // canonical
		// action 
void 	polymorph(Victim const &);
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & b);
#endif