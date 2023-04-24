/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:46:25 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 16:57:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed {
public:

	Fixed(void);
	Fixed(Fixed const & copie);
	~Fixed(void);

	Fixed & operator=(Fixed const & f);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
private:
	int 				_value;
	static int const	_n_bit_fact;
	
};

#endif