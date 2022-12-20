/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_origin_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:08:33 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 17:31:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d_fl	get_origin_coord(t_event_param *param)
{
	t_point2d_fl	orig;
	t_point2d_fl	min_fl;
	t_point2d_fl	max_fl;

	min_fl.xf = get_xf_min(param->trame);
	max_fl.xf = get_xf_max(param->trame);
	min_fl.yf = get_yf_min(param->trame);
	max_fl.yf = get_yf_max(param->trame);
	orig.xf = (param->wdim.width - param->scale_factor
			* (max_fl.xf + min_fl.xf)) / (2 * param->scale_factor);
	orig.yf = (param->wdim.height - param->scale_factor
			* (max_fl.yf + min_fl.yf)) / (2 * param->scale_factor);
	return (orig);
}
