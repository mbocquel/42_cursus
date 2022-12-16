/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_trame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:44:40 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 22:58:47 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*get_last_point(t_trame *begin_trame)
{
	t_trame	*elem;

	if (!begin_trame || !(begin_trame->next))
		return (begin_trame);
	elem = begin_trame;
	while (elem)
	{
		if (elem->next == NULL)
			return (elem);
		else
			elem = elem->next;
	}
	return (elem);
}

void	tracer_trame(t_data *img, t_trame *trame, t_wdim wdim)
{
	t_trame	*elem;
	t_seg	seg;

	elem = get_last_point(trame);
	while (elem)
	{
		seg.start = elem->point_2d_px;
		if (elem->down)
		{
			seg.end = (elem->down)->point_2d_px;
			put_segment_img(img, seg, wdim);
		}
		if (elem->right)
		{
			seg.end = (elem->right)->point_2d_px;
			put_segment_img(img, seg, wdim);
		}
		elem = elem->previous;
	}
}

void	tracer_trame_color(t_data *img, t_trame *trame, t_wdim wdim)
{
	t_trame	*elem;
	t_seg	seg;

	elem = get_last_point(trame);
	while (elem)
	{
		seg.start = elem->point_2d_px;
		seg.start.color = seg.start.color_modif;
		if (elem->down)
		{
			seg.end = (elem->down)->point_2d_px;
			seg.end.color = seg.end.color_modif;
			put_segment_img(img, seg, wdim);
		}
		if (elem->right)
		{
			seg.end = (elem->right)->point_2d_px;
			seg.end.color = seg.end.color_modif;
			put_segment_img(img, seg, wdim);
		}
		elem = elem->previous;
	}
}
