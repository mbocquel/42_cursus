/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale_factor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:43:48 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 22:52:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_scale_factor(t_trame *trame, t_wdim wdim)
{
	float	factor_x;
	float	nb_elem_x;
	float	nb_elem_y;

	nb_elem_x = (get_xf_max(trame) - get_xf_min(trame) + 4);
	nb_elem_y = (get_yf_max(trame) - get_yf_min(trame) + 4);
	factor_x = (float)wdim.width / nb_elem_x;
	if (nb_elem_x * factor_x <= (float)wdim.height)
		return (factor_x);
	else
		return ((float)wdim.height / nb_elem_y);
}
