/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 13:42:15 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_trame(t_event_param *param)
{
	apply_isometric_proj(param);
	param->scale_factor = get_scale_factor(param->trame, param->wdim);
	param->orig = get_origin_coord(param);
	calculate_point_pos(param);
	tracer_trame(param);
}

t_event_param	initiate_img(int width, int height)
{
	t_event_param	p;

	p.mlx_ptr = mlx_init();
	if (p.mlx_ptr == NULL)
		return (p);
	p.win_ptr = mlx_new_window(p.mlx_ptr, width,
			height, "FDF by mbocquel");
	if (p.win_ptr == NULL)
	{
		free(p.win_ptr);
		return (p);
	}
	p.img.img = mlx_new_image(p.mlx_ptr, width, height);
	p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bits_per_pixel,
			&p.img.line_length, &p.img.endian);
	p.trame = NULL;
	p.wdim.width = width;
	p.wdim.height = height;
	p.scale_factor = 1;
	p.orig.xf = 0;
	p.orig.yf = 0;
	initiate_param(&p);
	return (p);
}

void	initiate_param(t_event_param *param)
{
	param->z_factor = 1;
	param->angle_x = 0;
	param->angle_y = 0;
	param->angle_z = 0;
	param->original_color = 1;
}

int	main(int argc, char **argv)
{
	t_event_param	param;
	t_trame			*trame;

	if (argc == 2)
	{
		trame = parsing_fdf(argv[1]);
		if (trame == NULL && ft_printf("Error with the map\n"))
			return (1);
		param = initiate_img(1800, 1000);
		if ((param.mlx_ptr == NULL || param.win_ptr == NULL)
			&& ft_printf("Error with the Mlx-lib\n"))
			return (1);
		param.trame = trame;
		process_trame(&param);
		mlx_key_hook(param.win_ptr, handle_key, &param);
		mlx_hook(param.win_ptr, 17, (1L << 0), close_win, &param);
		mlx_mouse_hook(param.win_ptr, handle_mouse, &param);
		mlx_loop(param.mlx_ptr);
	}
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
