/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/06 15:06:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_square_img(t_data *img, t_point p, int lenght, t_wdim wdim)
{
	int	line;
	int	col;
	int	max_c;
	int	max_l;

	line = 0;
	max_c = p.x + lenght - 1;
	max_l = p.y + lenght - 1;
	while (line < wdim.height)
	{
		col = 0;
		while (col < wdim.length)
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

void	put_circle_img(t_data *img, t_point center, int radius, t_wdim wdim)
{
	int	x;
	int	y;
	int	m;
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;

	x = 0;
	y = radius;
	m = 5 - 4 * radius;
	min_x = center.x;
	min_y = center.y;
	max_x = center.x;
	max_y = center.y;
	while (x <= y && )
	{
		if (x < wdim.lenght && y < wdim.height)
		my_mlx_pixel_put(img, x + center.x, y + center.y, 0xFFFFFFFF);
		if (x + center.x < min_x)
			min_x = x + center.x;
		if (y + center.y < min_y)
			min_y = y + center.y;
		if (x + center.x > max_x)
			max_x = x + center.x;
		if (y + center.y > max_y)
			max_y = y + center.y;
		my_mlx_pixel_put(img, y + center.x, x + center.y, 0xFFFFFFFF);
		if (y + center.x < min_x)
			min_x = y + center.x;
		if (x + center.y < min_y)
			min_y = x + center.y;
		if (y + center.x > max_x)
			max_x = y + center.x;
		if (x + center.y > max_y)
			max_y = x + center.y;
		my_mlx_pixel_put(img, -x + center.x, y + center.y, 0xFFFFFFFF);
		if (-x + center.x < min_x)
			min_x = -x + center.x;
		if (y + center.y < min_y)
			min_y = y + center.y;
		if (-x + center.x > max_x)
			max_x = -x + center.x;
		if (y + center.y > max_y)
			max_y = y + center.y;
		my_mlx_pixel_put(img, -y + center.x, x + center.y, 0xFFFFFFFF);
		if (-y + center.x < min_x)
			min_x = -y + center.x;
		if (x + center.y < min_y)
			min_y = x + center.y;
		if (-y + center.x > max_x)
			max_x = -y + center.x;
		if (x + center.y > max_y)
			max_y = x + center.y;
		my_mlx_pixel_put(img, x + center.x, -y + center.y, 0xFFFFFFFF);
		if (x + center.x < min_x)
			min_x = x + center.x;
		if (-y + center.y < min_y)
			min_y = -y + center.y;
		if (x + center.x > max_x)
			max_x = x + center.x;
		if (-y + center.y > max_y)
			max_y = -y + center.y;
		my_mlx_pixel_put(img, y + center.x, -x + center.y, 0xFFFFFFFF);
		if (y + center.x < min_x)
			min_x = y + center.x;
		if (-x + center.y < min_y)
			min_y = -x + center.y;
		if (y + center.x > max_x)
			max_x = y + center.x;
		if (-x + center.y > max_y)
			max_y = -x + center.y;
		my_mlx_pixel_put(img, -x + center.x, -y + center.y, 0xFFFFFFFF);
		if (-x + center.x < min_x)
			min_x = -x + center.x;
		if (-y + center.y < min_y)
			min_y = -y + center.y;
		if (-x + center.x > max_x)
			max_x = -x + center.x;
		if (-y + center.y > max_y)
			max_y = -y + center.y;
		my_mlx_pixel_put(img, -y + center.x, -x + center.y, 0xFFFFFFFF);
		if (-y + center.x < min_x)
			min_x = -y + center.x;
		if (-x + center.y < min_y)
			min_y = -x + center.y;
		if (-y + center.x > max_x)
			max_x = -y + center.x;
		if (-x + center.y > max_y)
			max_y = -x + center.y;
		if (m > 0)
		{
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
	printf("x_min cercle %d\n", min_x);
	printf("x_max cercle %d\n", max_x);
	printf("y_min cercle %d\n", min_y);
	printf("y_max cercle %d\n", max_y);
	
}

int	main(void)
{
	void	*mlx;	
	void	*mlx_win;
	t_wdim	wdim;
	t_data	img;
	t_point	point;

	wdim.length = 200;
	wdim.height = 200;
	point.x = 99;
	point.y = 99;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, wdim.length, wdim.height, "Hello world!");
	img.img = mlx_new_image(mlx, wdim.length, wdim.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	//put_square_img(&img, point, 50, wdim);
	put_circle_img(&img, point, 99);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
