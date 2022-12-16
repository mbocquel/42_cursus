/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_gradian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:45 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 22:37:09 by mbocquel         ###   ########.fr       */
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
