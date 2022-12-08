/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:47:36 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:17:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *begin_map)
{
	t_map	*elem;
	int		i;

	elem = begin_map;
	while (elem)
	{
		i = -1;
		while (++i < elem->nb_col)
			ft_printf("%d\t", elem->line_int[i]);
		ft_printf("\n");
		elem = elem->next;
	}
}

int	check_map(t_map *begin_map)
{
	t_map	*elem;
	int		nb_col;

	elem = begin_map;
	if (elem)
		nb_col = elem->nb_col;
	while (elem)
	{
		if (nb_col != elem->nb_col)
			return (0);
		elem = elem->next;
	}
	return (1);
}

void	free_map(t_map *begin_map)
{
	t_map	*elem;
	t_map	*next;

	elem = begin_map;
	while (elem)
	{
		next = elem->next;
		free(elem->line_int);
		free(elem);
		elem = next;
	}
}

void	free_tab_char(char **line_tab_char)
{
	int	i;

	i = 0;
	while (line_tab_char[i])
	{
		free(line_tab_char[i]);
		i++;
	}
	free(line_tab_char);
}
