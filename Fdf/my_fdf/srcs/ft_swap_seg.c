/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_seg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:45:46 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/07 14:13:20 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap_seg(t_seg *seg, t_point *delt)
{
	ft_swap(&((*seg).start.x), &((*seg).end.x));
	ft_swap(&((*seg).start.y), &((*seg).end.y));
	(*delt).x = -(*delt).x;
	(*delt).y = -(*delt).y;
}
