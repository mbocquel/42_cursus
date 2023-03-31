/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:46:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/31 11:13:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key, void *p)
{
	t_event_param	*param;

	param = (t_event_param *)p;
	if (key == KEY_ESC)
		close_win(p);
	else if (key == KEY_R)
		clear_all_change(param);
	else if (key == KEY_H || key == KEY_L)
		change_z_scale(param, key);
	else if (key == KEY_UP_ARROW || key == KEY_LOW_ARROW
		|| key == KEY_LEFT_ARROW || key == KEY_RIGHT_ARROW)
		translation(param, key);
	return (0);
}

int	close_win(void *p)
{
	t_event_param	*param;

	param = (t_event_param *)p;
	mlx_destroy_image(param->mlx_ptr, param->img.img);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	free(param->mlx_ptr);
	free_trame(param->trame);
	ft_printf("---- Goodbye, see you latter ! ----\n");
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	if (button == MOUSE_ROLL_ZOOM
		|| button == MOUSE_ROLL_UNZOOM)
		zoom_function((t_event_param *)param, button);
	return (0);
}
