/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:56:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
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

t_pile	*last_pile_elem(t_pile *lst)
{
	t_pile	*elem;

	if (!lst || !(lst->next))
		return (lst);
	elem = lst;
	while (elem)
	{
		if (elem->next == NULL)
			return (elem);
		else
			elem = elem->next;
	}
	return (elem);
}

t_pile	*parsing(int argc, char **argv, int *error)
{
	int			i;
	t_pile	*pile_a;
	t_pile	*last;

	pile_a = NULL;
	i = argc;
	while (--i > 0 && *error == 0)
		parsing_arg(argv[i], &pile_a, error);
	if (pile_a == NULL || *error)
	{
		free_unit_pile(&pile_a);
		return (NULL);
	}
	last = last_pile_elem(pile_a);
	pile_a->prev = last;
	last->next = pile_a;
	return (pile_a);
}

void	parsing_arg(char *str, t_pile **pile_a, int *error)
{
	char	**str_split;
	int		i;
	int		nb_args;
	int		val;

	nb_args = 0;
	val = 0;
	str_split = ft_split(str, " ");
	if (str_split == NULL)
		*error = 1;
	while (*error == 0 && str_split[nb_args])
		nb_args++;
	i = nb_args;
	while (*error == 0 && --i >= 0)
	{
		val = ft_atoi_arg_error(str_split[i], error);
		if (is_in_pile(*pile_a, val))
			*error = 1;
		if (*error == 0)
			push_front_lst(pile_a, val, error);
	}
	free_split(str_split);
}
