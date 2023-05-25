/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:05:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/25 16:49:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	message_value_error(std::string value)
{
	switch (BitcoinExchange::pbValueQt(value))
	{
	case 1:
		std::cout << "Error: not a number" << std::endl;
		break;
	case 2:
		std::cout << "Error: not a positive number." << std::endl;
		break;
	default:
		std::cout << "Error: too large a number." << std::endl;
		break;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1); 
	}
	BitcoinExchange	btc("data.csv");
	std::ifstream 	input_file(argv[1]);
	std::string		line; 
	std::size_t		pos_sep;
	std::string		date;
	std::string		value;
	if (input_file.fail())
	{
		std::cout << "Error could not open file " << argv[1] << std::endl;
		return (1);
	}
	std::getline(input_file, line);
	std::getline(input_file, line);
	while (!(line.empty() && input_file.eof()))
	{
		pos_sep = line.find(" | ");
		if (pos_sep != 10 || line.size() < 14)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			std::getline(input_file, line);
			continue ;
		}
		date = line.substr(0, 10);
		value = line.substr(13, line.size() - 13);
		if (!BitcoinExchange::validDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			std::getline(input_file, line);
			continue ;
		}
		if (BitcoinExchange::pbValueQt(value))
		{
			message_value_error(value);
			std::getline(input_file, line);
			continue ;
		}
		std::cout << date << " => " << value << " = " << btc.getValue(date, value) << std::endl;
		std::getline(input_file, line);
	}
	input_file.close();
	return (0);
}