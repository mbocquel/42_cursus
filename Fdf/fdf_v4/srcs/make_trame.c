/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:48 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 22:24:46 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*mk_trame_elem(int line, int col, char *str_alt_color)
{
	t_trame	*new;

	new = malloc(sizeof(t_trame));
	if (!new)
		return (NULL);
	new->point_3d.x_3d = (float)col;
	new->point_3d.y_3d = (float)line;
	new->point_3d.z_3d = (float)ft_atoi(str_alt_color);
	new->point_2d_px.x = 0;
	new->point_2d_px.y = 0;
	if (ft_strchr(str_alt_color, ',') != 0)
		new->point_2d_px.color = ft_atoi_color(str_alt_color);
	else
		new->point_2d_px.color = create_trgb(0, 255, 255, 255);
	new->point_2d_px.color_modif = 0;
	new->point_2d_fl.xf = 0;
	new->point_2d_fl.yf = 0;
	new->down = NULL;
	new->right = NULL;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

int	trame_add_back(t_trame *new, t_trame **begin_trame)
{
	t_trame	*elem;

	if (new == NULL)
		return (0);
	if (*begin_trame == NULL)
	{
		*begin_trame = new;
		return (1);
	}
	elem = *begin_trame;
	while (elem->next)
	{
		elem = elem->next;
	}
	elem->next = new;
	return (1);
}

int	trame_add_front(t_trame *new, t_trame **begin_trame)
{
	if (new == NULL)
		return (0);
	if (*begin_trame == NULL)
		*begin_trame = new;
	else
	{
		new->next = *begin_trame;
		*begin_trame = new;
	}
	return (1);
}
