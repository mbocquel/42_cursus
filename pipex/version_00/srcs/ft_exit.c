/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 00:02:52 by mbocquel         ###   ########.fr       */
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

int	ft_exit(t_pipex *px, int code_exit)
{
	if (code_exit % 2 == 0)
	{
		free_split(px->path_env);
	}
	if (code_exit % 3 == 0)
	{
		free_split(px->name);
		free_split(px->path_prog);
		free_split(px->cmd);
	}
	if (code_exit % 5 == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(code_exit);
	}
	return (0);
}
