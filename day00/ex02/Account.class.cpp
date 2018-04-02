#include "Account.class.hpp"
#include <iostream>
 #include <ctime>

int Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_accountIndex = _totalAmount;
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";created\n";
	_totalAmount += 1;
}

Account::Account(void) {
}

Account::~Account(void) {
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";closed\n";
}

void 	Account::_displayTimestamp() {
	// time
	time_t t = time(0);
	struct tm * now = localtime( & t );
	std::cout << "[" << now->tm_year + 1900; // year
	
	// mon
	if (now->tm_mon < 10)
		std::cout << '0' << now->tm_mon;
	else
		std::cout << now->tm_mon;
	// day
	if (now->tm_mday < 10)
		std::cout << '0' << now->tm_mday << '_';
	else
		std::cout << now->tm_mday << "_";
	// hour
	if (now->tm_hour < 10)
		std::cout << '0' << now->tm_hour;
	else
		std::cout << now->tm_hour;
	// min
	if (now->tm_min < 10)
		std::cout << '0' << now->tm_min;
	else
		std::cout << now->tm_min;
	// sec
	if (now->tm_sec < 10)
		std::cout << '0' << now->tm_sec;
	else
		std::cout << now->tm_sec;
	std::cout << "] ";
}

int		Account::getNbAccounts( void ) {
	return 1;//(_nbAccounts);
}
int		Account::getTotalAmount( void ) {
	return 1;//(_totalAmount);
}
int		Account::getNbDeposits( void ) {
	return 1;//(_totalNbDeposits);
}
int		Account::getNbWithdrawals( void ) {
	return 1;//(_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void ) {
	return ;
}

void	Account::makeDeposit( int deposit ) {
	return ;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	return true;
}
int		Account::checkAmount( void ) const {
	return (1);
}
void	Account::displayStatus( void ) const {
	return ;
}