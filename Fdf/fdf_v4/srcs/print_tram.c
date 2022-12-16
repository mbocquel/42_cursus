/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:50:08 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 20:25:39 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_tram(t_trame *trame)
{
	t_trame	*elem;

	elem = trame;
	while (elem)
	{
		printf("----\n	Adresse %p\n", elem);
		printf("	Point 3D x %d\n", elem->point_3d.x_3d);
		printf("	Point 3D y %d\n", elem->point_3d.y_3d);
		printf("	Point 3D z %d\n", elem->point_3d.z_3d);
		printf("	Point 2D float xf %f\n", elem->point_2d_fl.xf);
		printf("	Point 2D float yf %f\n", elem->point_2d_fl.yf);
		printf("	Point 2D px x %d\n", elem->point_2d_px.x);
		printf("	Point 2D px y %d\n", elem->point_2d_px.y);
		printf("	Point 2D color %d\n", elem->point_2d_px.color);
		printf("	Elem down %p\n", elem->down);
		printf("	Elem right %p\n", elem->right);
		printf("	Elem next %p\n", elem->next);
		printf("	Elem previous %p\n", elem->previous);
		elem = elem->next;
	}
}

void	print_tram_elem(t_trame *elem)
{
	printf("----\n	Adresse %p\n", elem);
	printf("	Point 3D x %d\n", elem->point_3d.x_3d);
	printf("	Point 3D y %d\n", elem->point_3d.y_3d);
	printf("	Point 3D z %d\n", elem->point_3d.z_3d);
	printf("	Point 2D float xf %f\n", elem->point_2d_fl.xf);
	printf("	Point 2D float yf %f\n", elem->point_2d_fl.yf);
	printf("	Point 2D px x %d\n", elem->point_2d_px.x);
	printf("	Point 2D px y %d\n", elem->point_2d_px.y);
	printf("	Point 2D color %d\n", elem->point_2d_px.color);
	printf("	Elem down %p\n", elem->down);
	printf("	Elem right %p\n", elem->right);
	printf("	Elem next %p\n", elem->next);
	printf("	Elem previous %p\n", elem->previous);
}
