/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/07 18:29:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	garbage_col(t_param *param, void *ptr)
{
	t_gar_col	*new_garb;

	if (ptr == NULL)
		return (1);
	new_garb = (t_gar_col *)malloc(sizeof(t_gar_col));
	if (new_garb == NULL)
	{
		param->error = 1;
		return (1);
	}
	new_garb->ptr = ptr;
	new_garb->next = NULL;
	if (param->garb == NULL)
		param->garb = new_garb;
	else
	{
		new_garb->next = param->garb;
		param->garb = new_garb;
	}
	return (0);
}

void	empty_garbage(t_param *param)
{
	t_gar_col	*elem_garb;
	t_gar_col	*temp;

	elem_garb = param->garb;
	while (elem_garb)
	{
		temp = elem_garb;
		free(elem_garb->ptr);
		elem_garb = temp->next;
		free(temp);
	}
}

