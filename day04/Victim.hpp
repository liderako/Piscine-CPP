#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim {
	private:
		std::string name;
	public:
		Victim( void ); /* canonical */
		Victim( Victim const & f ); /* canonical */
		Victim(std::string name, std::string title);
		~Victim( void ); /* canonical */
		/* gets */
			std::strign getName( void ) const ;
		/* sets */
			void setName( std::string const s );
		/* operator */	
		Victim & operator=( Victim const & f ); // canonical
		// action
		void 	getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & o, Victim const & b);
#endif