/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:11:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 19:19:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(45.65f);
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;

	c = a;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a < c: " << (a < c) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a > c: " << (a > c) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a <= c: " << (a <= c) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a >= c: " << (a >= c) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a != c: " << (a != c) << std::endl;
	
	return (0);
}
/*
int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}*/
