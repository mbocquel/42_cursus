/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:19:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 22:07:47 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_command_list(void)
{
	ft_printf("\n");
	ft_printf("#############################################################\n");
	ft_printf("#                     ROTATION COMMANDS                     #\n");
	ft_printf("#   X -> Rotate on the X axis                               #\n");
	ft_printf("#   Y -> Rotate on the Y axis                               #\n");
	ft_printf("#   Z -> Rotate on the Z axis                               #\n");
	ft_printf("#                                                           #\n");
	ft_printf("#                       MOVE COMMANDS                       #\n");
	ft_printf("#   UP ARROW    -> Rotate on the X axis                     #\n");
	ft_printf("#   DOWN ARROW  -> Rotate on the Y axis                     #\n");
	ft_printf("#   LEFT ARROW  -> Rotate on the Z axis                     #\n");
	ft_printf("#   RIGHT ARROW -> Rotate on the Z axis                     #\n");
	ft_printf("#                                                           #\n");
	ft_printf("#                       ZOOM COMMANDS                       #\n");
	ft_printf("#   + / Mouse roll up   -> Zoom in                          #\n");
	ft_printf("#   - / Mouse roll down -> Zoom out                         #\n");
	ft_printf("#   Left click          -> Center on the location           #\n");
	ft_printf("#                                                           #\n");
	ft_printf("#                     GENERAL COMMANDS                      #\n");
	ft_printf("#   R   -> Clear all changes                                #\n");
	ft_printf("#   ESC -> Leave program                                    #\n");
	ft_printf("#                                                           #\n");
	ft_printf("#############################################################\n");
	ft_printf("\n");
}