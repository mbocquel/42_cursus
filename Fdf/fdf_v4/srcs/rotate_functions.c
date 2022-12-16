/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:42:03 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 22:58:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	rotate_x(int angle, t_point_3d p3d)
{
	t_mat3x3	mat_rot_x;
	t_point_3d	result;

	mat_rot_x.l1[0] = 1;
	mat_rot_x.l1[1] = 0;
	mat_rot_x.l1[2] = 0;
	mat_rot_x.l2[0] = 0;
	mat_rot_x.l2[1] = cos(angle);
	mat_rot_x.l2[2] = -sin(angle);
	mat_rot_x.l3[0] = 0;
	mat_rot_x.l3[1] = sin(angle);
	mat_rot_x.l3[2] = cos(angle);
	result = prod_mat3x3_p3d(mat_rot_x, p3d);
	return (result);
}

t_point_3d	rotate_y(int angle, t_point_3d p3d)
{
	t_mat3x3	mat_rot_y;
	t_point_3d	result;

	mat_rot_y.l1[0] = cos(angle);
	mat_rot_y.l1[1] = 0;
	mat_rot_y.l1[2] = sin(angle);
	mat_rot_y.l2[0] = 0;
	mat_rot_y.l2[1] = 1;
	mat_rot_y.l2[2] = 0;
	mat_rot_y.l3[0] = -sin(angle);
	mat_rot_y.l3[1] = 0;
	mat_rot_y.l3[2] = cos(angle);
	result = prod_mat3x3_p3d(mat_rot_y, p3d);
	return (result);
}

t_point_3d	rotate_z(int angle, t_point_3d p3d)
{
	t_mat3x3	mat_rot_z;
	t_point_3d	result;

	mat_rot_z.l1[0] = cos(angle);
	mat_rot_z.l1[1] = -sin(angle);
	mat_rot_z.l1[2] = 0;
	mat_rot_z.l2[0] = sin(angle);
	mat_rot_z.l2[1] = cos(angle);
	mat_rot_z.l2[2] = 0;
	mat_rot_z.l3[0] = 0;
	mat_rot_z.l3[1] = 0;
	mat_rot_z.l3[2] = 1;
	result = prod_mat3x3_p3d(mat_rot_z, p3d);
	return (result);
}
