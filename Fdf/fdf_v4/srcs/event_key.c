/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:46:03 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 21:15:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_win(int key, void *p)
{
	t_event_param	*param;

	param = (t_event_param *)p;
	if (key == 0xFF1B)
	{
		mlx_destroy_image(param->mlx_ptr, param->img.img);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
		exit(0);
	}
	return (0);
}
