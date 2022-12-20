/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:46:03 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 16:04:18 by mbocquel         ###   ########.fr       */
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
		colorise(param);
	else if (key == KEY_R)
		clear_all_change(param);
	else if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate_trame(param, key);
	else if (key == KEY_H || key == KEY_L)
		change_z_scale(param, key);
	else if (key == KEY_UP_ARROW || key == KEY_LOW_ARROW
		|| key == KEY_LEFT_ARROW || key == KEY_RIGHT_ARROW)
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
	ft_printf("---- Goodbye, see you latter ! ----\n");
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	if (button == MOUSE_ROLL_ZOOM
		|| button == MOUSE_ROLL_UNZOOM)
		zoom_function((t_event_param *)param, button);
	if (button == 1)
		focus_point((t_event_param *)param, x, y);
	return (0);
}

void	colorise(t_event_param *param)
{
	if (param->original_color == 1)
	{
		ft_printf("---- Colors changed ----\n");
		tracer_trame_color(param);
		param->original_color = 0;
	}
}
