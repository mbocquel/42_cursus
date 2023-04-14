/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:19:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:19:55 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_command_list(void)
{
	ft_printf("Not a control key, please use the following control keys...\n");
	ft_printf("\n##########################################################\n");
	ft_printf("#                                                        #\n");
	ft_printf("#                ROTATION COMMANDS (KEYBOARD)            #\n");
	ft_printf("#   X -> Rotate on the X axis                   z        #\n");
	ft_printf("#   Y -> Rotate on the Y axis                   |        #\n");
	ft_printf("#   Z -> Rotate on the Z axis                  / \\       #\n");
	ft_printf("#                                             y   x      #\n");
	ft_printf("#                  MOVE COMMANDS (KEYBOARD)              #\n");
	ft_printf("#   UP ARROW    -> Move up                               #\n");
	ft_printf("#   DOWN ARROW  -> Move down                             #\n");
	ft_printf("#   LEFT ARROW  -> Move left                             #\n");
	ft_printf("#   RIGHT ARROW -> Move right                            #\n");
	ft_printf("#                                                        #\n");
	print_command_list_part2();
}

void	print_command_list_part2(void)
{
	ft_printf("#                 ALTITUDE SCALE (KEYBOARD)              #\n");
	ft_printf("#   L -> Reduce altitude scale                           #\n");
	ft_printf("#   H -> Increase altitude scale                         #\n");
	ft_printf("#                                                        #\n");
	ft_printf("#                  ZOOM COMMANDS (MOUSE)                 #\n");
	ft_printf("#   Mouse roll up   -> Zoom in                           #\n");
	ft_printf("#   Mouse roll down -> Zoom out                          #\n");
	ft_printf("#   Left click      -> Center on the location            #\n");
	ft_printf("#                                                        #\n");
	ft_printf("#                COLOR COMMANDS (KEYBOARD)               #\n");
	ft_printf("#   C   -> Apply colors based on altitude                #\n");
	ft_printf("#   V   -> Apply original colors                         #\n");
	ft_printf("#                                                        #\n");
	ft_printf("#             PROJECTION COMMANDS (KEYBOARD)             #\n");
	ft_printf("#   P   -> Apply parallel projection                     #\n");
	ft_printf("#   I   -> Apply isometric projection                    #\n");
	ft_printf("#                                                        #\n");
	ft_printf("#                GENERAL COMMANDS (KEYBOARD)             #\n");
	ft_printf("#   R   -> Clear all changes                             #\n");
	ft_printf("#   ESC -> Leave program                                 #\n");
	ft_printf("#                                                        #\n");
	ft_printf("##########################################################\n\n");
}
