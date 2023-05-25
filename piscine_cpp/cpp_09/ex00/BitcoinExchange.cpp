/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:13:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/25 16:55:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::_verbose = false;

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
BitcoinExchange::BitcoinExchange(void)
{
	if (BitcoinExchange::_verbose)
		std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file) : _file_name(file)
{
	if (BitcoinExchange::_verbose)
		std::cout << "BitcoinExchange file constructor called" << std::endl;
	try
	{
		this->_parsing_data();
	}
	catch(const std::exception& e)
	{
		this->_data.clear();
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy)
{
	if (BitcoinExchange::_verbose)
		std::cout << "BitcoinExchange copy constructor called" << std::endl;
	this->_file_name = copy._file_name;
	this->_data = copy._data;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (BitcoinExchange::_verbose)
		std::cout << "BitcoinExchange destructor called" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & bt_cp)
{
	if (this != &bt_cp)
	{
		this->_data.clear();
		this->_data = bt_cp._data;
		this->_file_name = bt_cp._file_name;
	}
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	BitcoinExchange::_parsing_data()
{
	std::ifstream 	file_in(this->_file_name.c_str());
	std::string		line;
	std::size_t		pos_sep = std::string::npos;
	std::string		date;
	std::string		value;
	
	if (file_in.fail())
		throw CannotOpenFile();
	
	std::getline(file_in, line);//first line to ignore
	std::getline(file_in, line);
	while (!(line.empty() && file_in.eof()))
	{
		pos_sep = line.find(",");
		if (pos_sep != 10 || line.size() < 12)
		{
			this->_data.clear();
			std::cout << "Error: bad input => " << line << std::endl;
			break;		
		}
		date = line.substr(0, 10);
		value = line.substr(11, line.size() - 10);
		if (!BitcoinExchange::validDate(date) || !BitcoinExchange::validValueBitcoin(value))
		{
			this->_data.clear();
			std::cout << "Error: bad input => " << line << std::endl;
			break;
		}
		this->_data.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
		std::getline(file_in, line);
	}
	file_in.close();
}

double	BitcoinExchange::getValue(std::string date, std::string quantity) const
{	
	std::pair<std::string, double> exchange = *(--this->_data.upper_bound(date));
	double	qt = strtod(quantity.c_str(), NULL);
	return (qt * exchange.second);
}

bool	BitcoinExchange::validDate(std::string date)
{
	if (date.size() != 10 || date.at(4) != '-' || date.at(7) != '-')
		return (false);
	double		year = strtod(date.substr(0, 4).c_str(), NULL);
	double		month = strtod(date.substr(5, 2).c_str(), NULL);
	double		day = strtod(date.substr(8, 2).c_str(), NULL);
	if (year < 2009 || static_cast<double>(static_cast<int>(year)) != year)
		return (false);
	if (month < 1 || month > 12 || static_cast<double>(static_cast<int>(month)) != month)
		return (false);
	if (day < 1 || day > 31 || static_cast<double>(static_cast<int>(day)) != day)
		return (false);
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2 && !BitcoinExchange::leapYear(static_cast<int>(year)) && day > 28)
		return (false);
	if (month == 2 && BitcoinExchange::leapYear(static_cast<int>(year)) && day > 29)
		return (false);
	return (true);
}

bool	BitcoinExchange::validValueBitcoin(std::string value_str)
{
	char		*remain = NULL;
	double		value_db = strtod(value_str.c_str(), &remain);
	std::string	remain_str(remain);

	if (!remain_str.empty() || value_db < 0)
		return (false);
	return (true);
}

int	BitcoinExchange::pbValueQt(std::string value_str)
{
	char		*remain = NULL;
	double		value_db = strtod(value_str.c_str(), &remain);
	std::string	remain_str(remain);
	
	if (!remain_str.empty())
		return (1);
	if (value_db < 0)
		return (2);
	if (value_db >= 2147483648)
		return (3);
	return (0);
}

bool	BitcoinExchange::leapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return (true);
			else
				return (false);
		}
		else
			return (true);
	}
	else
		return (false);
}

void	BitcoinExchange::seeData(std::ostream & o) const
{
	std::map<std::string, double>::const_iterator 	it = this->_data.begin();
	std::map<std::string, double>::const_iterator	ite = this->_data.end();
	
	while (it != ite)
	{
		o << it->first << " | " << it->second << std::endl;
		++it;
	}
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */
const char* BitcoinExchange::CannotOpenFile::what() const throw()
{
	return ("Error: could not open file.");
}
