/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:57:56 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 16:57:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed {
public:

	Fixed(void);
	Fixed(int const val_int);
	Fixed(float const val_float);
	Fixed(Fixed const & copie);
	~Fixed(void);
	
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed & operator=(Fixed const & f);
	
private:
	int 				_value;
	static int const	_n_bit_fact;
	
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif