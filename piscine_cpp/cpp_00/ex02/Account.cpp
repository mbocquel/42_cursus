/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:09:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/21 17:45:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/* Variables de class */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructeur et destructeur */
Account::Account( void ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) :
_amount(initial_deposit), 
_nbDeposits(0), 
_nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account( void )
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

/* Fonctions public de class */

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
	<< "total:" << Account::_totalAmount << ";"
	<< "deposits:" << Account::_totalNbDeposits << ";"
	<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/* Fonctions d'instance publiques  */

void	Account::makeDeposit(int deposit)
{
	int	p_amount;
	
	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" <<this->_accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;
	
	p_amount = this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout << "index:" <<this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		this->_amount -= withdrawal;
		Account::_displayTimestamp();
		std::cout << "index:" <<this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* Fonctions d'instance privee */

void	Account::_displayTimestamp(void)
{
	time_t	rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	std::cout << "["<< timeinfo->tm_year + 1900;
	if (timeinfo->tm_mon < 9)
		std::cout << "0";
	std::cout << timeinfo->tm_mon + 1 << timeinfo->tm_mday << "_"
	<< timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "] ";
	//std::cout << "[19920104_091532] ";
}
