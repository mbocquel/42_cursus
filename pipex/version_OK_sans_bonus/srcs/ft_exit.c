/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/19 13:26:10 by mbocquel         ###   ########.fr       */
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
		ft_exit(px, ERROR_MALLOC, "garbage_col", "new_garb");
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

int	ft_exit(t_pipex *px, int code_exit, char *str1, char *str2)
{
	if (code_exit == ERROR_MALLOC)
		ft_printf_fd(2,
			"Error: memory allocaton problem in %s --> %s\n", str1, str2);
	if (code_exit == ERROR_ARG_NUM)
	{
		ft_printf_fd(2, "Error: number of argument. ");
		ft_printf_fd(2, "Usage: %s file1 \"cmd1\" \"cmd2\" file2\n", str1);
	}
	if (code_exit == ERROR_PERROR)
		ft_printf_fd(2, "Error: %s: %s\n", strerror(errno), str2);
	if (code_exit == ERROR_CMD_NOT_FOUND)
		ft_printf_fd(2, "Error: command not found: %s\n", str1);
	empty_garbage(px);
	if (code_exit == 0)
		exit(0);
	else
		exit(EXIT_FAILURE);
}
