/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colored_trame.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:11:35 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 22:59:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_colored_trame(t_trame *trame)
{
	t_trame	*elem;
	float	min;
	float	max;
	int		color;

	get_alt_min_max(trame, &min, &max);
	color = 0;
	elem = trame;
	while (elem)
	{
		color = get_color_altitude(min, max, elem->point_3d.z_3d);
		elem->point_2d_px.color_modif = color;
		elem = elem->next;
	}
}
