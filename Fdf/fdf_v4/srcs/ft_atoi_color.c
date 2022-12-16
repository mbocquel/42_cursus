/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:18 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 21:13:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pos_in_base(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_color(const char *nptr)
{
	unsigned int	result;
	int				i;
	char			*base_min;

	i = 0;
	result = 0;
	base_min = "0123456789ABCDEF";
	while (nptr[i] && nptr[i] != 'x')
		i++;
	while (nptr[++i] && pos_in_base(base_min, nptr[i]) != -1)
	{
		result = result * 16
			+ pos_in_base(base_min, nptr[i]);
	}
	return (result);
}
