/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_trame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:44:40 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 22:49:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracer_trame(t_data *img, t_trame *trame, t_wdim wdim)
{
	t_trame	*elem;
	t_seg	seg;

	elem = trame;
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
		elem = elem->next;
	}
}
