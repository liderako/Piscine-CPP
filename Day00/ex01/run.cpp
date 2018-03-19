#include <iostream>
#include "DataBase.class.hpp"

std::string		getText( ) {
	std::string 	input;

	if ( std::getline( std::cin, input ) ) {
		return (input);
	}
	std::cout << "Error read input\n";
	std::exit(-1);
}

DataBase 	commandAdd( DataBase myBase ) {
	int count = myBase.getAmountContact();
	Contact 	tmp;
	if ( myBase.getAmountContact() > 7 ) {
		return (myBase);
	}
	std::cout << "Please, enter first name\n";
	tmp.setFirstName(getText());
	std::cout << "Please, enter last name\n";
	tmp.setLastName(getText());
	std::cout << "Please, enter nickname\n";
	tmp.setNickname(getText());
	std::cout << "Please, enter login\n";
	tmp.setLogin(getText());
	std::cout << "Please, enter postal address\n";
	tmp.setPostalAddress(getText());
	std::cout << "Please, enter email address\n";
	tmp.setEmailAddress(getText());
	std::cout << "Please, enter phone number\n";
	tmp.setPhoneNumber(getText());
	std::cout << "Please, enter birthday date\n";
	tmp.setBirthdayDate(getText());
	std::cout << "Please, enter favorite meal\n";
	tmp.setFavoriteMeal(getText());
	std::cout << "Please, enter underwear color\n";
	tmp.setUnderwearColor(getText());
	std::cout << "Please, enter darkest secret\n";
	tmp.setDarkestSecret(getText());
	// std::cout << "error";
	myBase.setBase( count, tmp );
	// std::cout << "1";
	myBase.setAmountContact( myBase.getAmountContact() + 1 );
	std::cout << "END ADD " << myBase.getAmountContact() << "\n";
	return (myBase);
}

DataBase 	chooseCommand( std::string command, DataBase myBase ) {
	if ( command == "EXIT" ) {
		myBase.setFlag(-1);
	}
	else if ( command == "ADD" ) {
		myBase = commandAdd( myBase );
	}
	else if (command == "SEARCH" ) {
		std::cout << "some code\n";
	}
	else {
		std::cout << "Unknown сommand, ";
		std::cout << "choose command [ADD] OR [SEARCH] OR [EXIT]\n";
	}
	return (myBase);
}

int main( void ) {
	DataBase 	myBase;
	std::string command;
	// int 		res;

	while ( 1 ) {
		command = getText();
		myBase = chooseCommand(command, myBase);
		if (myBase.getFlag() == -1) {
			return (1);
		}
	}
}
