#include "Account.class.hpp"
#include <iostream>
 #include <ctime>

int Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";created\n";
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

Account::Account(void) {
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";closed\n";
}

void 	Account::_displayTimestamp() {
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
	return (_nbAccounts);
}
int		Account::getTotalAmount( void ) {
	return (_totalAmount);
}
int		Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}
int		Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:"<< this->_nbDeposits << '\n';
}
bool	Account::makeWithdrawal( int withdrawal ) {
	 _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused\n";
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	std::cout << '\n';
	return (true);
}
int		Account::checkAmount( void ) const {
	return (1);
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << '\n';
}