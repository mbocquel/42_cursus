/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 10:34:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(void)
{
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & scalar)
{
	(void)scalar;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	ScalarConverter::convert_char(std::string str)
{
	std::ostringstream	os;
	char				c;

	c = str.c_str()[0];
	if (c < 32 || c > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: '" << c << "'" << std::endl;
	os << "int: " << static_cast<int>(c) << std::endl;
	std::streamsize ss = std::cout.precision();
	os << std::setprecision(1);
	os << std::setiosflags(std::ios::fixed) ;
	os << "float: " << static_cast<float>(c) << "f" << std::endl;
	os << std::setprecision(ss);
	os << std::resetiosflags(std::ios::fixed) ;
	os << "double: " << static_cast<double>(c) << std::endl;
	std::cout << os.str();
	return ;
}

void	ScalarConverter::convert_int(double db)
{
	std::ostringstream	os;
	int					i = static_cast<int>(db);
	
	if (db == static_cast<double>(i)) // Test int overflow
	{
		if (i < static_cast<int>(std::numeric_limits<char>::min()) || i > static_cast<int>(std::numeric_limits<char>::max()))
			os << "char: Impossible" << std::endl;
		else if (i < 32 || i > 126)
			os << "char: Non displayable" << std::endl;
		else
			os << "char: '" << static_cast<char>(i) << "'" << std::endl;
		os << "int: " << i << std::endl;
		os << std::setprecision(1);
		os << std::setiosflags(std::ios::fixed) ;
		os << "float: " << static_cast<float>(i) << "f" << std::endl;
		os << "double: " << static_cast<double>(i) << std::endl;
		std::cout << os.str();
		return ;
	}
	else
	{
		os << "char: int overflow, impossible conversion" << std::endl;
		os << "int: int overflow, impossible conversion" << std::endl;
		os << "float: int overflow, impossible conversion" << std::endl;
		os << "double: int overflow, impossible conversion" << std::endl;
		std::cout << os.str();
		return ;
	}
}

void	ScalarConverter::convert_float(double db, std::string str)
{
	std::ostringstream	os;
	float				f = static_cast<float>(db);
	int	precision = str.size() - 2 - str.find('.'); 

	if (std::abs(db) < std::numeric_limits<float>::min() || std::abs(db) > std::numeric_limits<float>::max())
	{
		os << "char: float overflow, impossible conversion" << std::endl;
		os << "int: float overflow, impossible conversion" << std::endl;
		os << "float: float overflow, impossible conversion" << std::endl;
		os << "double: float overflow, impossible conversion" << std::endl;
		std::cout << os.str();
		return ;
	}
	else
	{
		if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
			os << "char: Impossible" << std::endl;
		else if (static_cast<char>(f) < 32 || static_cast<char>(f) > 126)
			os << "char: Non displayable" << std::endl;
		else
			os << "char: '" << static_cast<char>(f) << "'" << std::endl;
		os << "int: " << static_cast<int>(f) << std::endl;
		os << std::setprecision(precision);
		os << std::setiosflags(std::ios::fixed) ;
		os << "float: " << f << "f" << std::endl;
		os << "double: " << static_cast<double>(f) << std::endl;
		std::cout << os.str();
		return ;
	}
}

void	ScalarConverter::convert_double(double db, std::string str)
{
	std::ostringstream	os;
	int	precision = str.size() - 1 - str.find('.'); 

	if (db < std::numeric_limits<char>::min() || db > std::numeric_limits<char>::max())
		os << "char: Impossible" << std::endl;
	else if (static_cast<char>(db) < 32 || static_cast<char>(db) > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: '" << static_cast<char>(db) << "'" << std::endl;
	os << "int: " << static_cast<int>(db) << std::endl;
	os << std::setprecision(precision);
	os << std::setiosflags(std::ios::fixed) ;
	os << "float: " << static_cast<float>(db) << "f" << std::endl;
	os << "double: " <<db << std::endl;
	std::cout << os.str();
	return ;
}

void	ScalarConverter::convert_nan(void)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	return ; 
}

void	ScalarConverter::convert_inf(bool pos)
{
	if (pos)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ; 
	}
	else
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ; 
	}
}

void		ScalarConverter::convert(std::string str)
{
	std::ostringstream	os;

	/* ------------  Test si c'est un char ----------------------- */
	if (str.size() == 1 && !isdigit(str.c_str()[0]))
	{
		ScalarConverter::convert_char(str);
		return ;
	}
	
	char	*remain = NULL;
	double	db = strtod(str.c_str(), &remain);
	std::string remain_string(remain);

	/* ------------  Test si c'est des psuedo literals ---------------- */
	if (db != db && (remain_string.empty() || remain_string == "f" || remain_string == "F")) // NAN
	{
		ScalarConverter::convert_nan();
		return ;
	}
	if (isinf(db) && (remain_string.empty() || remain_string == "f" || remain_string == "F"))
	{
		if (db < 0)
			ScalarConverter::convert_inf(false);
		else
			ScalarConverter::convert_inf(true);
		return ;
	}

	/* ------------  Test si c'est un int ----------------------- */
	if (!str.empty() && remain_string.empty() && str.find('.') == std::string::npos)
	{
		ScalarConverter::convert_int(db);
		return ;
	}
	/* ------------  Test si c'est un float ----------------------- */
	if (!str.empty() && (remain_string == "f" || remain_string == "F") && str.find('.') != std::string::npos)
	{
		ScalarConverter::convert_float(db, str);
		return ;
	}
	/* ------------  Test si c'est un double ----------------------- */
	if (!str.empty() && str.find('.') != std::string::npos && remain_string.empty())
	{
		ScalarConverter::convert_double(db, str);
		return ;
	}
	/* -----------  Si ce n'est rien de tous les cas precedents -----------------------*/
	
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

