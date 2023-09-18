/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:35:02 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/10 12:45:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_pipex(t_pipe *args, int **pids, t_fd **fd_list)
{
	*pids = ft_calloc_gc(args->prm, args->prm->source.id,
			args->argc + 1, sizeof(**pids));
	if (*pids == NULL)
		ft_error(2, args, NULL);
	*fd_list = ft_calloc_gc(args->prm, args->prm->source.id,
			args->argc + 2, sizeof(**fd_list));
	if (*fd_list == NULL)
		ft_error(3, args, *fd_list);
}

void	init_pipes(t_pipe *args, t_fd *fd_list)
{
	int	i;

	i = 0;
	while (i < args->argc + 1)
	{
		if (pipe((fd_list[i]).fd) == -1)
			ft_error(4, args, fd_list);
		i++;
	}
}
