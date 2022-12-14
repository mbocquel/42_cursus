/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_yf_min_and_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:02:27 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 15:41:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_yf_min(t_trame *trame)
{
	t_trame	*elem;
	float	min;

	elem = trame;
	if (elem)
		min = elem->point_2d_fl.yf;
	while (elem)
	{
		if (elem->point_2d_fl.yf < min)
			min = elem->point_2d_fl.yf;
		elem = elem->next;
	}
	return (min);
}

float	get_yf_max(t_trame *trame)
{
	t_trame	*elem;
	float	max;

	elem = trame;
	if (elem)
		max = elem->point_2d_fl.yf;
	while (elem)
	{
		if (elem->point_2d_fl.yf > max)
			max = elem->point_2d_fl.yf;
		elem = elem->next;
	}
	return (max);
}