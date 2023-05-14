/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:04 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/14 11:29:12 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <limits>  
# include <iomanip>
# include <ostream>
# include <cmath>
# include <sstream>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & sc);
	
public:
	~ScalarConverter(void);
	
	ScalarConverter & operator=(ScalarConverter const & scalar);
	
	static void	convert(std::string str);
	static void	convert_char(std::string str);
	static void convert_int(double db);
	static void	convert_float(double db);
	static void	convert_double(double db);
};


#endif