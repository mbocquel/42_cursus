/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/16 20:10:03 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **strs)
{
	
}

int	ft_exit(t_pipex *px, int code_exit)
{
	if (code_exit % 2 == 0)
	{
		free_split(px->path);
	}
	if (code_exit % 3 == 0)
	{
		free_split(px->path);
	}

}
