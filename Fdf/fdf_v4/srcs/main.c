/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:55:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 23:06:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Obligatoire : 
- Mieux gerer le centrage de l'image.
- Gerer les erreurs de la MinilibX en verifiant ce que renvoie le poiteur.

Fonctionalites bonus :
- Rotation X, Y, Z axis. 
- Modifier la hauteur du z.
- Projection conique.
- Zoom et de-zoom sur la carte.
- Deplacement dans es 4 directions avec les fleches.
- Tout reinitialiser.
- Coloriser en fonction de l'altitude.

- Besoin de calculer le facteur de redim de z en fonction de l'image pour pas que ca fasse un truc moche pour les petites dim mais avec des hautes alts. 
*/

void	process_trame(t_event_param *param)
{
	apply_isometric_proj(param->trame, 1);
	param->scale_factor = get_scale_factor(param->trame, param->wdim);
	param->orig = get_origin_coord(param->trame);
	calculate_point_pos(param);
	tracer_trame(param);
}

t_event_param	initiate_img(int width, int height)
{
	t_event_param	p;

	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, width,
			height, "FDF by mbocquel");
	p.img.img = mlx_new_image(p.mlx_ptr, width, height);
	p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bits_per_pixel,
			&p.img.line_length, &p.img.endian);
	p.trame = NULL;
	p.wdim.width = width;
	p.wdim.height = height;
	p.scale_factor = 1;
	p.z_factor = 1;
	p.orig.xf = 0;
	p.orig.yf = 0;
	p.original_color = 1;
	return (p);
}

int	main(int argc, char **argv)
{
	t_event_param	param;

	if (argc == 2)
	{
		param = initiate_img(1800, 1000);
		param.trame = parsing_fdf(argv[1]);
		if (!param.trame && ft_printf("Error with the map\n"))
			return (1);
		process_trame(&param);
		mlx_put_image_to_window(param.mlx_ptr, param.win_ptr,
			param.img.img, 0, 0);
		mlx_key_hook(param.win_ptr, handle_key, &param);
		mlx_hook(param.win_ptr, 17, (1L << 0), close_win, &param);
		mlx_mouse_hook(param.win_ptr, handle_mouse, &param);
		mlx_loop(param.mlx_ptr);
	}
	else
		ft_printf("Wrong argument number\n");
	return (0);
}

/*
int	main(void)
{
	int i;
	i = 0;
	printf("%c\n",ft_tolower('f'));
	i = ft_atoi_color("0xff");
	printf("%d\n",i);
	return (0);
}*/