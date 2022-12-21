/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:12 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 23:00:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d_fl	prod_mat3x2_p3d(t_mat3x2 mat, t_point_3d point_3d)
{
	t_point2d_fl	point;

	point.xf = mat.l1[0] * point_3d.x_3d + mat.l1[1]
		* point_3d.y_3d + mat.l1[2] * point_3d.z_3d;
	point.yf = mat.l2[0] * point_3d.x_3d + mat.l2[1]
		* point_3d.y_3d + mat.l2[2] * point_3d.z_3d;
	return (point);
}

t_point_3d	prod_mat3x3_p3d(t_mat3x3 mat, t_point_3d p_3d)
{
	t_point_3d	result;

	result.x_3d = mat.l1[0] * p_3d.x_3d + mat.l1[1] * p_3d.y_3d
		+ mat.l1[2] * p_3d.z_3d;
	result.y_3d = mat.l2[0] * p_3d.x_3d + mat.l2[1] * p_3d.y_3d
		+ mat.l2[2] * p_3d.z_3d;
	result.z_3d = mat.l3[0] * p_3d.x_3d + mat.l3[1] * p_3d.y_3d
		+ mat.l3[2] * p_3d.z_3d;
	return (result);
}

int	va_abs(int i)
{
	if (i < 0 && i != -2147483648)
		i = -i;
	return (i);
}
