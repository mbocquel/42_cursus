/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:45 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/19 12:43:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_prog2(t_pipex *px)
{
	t_gar_col	*garb;

	ft_printf("\nGarbage \n");
	garb = px->garbage;
	while (garb)
	{
		ft_printf("	garbage %p\n", garb->ptr);
		garb = garb->next;
	}
}

void	print_prog(t_pipex *px)
{
	int			i;
	t_cmd		*c;

	ft_printf("Path Env\n");
	i = -1;
	while ((px->path_env)[++i])
		ft_printf("path: %s - %p\n", (px->path_env)[i], (px->path_env)[i]);
	ft_printf("\nCmd \n");
	c = px->cmd;
	while (c)
	{
		i = 0;
		ft_printf("ptr cmd_split : %p\n", c->cmd_split);
		while (c->cmd_split[i])
		{
			ft_printf("%d: %s - %p\n", i, (c->cmd_split)[i], (c->cmd_split)[i]);
			i++;
		}
		c = c->next;
	}
	print_prog2(px);
}
