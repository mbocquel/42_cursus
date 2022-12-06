/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:13:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/06 14:18:03 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point {
	int	x;
	int	y;
}				t_point;

typedef struct	s_wdim {
	int	length;
	int	height;
}				t_wdim;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_square_img(t_data *img, t_point p, int lenght, t_wdim wdim);





#endif
