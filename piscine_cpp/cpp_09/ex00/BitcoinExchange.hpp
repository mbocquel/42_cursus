/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:13:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/29 15:20:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <string>
# include <map>
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <utility>

class BitcoinExchange
{
private:
	static bool						_verbose;
	std::map<std::string, double>	_data;
	std::string						_file_name;
	void							_parsing_data();
	bool							_file_ok;
	BitcoinExchange(void);

public:
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange & copy);
	~BitcoinExchange(void);

	BitcoinExchange & operator=(BitcoinExchange const & bt_cp);

	double			getValue(std::string date, std::string quantity) const;
	static bool		validDate(std::string date);
	static bool		validValueBitcoin(std::string value_str);
	static int		pbValueQt(std::string value_str);
	static bool		leapYear(int year);
	void			seeData(std::ostream & o) const;
	bool			getFileOk(void) const;

	class CannotOpenFile : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


#endif