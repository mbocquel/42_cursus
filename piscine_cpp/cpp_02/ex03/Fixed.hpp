/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:57:56 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 19:05:13 by mbocquel         ###   ########.fr       */
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
	
	float				toFloat(void) const;
	int					toInt(void) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	static Fixed		&min(Fixed & a, Fixed &b);
	static Fixed		&max(Fixed & a, Fixed &b);
	static const Fixed	&min(Fixed const & a, Fixed const & b);
	static const Fixed	&max(Fixed const & a, Fixed const & b);

	Fixed				&operator=(Fixed const & f);
	Fixed				operator+(Fixed const & f) const;
	Fixed				operator-(Fixed const & f) const;
	Fixed				operator*(Fixed const & f) const;
	Fixed				operator/(Fixed const & f) const;
	bool				operator<(Fixed const & f) const;
	bool				operator>(Fixed const & f) const;
	bool				operator<=(Fixed const & f) const;
	bool				operator>=(Fixed const & f) const;
	bool				operator==(Fixed const & f) const;
	bool				operator!=(Fixed const & f) const;
	Fixed				&operator++(void); // pre incrementation
	Fixed				operator++(int); // post incrementation
	Fixed				&operator--(void); // pre decrementation
	Fixed				operator--(int); //post decrementation
	
private:
	int 				_value;
	static int const	_n_bit_fact;
	
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif