/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:52:38 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 18:00:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_fd(t_pipe *args, t_fd *fd_list)
{
	int	i;

	i = 0;
	while (i < args->argc + 1)
	{
		close(fd_list[i].fd[0]);
		close(fd_list[i].fd[1]);
		i++;
	}
}
