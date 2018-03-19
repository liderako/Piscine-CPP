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
	return ;
}

DataBase::DataBase( void ) {
	this->sizeMax = 8;
	this->amountContact = 0;
	return ;
}

DataBase::~DataBase( void ) {
	return ;
}
