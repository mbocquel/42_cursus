/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:04:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/31 11:17:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_event_param *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img.img);
	param->img.img = mlx_new_image(param->mlx_ptr,
			param->wdim.width, param->wdim.height);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&(param->img).bits_per_pixel,
			&(param->img).line_length, &(param->img).endian);
}
