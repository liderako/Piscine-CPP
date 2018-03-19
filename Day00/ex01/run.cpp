#include <iostream>
#include "DataBase.class.hpp"

int		ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		ft_atoi(std::string s)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (ft_isdigit(s[i]) == 1)
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result);
}

size_t 	ft_strlen(std::string s) {
	size_t j = 0;
	while (s[j])
		j++;
	return (j);
}

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
		std::cout << "Too more contract. Base is full.\n";
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
	myBase.setBase( count, tmp );
	myBase.setAmountContact( myBase.getAmountContact() + 1 );
	return (myBase);
}

void 	writeOnlyTewChar( std::string s ) {
	size_t j;

	j = 0;
	while ( j < 10 ) {
		if ( j > ft_strlen(s) - 1)
			std::cout << " ";
		if ( j == 9 && ft_strlen(s) > 9 )
			std::cout << ".";
		else
			std::cout << s[j];
		j++;
	}
	std::cout << "|";
}

void 	search( DataBase myBase ) {
	int 		i;
	std::string command;
	if (myBase.getAmountContact() == 0) {
		std::cout << "No have Contact\n";
		return ;
	}
	i = 0;
	std::cout << "index     |first name|last name |nickname  |\n";
	while ( i < myBase.getAmountContact() ) {
		std::cout << i + 1 << "         |";
		Contact tmp1 = myBase.getContact(i);
		writeOnlyTewChar(tmp1.getFirstName());
		writeOnlyTewChar(tmp1.getLastName());
		writeOnlyTewChar(tmp1.getNickname());
		std::cout << "\n";
		i++;
	}
	std::cout << "Select the contract index\n";
	while (1) {
		command = getText();
		if ((ft_strlen(command)) > 1)
			std::cout << "Invalid index\n";
		else if (command[0] < '0' && command[0] > '9' ){
			std::cout << "Invalid index\n";
		}
		else if (command[0] - 48 > myBase.getAmountContact()) {
			std::cout << "Invalid index\n";
		}
		else {
			int index = command[0] - 48;
			Contact tmp1 = myBase.getContact(index - 1);
			tmp1.infoContact();
			break ;
		}
	}
	return ;
}

DataBase 	chooseCommand( std::string command, DataBase myBase ) {
	if ( command == "EXIT" ) {
		myBase.setFlag(-1);
	}
	else if ( command == "ADD" ) {
		myBase = commandAdd( myBase );
	}
	else if (command == "SEARCH" ) {
		search(myBase);
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
	while ( 1 ) {
		command = getText();
		myBase = chooseCommand(command, myBase);
		if (myBase.getFlag() == -1) {
			return (1);
		}
	}
}
