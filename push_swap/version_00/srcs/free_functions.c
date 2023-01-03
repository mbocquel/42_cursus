/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:20:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i])
	{
		free(str_split[i]);
		i++;
	}
	free(str_split);
}

void	free_piles(t_pile **pile_a, t_pile **pile_b)
{
	free_unit_pile(pile_a);
	free_unit_pile(pile_b);
}

void	free_unit_pile(t_pile **pile)
{
	t_pile	*elem;
	t_pile	*temp;

	if (*pile == NULL)
		return ;
	elem = *pile;
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		free(temp);
		if (elem == *pile)
			break ;
	}
	*pile = NULL;
}
