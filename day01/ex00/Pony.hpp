#ifndef PONNY_HPP
# define PONNY_HPP
# include <iostream>

class Pony {
	private:
		std::string 	name;
		std::string 	phrase;
	public:
		std::string 	getName( void );
		std::string		getPhrase( void );
		void			setName( std::string name );
		void			setPhrase( std::string phrase );
		void			ponyOnTheHeap( void );
		void			ponyOnTheStack( void );
		void			say( void );
						Pony( std::string name, std::string phrase );
						Pony();
						~Pony();
};


#endif 
