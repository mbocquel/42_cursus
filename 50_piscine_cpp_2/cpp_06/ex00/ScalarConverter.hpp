/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:04 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/14 12:41:32 by mbocquel         ###   ########.fr       */
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
# include <math.h>
# include <sstream>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & sc);
	static void	convert_char(std::string str);
	static void convert_int(double db);
	static void	convert_float(double db, std::string str);
	static void	convert_double(double db, std::string str);
	static void	convert_nan(void);
	static void	convert_inf(bool pos);
	
public:
	~ScalarConverter(void);
	
	ScalarConverter & operator=(ScalarConverter const & scalar);
	
	static void	convert(std::string str);
	
};


#endif