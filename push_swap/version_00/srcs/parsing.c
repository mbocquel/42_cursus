/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:56:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/02 19:24:19 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_arg_error(const char *nptr, int *error)
{
	long	result;
	int		i;
	long	sng;

	i = 0;
	sng = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sng = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9' && result <= 2147483648)
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	if (sng * result < -2147483648 || sng * result > 2147483647 || nptr[i])
		*error = 1;
	if (*error == 0)
		return ((int)(sng * result));
	return (0);
}

void	parsing(char *str, t_lst_ps **pile_a, int *error)
{
	char	**str_split;
	int		i;
	int		nb_args;
	int		arg;

	nb_args = 0;
	arg = 0;
	str_split = ft_split(str, " ");
	if (str_split == NULL)
		*error = 1;
	while (*error == 0 && str_split[nb_args])
		nb_args++;
	i = nb_args - 1;
	while (*error == 0 && i >= 0)
	{
		arg = ft_atoi_arg_error(str_split[i], error);
		if (*error)
		{
			free_split(str_split, nb_args, i);
			break ;
		}
		push_front_lst(pile_a, arg, error);
		i--;
	}
	free_split(str_split, nb_args, i);
}
