#ifndef DATABASE_CLASS_H
# define DATABASE_CLASS_H
#include <iostream>
#include "Contact.class.hpp"

class DataBase {
	private:
		int const 	sizeMax;
		int			amountContact;
		// Contact 	*base;
	public:
		int 		getAmountContact( );
		void 		setAmountContact( int amount );
		// Contact 	getBase( int id );
		// void		setBase( int id );

		DataBase( void );
		~DataBase( void );
};

#endif
