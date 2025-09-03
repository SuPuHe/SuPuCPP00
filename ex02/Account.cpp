#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	std::cout << "Constructor: " << initial_deposit << std::endl;
}
Account::~Account(void)
{
	std::cout << "Destructor" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) { return _nbAccounts; };
int	Account::getTotalAmount( void ) { return _totalAmount; };
int	Account::getNbDeposits( void ) { return _totalNbDeposits; };
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; };

void	Account::displayAccountsInfos( void )
{
	std::cout << "displayAccountsInfos" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	std::cout << "makeDeposit: " << deposit << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << "makeWithdrawal: " << withdrawal << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return (0);
}

void	Account::displayStatus( void ) const
{
	std::cout << "displayStatus" << std::endl;
}
