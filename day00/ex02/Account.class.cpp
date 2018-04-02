#include "Account.class.hpp"
#include <iostream>

int Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	// std::cout << Account::_totalAmount << "\n";
	// _nbAccounts = 0;
	// std::cout << getNbAccounts();
	this->_accountIndex = _totalAmount;
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";created\n";
	_totalAmount += 1;
}

Account::Account(void) {
	// _totalAmount = 0;
}

Account::~Account(void) {
	std::cout << "index:" << this->_accountIndex << ";amount:" <<  this->_amount << ";closed\n";
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