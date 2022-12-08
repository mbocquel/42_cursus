/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:40:46 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:45:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_trame(t_trame *begin_trame)
{
	t_trame	*elem;
	t_trame	*next;

	elem = begin_trame;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
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
