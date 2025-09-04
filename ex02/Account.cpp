#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << CYAN << "index:" << _accountIndex << ";amount:"
			<< checkAmount() << ";created" << RESET << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << RED << "index:" << _accountIndex << ";amount:"
			<< checkAmount() << ";closed" << RESET << std::endl;
}


int	Account::getNbAccounts( void ) { return _nbAccounts; };
int	Account::getTotalAmount( void ) { return _totalAmount; };
int	Account::getNbDeposits( void ) { return _totalNbDeposits; };
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; };

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << GREEN << "accounts:" << _nbAccounts << ";total:"
			<< _totalAmount << ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << RESET << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
			<< _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << checkAmount()
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:"
				<< _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals += _nbWithdrawals;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	std::cout << ";amount:" << checkAmount()
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const { return _amount; };

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << MAGENTA << "index:" << _accountIndex << ";total:"
			<< _amount << ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << RESET << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(0);
	struct tm	ltm = *std::localtime(&now);

	std::cout << "[" << 1900 + ltm.tm_year <<
	std::setfill('0') << std::setw(2) << 1 + ltm.tm_mon <<
	std::setfill('0') << std::setw(2) << ltm.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << ltm.tm_hour <<
	std::setfill('0') << std::setw(2) << ltm.tm_min <<
	std::setfill('0') << std::setw(2) << ltm.tm_sec <<
	"] ";
}
