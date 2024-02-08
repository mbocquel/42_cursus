/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:41:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/13 11:38:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_power(int nb, int power)
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

static void	ft_init_iota(long int *pt_nbr, char *nbr_char, int *pt_i)
{
	if (*pt_nbr < 0)
	{
		*pt_nbr = -(*pt_nbr);
		nbr_char[0] = '-';
		*pt_i = 1;
	}
}

char	*ft_itoa(int n)
{
	char		*nbr_char;
	long int	nbr;
	int			i;
	int			power;

	nbr = (long int) n;
	i = 0;
	nbr_char = (char *)malloc((ft_size_nb(nbr) + 1) * sizeof(char));
	if (nbr_char == NULL)
		return (NULL);
	ft_init_iota(&nbr, nbr_char, &i);
	power = ft_size_nb(nbr)-1;
	while (power > 0)
	{
		nbr_char[i] = (nbr / ft_power(10, power)) + '0';
		nbr = nbr % ft_power(10, power);
		power--;
		i++;
	}
	nbr_char[i] = nbr + '0';
	nbr_char[i + 1] = '\0';
	return (nbr_char);
}
