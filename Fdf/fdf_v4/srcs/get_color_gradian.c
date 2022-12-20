/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_gradian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:45 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 14:02:54 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color_gradian(t_point p_s, t_point p_e, t_point p)
{
	int	col;
	int	dseg2;
	int	d2;
	int	e;

	e = 0;
	dseg2 = pow(p_e.y - p_s.y, 2) + pow(p_e.x - p_s.x, 2);
	d2 = pow(p.y - p_s.y, 2) + pow(p.x - p_s.x, 2);
	if (dseg2)
		e = (int)(sqrt(((float)d2 / (float)dseg2)) * 100);
	col = create_trgb(
			(e * get_t(p_e.color) + (100 - e) * get_t(p_s.color)) / 100,
			(e * get_r(p_e.color) + (100 - e) * get_r(p_s.color)) / 100,
			(e * get_g(p_e.color) + (100 - e) * get_g(p_s.color)) / 100,
			(e * get_b(p_e.color) + (100 - e) * get_b(p_s.color)) / 100);
	return (col);
}

int	get_color_altitude(float min, float max, float z)
{
	int		col_min;
	int		col_zero;
	int		col_max;
	int		col;
	int		e;

	e = 0;
	col_min = create_trgb(0, 0, 0, 255);
	col_zero = create_trgb(0, 0, 255, 0);
	col_max = create_trgb(0, 255, 0, 0);
	if (z > 0 && max > 0)
	{
		e = (int)(((z - 0) / (max - 0)) * 100);
		col = get_color_altitude_pos(e, col_max, col_zero);
		return (col);
	}
	if (z < 0 && min < 0)
	{
		e = (int)(((0 - z) / (0 - min)) * 100);
		col = get_color_altitude_neg(e, col_zero, col_min);
		return (col);
	}
	return (col_zero);
}

int	get_color_altitude_pos(int e, int col_max, int col_zero)
{
	int	col;

	col = create_trgb(
			(e * get_t(col_max) + (100 - e) * get_t(col_zero)) / 100,
			(e * get_r(col_max) + (100 - e) * get_r(col_zero)) / 100,
			(e * get_g(col_max) + (100 - e) * get_g(col_zero)) / 100,
			(e * get_b(col_max) + (100 - e) * get_b(col_zero)) / 100);
	return (col);
}

int	get_color_altitude_neg(int e, int col_zero, int col_min)
{
	int	col;

	col = create_trgb(
			(e * get_t(col_zero) + (100 - e) * get_t(col_min)) / 100,
			(e * get_r(col_zero) + (100 - e) * get_r(col_min)) / 100,
			(e * get_g(col_zero) + (100 - e) * get_g(col_min)) / 100,
			(e * get_b(col_zero) + (100 - e) * get_b(col_min)) / 100);
	return (col);
}
