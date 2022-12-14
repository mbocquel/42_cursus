/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xf_min_and_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:27 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 15:42:46 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_xf_min(t_trame *trame)
{
	t_trame	*elem;
	float	min;

	elem = trame;
	if (elem)
		min = elem->point_2d_fl.xf;
	while (elem)
	{
		if (elem->point_2d_fl.xf < min)
			min = elem->point_2d_fl.xf;
		elem = elem->next;
	}
	return (min);
}

float	get_xf_max(t_trame *trame)
{
	t_trame	*elem;
	float	max;

	elem = trame;
	if (elem)
		max = elem->point_2d_fl.xf;
	while (elem)
	{
		if (elem->point_2d_fl.xf > max)
			max = elem->point_2d_fl.xf;
		elem = elem->next;
	}
	return (max);
}