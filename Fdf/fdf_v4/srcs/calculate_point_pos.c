/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_point_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:18:10 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 20:17:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_point_pos(t_event_param *param)
{
	t_trame			*elem;

	//printf("param->scale_factor %f", param->scale_factor);
	elem = param->trame;
	while (elem)
	{
		elem->point_2d_px.x = (int)(param->scale_factor * (elem->point_2d_fl.xf + param->orig.xf));
		elem->point_2d_px.y = (int)(param->scale_factor * (elem->point_2d_fl.yf + param->orig.yf));
		elem = elem->next;
	}
}
