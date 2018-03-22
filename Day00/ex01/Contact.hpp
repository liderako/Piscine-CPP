#ifndef CONTRACT_H
# define CONTRACT_H
#include <iostream>

class Contact {
	private:
		std::string 	firstName;
		std::string 	lastName;
		std::string 	nickname;
		std::string 	login;
		std::string 	postalAddress;
		std::string 	emailAddress;
		std::string 	phoneNumber;
		std::string		birthDayDate;
		std::string		favoriteMeal;
		std::string		underwearColor;
		std::string		darkestSecret;
	public:
		std::string		getFirstName( void );
		std::string 	getLastName( void );
		std::string 	getNickname( void );
		std::string 	getLogin( void );
		std::string 	getPostalAddress( void );
		std::string 	getEmailAddress( void );
		std::string 	getPhoneNumber( void );
		std::string 	getBirthDayDate( void );
		std::string 	getFavoriteMeal( void );
		std::string 	getUnderwearColor( void );
		std::string 	getDarkestSecret( void );
		void			setFirstName( std::string );
		void 			setLastName( std::string );
		void 			setNickname( std::string );
		void 			setLogin( std::string );
		void 			setPostalAddress( std::string );
		void 			setEmailAddress( std::string );
		void 			setPhoneNumber( std::string );
		void 			setBirthdayDate( std::string );
		void 			setFavoriteMeal( std::string );
		void 			setUnderwearColor( std::string );
		void 			setDarkestSecret( std::string );
		void 			infoContact();
		Contact( void );
		~Contact( void );
};

#endif
