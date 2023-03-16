/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:34:22 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 18:05:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_wait(t_pipe *args, int *pids)
{
	int	i;

	i = 0;
	while (i < args->argc - 1)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}
