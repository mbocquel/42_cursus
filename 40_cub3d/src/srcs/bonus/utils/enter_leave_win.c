/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_leave_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:05:59 by mbocquel          #+#    #+#             */
/*   Updated: 2024/02/08 17:13:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	enter_window(void *p)
{
	t_param	*prm;

	prm = (t_param *)p;
	prm->in_focus = 1;
	mlx_mouse_hide(prm->mlx, prm->win);
	return (0);
	(void)p;
	(void)prm;
}

int	leave_window(void *p)
{
	t_param	*prm;

	prm = (t_param *)p;
	prm->in_focus = 0;
	mlx_mouse_show(prm->mlx, prm->win);
	(void)p;
	return (0);
}
