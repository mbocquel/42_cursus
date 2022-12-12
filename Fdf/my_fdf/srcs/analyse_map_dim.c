/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map_dim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:36 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/12 19:05:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* ------- Logique pour calculer Ux et Uy ---------

Je calcul Ux en fonction du nombre de division de la fenetre necessaire
puis en divisant la largeur de la fenetre par 120% de ce nombre pour avoir
une marge ok en haut et en bas...

===> Est ce que c'est pas mieux d'avoir une marge fixe ? 

une fois que j'ai Ux, je peux determiner Uy avec Uy = Ux / tan(1,0472 radian)
je regarde combien d'unit je dois avoir en y et du coup si c'est compatible 
avec l'hauteur de la fenetre. 
==> si c'est ok, c'est bon j'ai Ux et Uy
Si c'est pas bon. Uy devient : 

Window Heigh / h
h = (nb_ligne + nb_col) * Ux * cos(60 degre)/cos(30 degre)

Ux' = Ux / cos(30 degre)
Uy = Ux * tan (30 degre)

Position de zero 
nb_ligne * Ux , 0 

pour chaque point 
ligne col
=> X = X0 + Ux * (num_col - num_ligne)
=> Y = Y0 + Uy * (num_col + num_ligne)
*/

int	get_px_unit_x(t_map *map, t_wdim wdim)
{
	int	u_x;
	int	qt;

	u_x = 0;
	qt = (int)((float)((get_nb_line(map) + map->nb_col) * 120) / 100);
	if (qt)
		u_x = wdim.width / qt;
	return (u_x);
}
/* A modifier 
int	get_px_unit_y(t_map *map, t_wdim wdim)
{
	int	u_y;
	int	qt;

	u_y = 0;
	qt = (int)((float)((get_nb_line(map) + map->nb_col) * 120) / 100);
	if (qt)
		u_y = wdim.width / qt;
	return (u_y);
}
*/

int	va_abs(int i)
{
	if (i < 0 && i != -2147483648)
		i = -i;
	return (i);
}

int	get_max_high_up(t_map *map)
{
	t_map	*elem;
	int		max;
	int		i;

	elem = map;
	if (elem)
		max = elem->line_int[0];
	while (elem)
	{
		i = 0;
		while (i < elem->nb_col)
		{
			if (elem->line_int[i] - elem->n_line - i > max)
				max = elem->line_int[i] - elem->n_line - i;
			i++;
		}
		elem = elem->next;
	}
	return (max);
}

t_point	get_origin_coord(t_map *map, t_wdim wdim)
{
	t_point orig;

	orig.x = get_nb_line(map) * get_px_unit_x(map, wdim);
	orig.y = 0;
	
	return (orig); 
}

