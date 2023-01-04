/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:56:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 17:04:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_arg_error(const char *nptr, int *val)
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
		return (1);
	*val = (int)(sng * result);
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

void	parsing(int argc, char **argv, t_ps *ps)
{
	int		i;
	t_pile	*last;

	i = argc;
	ps->pile_a = NULL;
	ps->pile_b = NULL;
	ps->inst = NULL;
	while (--i > 0)
		parsing_arg(argv[i], ps);
	if (ps->pile_a == NULL)
		ft_exit(ps, ERROR_PARSING);
	last = last_pile_elem(ps->pile_a);
	(ps->pile_a)->prev = last;
	last->next = ps->pile_a;
	get_final_position(ps);
}

void	parsing_arg(char *str, t_ps *ps)
{
	char	**str_split;
	int		i;
	int		nb_args;
	int		val;

	nb_args = 0;
	val = 0;
	str_split = ft_split(str, " ");
	if (str_split == NULL)
		ft_exit(ps, ERROR_PARSING);
	while (str_split[nb_args])
		nb_args++;
	i = nb_args;
	while (--i >= 0)
	{
		if (ft_atoi_arg_error(str_split[i], &val)
			|| is_in_pile(ps->pile_a, val))
		{
			free_split(str_split);
			ft_exit(ps, ERROR_PARSING);
		}
		add_to_pile(ps, val);
	}
	free_split(str_split);
}
