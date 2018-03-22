#ifndef DATABASE_H
# define DATABASE_H
#include <iostream>
#include "Contact.hpp"

class DataBase {
	private:
		int 		sizeMax;
		int			amountContact;
		int			flag;
		Contact 	base[8];
	public:
		int 		getAmountContact( );
		void 		setAmountContact( int amount );
		Contact 	getContact( int id );
		void		setBase( int id, Contact base );
		int 		getFlag( void );
		void 		setFlag( int flag );
		DataBase( void );
		~DataBase( void );
};

#endif
