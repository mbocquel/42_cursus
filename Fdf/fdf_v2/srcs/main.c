/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 21:53:54 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_trame(t_map *map, t_wdim wdim, t_data *img)
{
	t_trame	*trame;

	trame = make_trame(map);
	apply_isometric_proj(trame);
	calculate_point_pos(trame, wdim);
	tracer_trame(img, trame, wdim);
	free_all(map, trame);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_wdim			wdim;
	t_event_param	p;

	if (argc == 2)
	{
		map = parsing_fdf(argv[1]);
		if ((!map || !check_map(map)) && ft_printf("Error with the map\n"))
			return (1);
		wdim.width = 1800;
		wdim.height = 1000;
		p.mlx_ptr = mlx_init();
		p.win_ptr = mlx_new_window(p.mlx_ptr, wdim.width,
				wdim.height, "FDF by mbocquel");
		p.img.img = mlx_new_image(p.mlx_ptr, wdim.width, wdim.height);
		p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bits_per_pixel,
				&p.img.line_length, &p.img.endian);
		process_trame(map, wdim, &p.img);
		mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img.img, 0, 0);
		mlx_key_hook(p.win_ptr, key_win, &p);
		mlx_loop(p.mlx_ptr);
	}
	else
		ft_printf("Wrong argument number\n");
	return (0);
}
