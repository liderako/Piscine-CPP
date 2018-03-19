#ifndef DATABASE_CLASS_H
# define DATABASE_CLASS_H
#include <iostream>
#include "Contact.class.hpp"

class DataBase {
	private:
		int 		sizeMax;
		int			amountContact;
		int			flag;
		Contact 	base[8];
	public:
		int 		getAmountContact( );
		void 		setAmountContact( int amount );
		Contact 	getBase( int id );
		void		setBase( int id, Contact base );
		int 		getFlag( void );
		void 		setFlag( int flag );
		DataBase( void );
		~DataBase( void );
};

#endif
