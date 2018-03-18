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
	firstName = s;
}

void 			Contact::setLastName( std::string s ) {
	lastName = s;
}

void 			Contact::setNickname( std::string s ) {
	nickname = s;
}

void 			Contact::setLogin( std::string s ) {
	login = s;
}

void 			Contact::setPostalAddress( std::string s ) {
	postalAddress = s;
}

void 			Contact::setEmailAddress( std::string s ) {
	emailAddress = s;
}

void 			Contact::setPhoneNumber( std::string s ) {
	phoneNumber = s;
}

void 			Contact::setBirthdayDate( std::string s ) {
	birthDayDate = s;
}

void 			Contact::setFavoriteMeal( std::string s ) {
	favoriteMeal = s;
}

void 			Contact::setUnderwearColor( std::string s ) {
	underwearColor = s;
}

void 			Contact::setDarkestSecret( std::string s ) {
	darkestSecret = s;
}

Contact::Contact( void ) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}

// class Contact {
// 	public:
// 		data[8];
//
// }
