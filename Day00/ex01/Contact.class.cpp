#include "Contact.class.hpp"

std::string 	Contact::getFirstName( void ){
	return (firstName);
}

std::string 	Contact::getLastName( void ) {
	return (lastName);
}

std::string 	Contact::getNickname( void ) {
	return (nickname);
}

std::string 	Contact::getLogin( void ) {
	return (login);
}

std::string 	Contact::getPostalAddress( void ) {
	return (postalAddress);
}

std::string 	Contact::getEmailAddress( void ) {
	return (emailAddress);
}

std::string 	Contact::getPhoneNumber( void ) {
	return (phoneNumber);
}

std::string 	Contact::getBirthDayDate( void ) {
	return (birthDayDate);
}

std::string 	Contact::getFavoriteMeal( void ) {
	return (favoriteMeal);
}

std::string 	Contact::getUnderwearColor( void ) {
	return (underwearColor);
}

std::string 	Contact::getDarkestSecret( void ) {
	return (darkestSecret);
}

void			Contact::setFirstName( std::string s ) {
	this->firstName = s;
}

void 			Contact::setLastName( std::string s ) {
	this->lastName = s;
}

void 			Contact::setNickname( std::string s ) {
	this->nickname = s;
}

void 			Contact::setLogin( std::string s ) {
	this->login = s;
}

void 			Contact::setPostalAddress( std::string s ) {
	this->postalAddress = s;
}

void 			Contact::setEmailAddress( std::string s ) {
	this->emailAddress = s;
}

void 			Contact::setPhoneNumber( std::string s ) {
	this->phoneNumber = s;
}

void 			Contact::setBirthdayDate( std::string s ) {
	this->birthDayDate = s;
}

void 			Contact::setFavoriteMeal( std::string s ) {
	this->favoriteMeal = s;
}

void 			Contact::setUnderwearColor( std::string s ) {
	this->underwearColor = s;
}

void 			Contact::setDarkestSecret( std::string s ) {
	this->darkestSecret = s;
}

Contact::Contact( void ) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}
