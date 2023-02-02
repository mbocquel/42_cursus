/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/30 13:55:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	garbage_col(t_pipex *px, void *ptr)
{
	t_gar_col	*new_garb;

	if (ptr == NULL)
		return ;
	new_garb = (t_gar_col *)malloc(sizeof(t_gar_col));
	if (new_garb == NULL)
		ft_exit(px, ERROR_MALLOC, "garbage_col -> new_garb", 0);
	new_garb->ptr = ptr;
	new_garb->next = NULL;
	if (px->garbage == NULL)
		px->garbage = new_garb;
	else
	{
		new_garb->next = px->garbage;
		px->garbage = new_garb;
	}
}

void	garbage_split(t_pipex *px, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		garbage_col(px, (void *)(strs[i]));
		i++;
	}
	garbage_col(px, (void *)strs);
}

void	empty_garbage(t_pipex *px)
{
	t_gar_col	*elem_garb;
	t_gar_col	*temp;

	elem_garb = px->garbage;
	while (elem_garb)
	{
		temp = elem_garb;
		free(elem_garb->ptr);
		elem_garb = temp->next;
		free(temp);
	}
}
