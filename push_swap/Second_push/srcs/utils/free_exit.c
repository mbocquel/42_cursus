/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:20:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/11 17:36:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_exit(t_ps *ps, int error_code)
{
	if (error_code % 2 == 0)
	{
		free_pile(&(ps->pile_a));
		free_pile(&(ps->pile_b));
	}
	if (error_code % 3 == 0)
		free_split(ps->inst);
	if (error_code % 5 == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}

void	free_split(char **str_split)
{
	int	i;

	i = 0;
	if (str_split == NULL)
		return ;
	while (str_split[i])
	{
		free(str_split[i]);
		i++;
	}
	free(str_split);
}

void	free_pile(t_pile **pile)
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
