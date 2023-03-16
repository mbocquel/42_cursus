/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:52:19 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 11:34:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error(int n, t_pipe *args, t_fd *fd_list)
{
	if ((n >= 4 || n == 0 || n == 1) && n != 7 && n != 10)
	{
		close_fd(args, fd_list);
	}
	if (n == 2)
		ft_putendl_fd("minishell: error calloc pids", 2);
	if (n == 3)
	{
		ft_putendl_fd("minishell: error calloc fd_list", 2);
	}
	if (n == 4)
		ft_putendl_fd("minishell: error pipe", 2);
	if (n == 5)
		ft_putendl_fd("minishell: error fork", 2);
	if (n == 6)
		ft_putendl_fd("minishell: could not execve", 2);
	empty_garbage(args->prm, -1);
	exit (n);
}
