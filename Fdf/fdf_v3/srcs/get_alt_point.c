/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:43:58 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/15 17:34:30 by mbocquel         ###   ########.fr       */
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
	base_min = "0123456789abcdef";
	while (nptr[i] && nptr[i] != ',')
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
	/*if (result == 0)
		result = create_trgb(0, 255, 255, 255);*/
	return (result);
}


int	get_alt_and_color_point(int line, int col, t_map *begin_map, int *color)
{
	t_map	*elem;

	elem = begin_map;
	while (elem)
	{
		if (elem->n_line == line && col < elem->nb_col)
		{
			*color = ft_atoi_color(elem->elem_map[col]);
			if (*color > 0)
				printf("line %d, col %d, color %d\n", line, col, *color);
			return (ft_atoi(elem->elem_map[col]));
		}
		elem = elem->next;
	}
	return (0);
}
/* 
int	get_alt_point(int line, int col, t_map *begin_map)
{
	t_map	*elem;

	elem = begin_map;
	while (elem)
	{
		if (elem->n_line == line && col < elem->nb_col)
			return (elem->line_int[col]);
		elem = elem->next;
	}
	return (0);
} */
