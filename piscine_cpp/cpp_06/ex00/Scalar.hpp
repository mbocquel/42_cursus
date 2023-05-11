/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:04 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/11 16:33:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP
# include <iostream>
# include <string>
# include <cstdlib>

class Scalar
{
private:
	char			_char;
	int				_int;
	float			_float;
	double			_double;
	static	bool	_verbose;
	Scalar(void);
	
public:
	Scalar(const char *str);
	Scalar(Scalar const & copy);
	~Scalar(void);
	
	Scalar & operator=(Scalar const & scalar);
	
	char		getChar(void) const;
	int			getInt(void) const;
	float		getFloat(void) const;
	double		getDouble(void) const;
};

std::ostream & operator<<(std::ostream & o, Scalar const & scalar);

#endif