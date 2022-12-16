/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:40:46 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 21:22:24 by mbocquel         ###   ########.fr       */
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

int	free_line_split(char **tab_str_alt_color)
{
	int	i;

	i = 0;
	while (tab_str_alt_color[i])
	{
		free(tab_str_alt_color[i]);
		i++;
	}
	free(tab_str_alt_color);
	return (1);
}
