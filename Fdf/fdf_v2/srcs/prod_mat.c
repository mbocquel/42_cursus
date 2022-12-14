/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:16:12 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 15:29:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d_fl	prod_mat3x2_p3d(t_mat3x2 mat, t_point_3d point_3d)
{
	t_point2d_fl	point;
	
	point.xf = mat.l1[0] * (float)point_3d.x_3d + mat.l1[1]
		* (float)point_3d.y_3d + mat.l1[2] * (float)point_3d.z_3d;
	point.yf = mat.l2[0] * (float)point_3d.x_3d + mat.l2[1]
		* (float)point_3d.y_3d + mat.l2[2] * (float)point_3d.z_3d;
	return (point);
}

//probleme en etant en int comme ca = tout s'ecrase. il faudrait plutot etre avec des float, ou alors directement multiplier par ux. 

void	prod_mat3x3_p3d(t_mat3x3 mat, t_point_3d p_3d, t_point_3d *result)
{
	result->x_3d = mat.l1[0] * p_3d.x_3d + mat.l1[1] * p_3d.y_3d
		+ mat.l1[2] * p_3d.z_3d;
	result->y_3d = mat.l2[0] * p_3d.x_3d + mat.l2[1] * p_3d.y_3d
		+ mat.l2[2] * p_3d.z_3d;
	result->z_3d = mat.l3[0] * p_3d.x_3d + mat.l3[1] * p_3d.y_3d
		+ mat.l3[2] * p_3d.z_3d;
}
