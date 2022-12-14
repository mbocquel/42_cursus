/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_origin_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:08:33 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 16:17:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d_fl	get_origin_coord(t_trame *trame)
{
	t_point2d_fl orig;
	orig.xf = - get_xf_min(trame) + 2;
	orig.yf = - get_yf_min(trame) + 2;	
	return (orig); 
}