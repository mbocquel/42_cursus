/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:41 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/15 14:54:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi_hex(const char *nptr)
{
	unsigned int	result;
	int				i;
	char			*base_min;

	i = 0;
	result = 0;
	base_min = "0123456789abcdef";
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && nptr[i + 1] && nptr[i] == '0'
		&& (nptr[i + 1] == 'x' || nptr[i + 1] == 'X'))
	{
		i = i + 2;
		while (nptr[i] && pos_in_base(base_min, ft_tolower(nptr[i])) != -1)
		{
			result = result * 16
				+ pos_in_base(base_min, ft_tolower(nptr[i]));
			i++;
		}
	}
	return (result);
}
