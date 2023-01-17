/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 13:20:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
/*
void free_prog(t_prog *prog)
{
	t_prog	*elem;
	t_prog	*temp;
	
	elem = prog;
	if (elem == NULL)
		return ;
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		free_split(temp->cmd_split);
		free(temp->path_prog);
		free(temp);
	}
}
*/

void	garbage_col(t_pipex *px, void *ptr)
{
	t_gar_col	*new_garb;

	if (ptr == NULL)
		return ;
	new_garb = (t_gar_col *)malloc(sizeof(t_gar_col));
	if (new_garb == NULL)
		ft_exit(px, ERROR_GARBAGE_COL);
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

int	ft_exit(t_pipex *px, int code_exit)
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
	if (code_exit % 5 == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(code_exit);
	}
	return (0);
}
