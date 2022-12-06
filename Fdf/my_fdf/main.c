/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/06 19:13:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void	put_pix_circle_img(t_data *img, t_point p, t_point center, t_wdim wdim)
{
	if ((0 <= p.x + center.x) && (p.x + center.x < wdim.width)
		&& (0 <= p.y + center.y) && (p.y + center.y < wdim.height))
		my_mlx_pixel_put(img, p.x + center.x, p.y + center.y, p.color);
	if ((0 <= p.y + center.x) && (p.y + center.x < wdim.width)
		&& (0 <= p.x + center.y) && (p.x + center.y < wdim.height))
		my_mlx_pixel_put(img, p.y + center.x, p.x + center.y, p.color);
	if ((0 <= -p.x + center.x) && (-p.x + center.x < wdim.width)
		&& (0 <= p.y + center.y) && (p.y + center.y < wdim.height))
		my_mlx_pixel_put(img, -p.x + center.x, p.y + center.y, p.color);
	if ((0 <= -p.y + center.x) && (-p.y + center.x < wdim.width)
		&& (0 <= p.x + center.y) && (p.x + center.y < wdim.height))
		my_mlx_pixel_put(img, -p.y + center.x, p.x + center.y, p.color);
	if ((0 <= p.x + center.x) && (p.x + center.x < wdim.width)
		&& (0 <= -p.y + center.y) && (-p.y + center.y < wdim.height))
		my_mlx_pixel_put(img, p.x + center.x, -p.y + center.y, p.color);
	if ((0 <= p.y + center.x) && (p.y + center.x < wdim.width)
		&& (0 <= -p.x + center.y) && (-p.x + center.y < wdim.height))
		my_mlx_pixel_put(img, p.y + center.x, -p.x + center.y, p.color);
	if ((0 <= -p.x + center.x) && (-p.x + center.x < wdim.width)
		&& (0 <= -p.y + center.y) && (-p.y + center.y < wdim.height))
		my_mlx_pixel_put(img, -p.x + center.x, -p.y + center.y, p.color);
	if ((0 <= -p.y + center.x) && (-p.y + center.x < wdim.width)
		&& (0 <= -p.x + center.y) && (-p.x + center.y < wdim.height))
		my_mlx_pixel_put(img, -p.y + center.x, -p.x + center.y, p.color);
}

void	put_circle_img(t_data *img, t_point center, int radius, t_wdim wdim)
{
	t_point	p;
	int		m;

	p.x = 0;
	p.y = radius;
	p.color = 0xFFFFFFFF;
	m = 5 - 4 * radius;
	while (p.x <= p.y)
	{
		put_pix_circle_img(img, p, center, wdim);
		if (m > 0)
		{
			p.y = p.y - 1;
			m = m - 8 * p.y;
		}
		p.x = p.x + 1;
		m = m + 8 * p.x + 4;
	}
}

void	ft_swap_seg(t_seg *seg, t_point *delt)
{
	ft_swap(&((*seg).start.x), &((*seg).end.x));
	ft_swap(&((*seg).start.y), &((*seg).end.y));
	(*delt).x = -(*delt).x;
	(*delt).y = -(*delt).y;
}

void	put_segment_img_cas1(t_data *img, t_seg seg, t_wdim wdim)
{
	t_point	delt;
	t_point	p;
	int		inc_y;
	int		d;

	delt.x = seg.end.x - seg.start.x;
	delt.y = seg.end.y - seg.start.y;
	if (seg.start.x > seg.end.x)
		ft_swap_seg(&seg, &delt);
	inc_y = 1;
	if (delt.y < 0)
	{
		inc_y = -1;
		delt.y = -delt.y;
	}
	p = seg.start;
	d = 2 * delt.y - delt.x;
	while (p.x <= seg.end.x)
	{
		if (p.x >= 0 && p.x < wdim.width && p.y >= 0 && p.y < wdim.height)
			my_mlx_pixel_put(img, p.x, p.y, seg.start.color);
		if (d < 0)
			d += 2 * delt.y;
		else
		{
			d += 2 * (delt.y - delt.x);
			p.y += inc_y;
		}	
		(p.x)++;
	}
}

void	put_segment_img_cas2(t_data *img, t_seg seg, t_wdim wdim)
{
	t_point	delt;
	t_point	p;
	int		inc_x;
	int		d;

	delt.x = seg.end.x - seg.start.x;
	delt.y = seg.end.y - seg.start.y;
	if (seg.start.y > seg.end.y)
		ft_swap_seg(&seg, &delt);
	inc_x = 1;
	if (delt.x < 0)
	{
		inc_x = -1;
		delt.x = -delt.x;
	}
	p = seg.start;
	d = 2 * delt.x - delt.y;
	while (p.y <= seg.end.y)
	{
		if (p.x >= 0 && p.x < wdim.width && p.y >= 0 && p.y < wdim.height)
			my_mlx_pixel_put(img, p.x, p.y, seg.start.color);
		if (d < 0)
			d += 2 * delt.x;
		else
		{
			d += 2 * (delt.x - delt.y);
			p.x += inc_x;
		}
		(p.y)++;
	}
}

void	put_segment_img(t_data *img, t_seg seg, t_wdim wdim)
{
	t_point	delt;

	delt.x = seg.end.x - seg.start.x;
	delt.y = seg.end.y - seg.start.y;
	if (abs(delt.x) > abs(delt.y))
		put_segment_img_cas1(img, seg, wdim);
	else
		put_segment_img_cas2(img, seg, wdim);
}

int	main(void)
{
	void	*mlx;	
	void	*mlx_win;
	t_wdim	wdim;
	t_data	img;
	t_point	point;
	t_point	p1;
	t_point	p2;
	t_seg seg;

	wdim.width = 600;
	wdim.height = 600;
	point.x = 249;
	point.y = 249;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, wdim.width, wdim.height, "Hello world!");
	img.img = mlx_new_image(mlx, wdim.width, wdim.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	//put_square_img(&img, point, 50, wdim);
	put_circle_img(&img, point, 200, wdim);
	p1.x = 200;
	p1.y = 500;
	p1.color = 0xFFFFFFFF;
	p2.x = 10;
	p2.y = 20;
	p2.color = 0xFFFFFFFF;	
	seg.start = p1;
	seg.end = p2;
	put_segment_img(&img, seg, wdim);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
