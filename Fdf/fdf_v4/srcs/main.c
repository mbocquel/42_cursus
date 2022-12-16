/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 23:01:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Obligatoire : 
- Mieux gerer le centrage de l'image.
- Gerer la fermeture de la fenetre en cliquant sur la croix en haut.
- Gerer les erreurs de la MinilibX en verifiant ce que renvoie le poiteur.

Fonctionalites bonus :
- Rotation X, Y, Z axis. 
- Modifier la hauteur du z.
- Projection conique.
- Zoom et de-zoom sur la carte.
- Deplacement dans es 4 directions avec les fleches.
- Tout reinitialiser.
- Coloriser en fonction de l'altitude.
- Modifier la hauteur du z.
*/

void	process_trame(t_trame *trame, t_wdim wdim, t_data *img)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	apply_isometric_proj(trame);
	end = clock();
	printf("apply_isometric_proj : %f s\n",
		((double) end - start) / CLOCKS_PER_SEC);
	start = clock();
	calculate_point_pos(trame, wdim);
	end = clock();
	printf("calculate_point_pos : %f s\n",
		((double) end - start) / CLOCKS_PER_SEC);
	start = clock();
	tracer_trame(img, trame, wdim);
	make_colored_trame(trame);
	tracer_trame_color(img, trame, wdim);
	end = clock();
	printf("tracer_trame : %f s\n",
		((double) end - start) / CLOCKS_PER_SEC);
	free_trame(trame);
}

int	main(int argc, char **argv)
{
	t_trame			*trame;
	t_wdim			wdim;
	t_event_param	p;
	clock_t			start;
	clock_t			end;

	if (argc == 2)
	{
		start = clock();
		trame = parsing_fdf(argv[1]);
		end = clock();
		printf("parsing_fdf : %f s\n",
			((double) end - start) / CLOCKS_PER_SEC);
		if (!trame && ft_printf("Error with the map\n"))
			return (1);
		wdim.width = 1800;
		wdim.height = 1000;
		p.mlx_ptr = mlx_init();
		p.win_ptr = mlx_new_window(p.mlx_ptr, wdim.width,
				wdim.height, "FDF by mbocquel");
		p.img.img = mlx_new_image(p.mlx_ptr, wdim.width, wdim.height);
		p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bits_per_pixel,
				&p.img.line_length, &p.img.endian);
		process_trame(trame, wdim, &p.img);
		mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img.img, 0, 0);
		mlx_key_hook(p.win_ptr, key_win, &p);
		mlx_loop(p.mlx_ptr);
	}
	else
		ft_printf("Wrong argument number\n");
	return (0);
}
