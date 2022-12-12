/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_trame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:04:57 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/12 20:08:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	position_trame(t_trame *trame, t_map *map, t_wdim wdim)
{
	int	ux;
	t_point orig;
	t_trame *elem;
	
	ux = get_px_unit_x(map, wdim);
	orig = get_origin_coord(map, wdim);
	elem = trame;
	(elem->point).x = orig.x;
	(elem->point).y = orig.y;
	elem = elem->next;
	ft_printf("ux %d\n", ux);
	while (elem)
	{
		elem->point.x = orig.x + ux * (elem->col - elem->line);
		elem->point.y = (int)((float)orig.y + (float)ux * 0.57735026 * (float)(elem->col + elem->line - get_alt_point(elem->line, elem->col, map)));
		if (get_alt_point(elem->line, elem->col, map) > 0)
			elem->point.color = create_trgb(0, 255, 0, 0);
		elem = elem->next;
	}
}

void tracer_trame(t_data *img, t_trame *trame, t_wdim wdim)
{
	t_trame	*elem;
	t_seg	seg;

	elem = trame;
	while (elem)
	{
		seg.start = elem->point;
		if (elem->down)
		{
			seg.end = (elem->down)->point;
			put_segment_img(img, seg, wdim);
		}
		if (elem->right)
		{
			seg.end = (elem->right)->point;
			put_segment_img(img, seg, wdim);
		}
		elem = elem->next;
	}
}

void	print_tram(t_trame *trame)
{
	t_trame *elem;

	elem = trame;
	while (elem)
	{
		ft_printf("----\n	adresse %p\n", elem);
		ft_printf("	line %d\n", elem->line);
		ft_printf("	col %d\n", elem->col);
		ft_printf("	point.x %d\n", elem->point.x);
		ft_printf("	point.y %d\n", elem->point.y);
		ft_printf("	point.color %d\n", elem->point.color);
		ft_printf("	adresse down %p\n", elem->down);
		ft_printf("	adresse right %p\n", elem->right);
		ft_printf("	adresse next %p\n", elem->next);
		elem = elem->next;
	}
}