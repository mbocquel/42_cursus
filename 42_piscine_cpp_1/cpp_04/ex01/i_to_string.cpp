/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_string.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:43:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:34:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_power(nb, power - 1));
}

static int	ft_size_nb(long int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static std::string	ft_c_to_string(int i)
{
	if (i == '0')
		return ("0");
	if (i == '1')
		return ("1");
	if (i == '2')
		return ("2");
	if (i == '3')
		return ("3");
	if (i == '4')
		return ("4");
	if (i == '5')
		return ("5");
	if (i == '6')
		return ("6");
	if (i == '7')
		return ("7");
	if (i == '8')
		return ("8");
	if (i == '9')
		return ("9");
	return ("");
}

std::string i_to_string(int n)
{
	std::string	nbr_string;
	long int	nbr;
	int			power;

	nbr = (long int) n;
	if (nbr < 0)
	{
		nbr = -(nbr);
		nbr_string += "-";
	}
	power = ft_size_nb(nbr)-1;
	while (power > 0)
	{
		nbr_string += ft_c_to_string((nbr / ft_power(10, power)) + '0');
		nbr = nbr % ft_power(10, power);
		power--;
	}
	nbr_string +=  ft_c_to_string(nbr + '0');
	return (nbr_string);
}