/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:20:14 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/07 12:10:07 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pix_circle_img(t_data *img, t_point p, t_point cen, t_wdim wdim)
{
	if ((0 <= p.x + cen.x) && (p.x + cen.x < wdim.width)
		&& (0 <= p.y + cen.y) && (p.y + cen.y < wdim.height))
		my_mlx_pixel_put(img, p.x + cen.x, p.y + cen.y, p.color);
	if ((0 <= p.y + cen.x) && (p.y + cen.x < wdim.width)
		&& (0 <= p.x + cen.y) && (p.x + cen.y < wdim.height))
		my_mlx_pixel_put(img, p.y + cen.x, p.x + cen.y, p.color);
	if ((0 <= -p.x + cen.x) && (-p.x + cen.x < wdim.width)
		&& (0 <= p.y + cen.y) && (p.y + cen.y < wdim.height))
		my_mlx_pixel_put(img, -p.x + cen.x, p.y + cen.y, p.color);
	if ((0 <= -p.y + cen.x) && (-p.y + cen.x < wdim.width)
		&& (0 <= p.x + cen.y) && (p.x + cen.y < wdim.height))
		my_mlx_pixel_put(img, -p.y + cen.x, p.x + cen.y, p.color);
	if ((0 <= p.x + cen.x) && (p.x + cen.x < wdim.width)
		&& (0 <= -p.y + cen.y) && (-p.y + cen.y < wdim.height))
		my_mlx_pixel_put(img, p.x + cen.x, -p.y + cen.y, p.color);
	if ((0 <= p.y + cen.x) && (p.y + cen.x < wdim.width)
		&& (0 <= -p.x + cen.y) && (-p.x + cen.y < wdim.height))
		my_mlx_pixel_put(img, p.y + cen.x, -p.x + cen.y, p.color);
	if ((0 <= -p.x + cen.x) && (-p.x + cen.x < wdim.width)
		&& (0 <= -p.y + cen.y) && (-p.y + cen.y < wdim.height))
		my_mlx_pixel_put(img, -p.x + cen.x, -p.y + cen.y, p.color);
	if ((0 <= -p.y + cen.x) && (-p.y + cen.x < wdim.width)
		&& (0 <= -p.x + cen.y) && (-p.x + cen.y < wdim.height))
		my_mlx_pixel_put(img, -p.y + cen.x, -p.x + cen.y, p.color);
}

void	put_circle_img(t_data *img, t_point center, int radius, t_wdim wdim)
{
	t_point	p;
	int		m;

	p.x = 0;
	p.y = radius;
	p.color = center.color;
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
