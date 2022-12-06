/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:13:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/06 18:48:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft/libft.h"
# include <math.h>
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
	int	color;
}				t_point;

typedef struct	s_seg {
	t_point	start;
	t_point	end;
}				t_seg;

typedef struct	s_wdim {
	int	width;
	int	height;
}				t_wdim;




#endif
