#include "DataBase.class.hpp"

int 		DataBase::getAmountContact() {
	return (this->amountContact);
}

void 		DataBase::setAmountContact( int x ) {
	this->amountContact = x;
}

Contact 	DataBase::getContact( int id ) {
	return (this->base[id]);
}

int 	DataBase::getFlag( void ) {
	return (this->flag);
}

void 	DataBase::setFlag( int flag ) {
	this->flag = flag;
}

void		DataBase::setBase( int id, Contact base ) {
	this->base[id] = base;
	// this->base[id].setFirstName( base.getFirstName() );
	// // this->base[id].setLastName( base.getLastName() );
	// // this->base[id].setNickname( base.getNickname() );
	// // this->base[id].setLogin( base.getLogin() );
	// // this->base[id].setPostalAddress( base.getPostalAddress() );
	// // this->base[id].setEmailAddress( base.getEmailAddress() );
	// // this->base[id].setPhoneNumber( base.getPhoneNumber() );
	// // this->base[id].setBirthdayDate( base.getBirthDayDate() );
	// // this->base[id].setFavoriteMeal( base.getFavoriteMeal() );
	// // this->base[id].setUnderwearColor( base.getUnderwearColor() );
	// // this->base[id].setDarkestSecret( base.getDarkestSecret() );
	return ;
}

DataBase::DataBase( void ) {
	this->sizeMax = 8;
	this->amountContact = 0;
	// base[0].setLastName("a");
	// std::cout << base[0].getLastName();
	// this->base = new Contact[8;
	// this->base[0].setFirstName( "NULL" );
	return ;
}

DataBase::~DataBase( void ) {
	return ;
}
