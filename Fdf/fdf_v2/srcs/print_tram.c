/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:50:08 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 15:32:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_tram(t_trame *trame)
{
	t_trame *elem;

	elem = trame;
	while (elem)
	{
		ft_printf("----\n	Adresse %p\n", elem);
		ft_printf("	Point 3D x %d\n", elem->point_3d.x_3d);
		ft_printf("	Point 3D y %d\n", elem->point_3d.y_3d);
		ft_printf("	Point 3D z %d\n", elem->point_3d.z_3d);
		ft_printf("	Point 2D float xf %d\n", elem->point_2d_fl.xf);
		ft_printf("	Point 2D float yf %d\n", elem->point_2d_fl.yf);
		ft_printf("	Point 2D px x %d\n", elem->point_2d_px.x);
		ft_printf("	Point 2D px y %d\n", elem->point_2d_px.y);
		//ft_printf("	Point 2D color %d\n", elem->point_2d_px.color);
		//ft_printf("	Elem down %p\n", elem->down);
		//ft_printf("	Elem right %p\n", elem->right);
		//ft_printf("	Elem next %p\n", elem->next);
		elem = elem->next;
	}
}