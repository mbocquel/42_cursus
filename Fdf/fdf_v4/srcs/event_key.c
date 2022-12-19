/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:46:03 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 22:31:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key, void *p)
{
	t_event_param	*param;

	param = (t_event_param *)p;
	if (key == KEY_ESC)
		close_win(p);
	else if (key == KEY_C)
	{
		tracer_trame_color(param);
		param->original_color = 0;
		ft_printf("---- Colors changed ----\n");
	}
	else if (key == KEY_R)
	{
		clear_img(param);
		param->z_factor = 1;
		apply_isometric_proj(param->trame, param->z_factor);
		param->scale_factor = get_scale_factor(param->trame, param->wdim);
		param->orig = get_origin_coord(param->trame);
		calculate_point_pos(param);
		tracer_trame(param);
		param->original_color = 1;
		ft_printf("---- All changes cleared ----\n");
	}
	else if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate_trame(param, key);
	else if (key == KEY_H || key == KEY_L)
		change_z_scale(param, key);
	else if (key == KEY_UP_ARROW || key == KEY_LOW_ARROW || key == KEY_LEFT_ARROW || key == KEY_RIGHT_ARROW)
		translation(param, key);
	else
		print_command_list();
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
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	if (button == MOUSE_ROLL_ZOOM)
		zoom_function((t_event_param *)param, x, y);
	if (button == MOUSE_ROLL_UNZOOM)
		unzoom_function((t_event_param *)param, x, y);
	if (button == 1)
		focus_point((t_event_param *)param, x, y);
	return (0);
}