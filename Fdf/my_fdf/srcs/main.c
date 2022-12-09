/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/09 18:02:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_square_img(t_data *img, t_point p, int length, t_wdim wdim)
{
	int	line;
	int	col;
	int	max_c;
	int	max_l;

	line = 0;
	max_c = p.x + length - 1;
	max_l = p.y + length - 1;
	while (line < wdim.height)
	{
		col = 0;
		while (col < wdim.width)
		{
			if ((col >= p.x && col <= max_c) && (line == p.y || line == max_l))
				my_mlx_pixel_put(img, col, line, 0xFFFFFFFF);
			if ((col == p.x || col == max_c) && (line > p.y && line < max_l))
				my_mlx_pixel_put(img, col, line, 0xFFFFFFFF);
			col++;
		}
		line++;
	}
}

void	test_fonctions(t_data *img, t_wdim wdim)
{
	t_point	point;
	t_point	p1;
	t_point	p2;
	t_seg	seg;

	point.x = 249;
	point.y = 249;
	point.color = create_trgb(0, 208, 0, 152);
	put_square_img(img, point, 50, wdim);
	put_circle_img(img, point, 200, wdim);
	p1.x = 200;
	p1.y = 500;
	p1.color = create_trgb(0, 255, 0, 0);
	p2.x = 250;
	p2.y = 20;
	p2.color = create_trgb(0, 0, 255, 0);
	seg.start = p1;
	seg.end = p2;
	put_segment_img(img, seg, wdim);
}

int	key_win(int key, void *p)
{
	(void)p;
	if (key == 0xFF1B)
		exit(0);
	return (0);
}

/*int	main(void)
{
	void	*mlx;	
	void	*mlx_win;
	t_wdim	wdim;
	t_data	img;

	wdim.width = 1800;
	wdim.height = 1000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, wdim.width, wdim.height, "FDF by mbocquel");
	img.img = mlx_new_image(mlx, wdim.width, wdim.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	test_fonctions(&img, wdim);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_win, 0);
	mlx_loop(mlx);
	return (0);
}*/
int	main(int argc, char **argv)
{
	t_map	*map;
	t_trame	*trame;
	void	*mlx;	
	void	*mlx_win;
	t_wdim	wdim;
	t_data	img;
	
	if (argc == 2)
	{
		map = parsing_fdf(argv[1]);
		if (!map && check_map(map))
		{
			ft_printf("Error with the map\n");
			return (1);
		}
		wdim.width = 1800;
		wdim.height = 1000;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, wdim.width, wdim.height, "FDF by mbocquel");
		img.img = mlx_new_image(mlx, wdim.width, wdim.height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
		test_fonctions(&img, wdim);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_key_hook(mlx_win, key_win, 0);
		print_map(map);
		trame = make_trame(map);
		ft_printf("altitude au dessus de l'origine : %d\n",get_max_high_up(map));
		ft_printf("get_px_unit_x : %d\n",get_px_unit_x(map, wdim));
		ft_printf("get_px_unit_y : %d\n",get_px_unit_y(map, wdim));
		//ft_printf("adresse de l'element (3,2) de la map %p\n", get_tram_elem(3, 2, trame));
		//ft_printf("altitude (2, 3) : %d\n",get_alt_point(2, 3, map));
		//ft_printf("nb de lignes : %d\n",get_nb_line(map));
		//ft_printf("Altitude max : %d\n",get_alt_max(map));
		//ft_printf("Altitude min : %d\n",get_alt_min(map));
		free_trame(trame);
		free_map(map);
		mlx_loop(mlx);
	
	}
	else
		ft_printf("Wrong argument number\n");
	return (0);
}