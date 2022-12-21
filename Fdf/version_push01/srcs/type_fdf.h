/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fdf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:12:30 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 14:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_FDF_H
# define TYPE_FDF_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
	int	x;
	int	y;
	int	color;
	int	color_modif;
}				t_point;

typedef struct s_point2d_fl {
	float	xf;
	float	yf;
}				t_point2d_fl;

typedef struct s_point_3d {
	float	x_3d;
	float	y_3d;
	float	z_3d;
}				t_point_3d;

typedef struct s_seg {
	t_point	start;
	t_point	end;
}				t_seg;

typedef struct s_wdim {
	int	width;
	int	height;
}				t_wdim;

typedef struct s_map {
	int				n_line;	
	int				*line_int;
	int				nb_col;
	struct s_map	*next;
}				t_map;

typedef struct s_mat3x2 {
	float			l1[3];	
	float			l2[3];
}				t_mat3x2;

typedef struct s_mat3x3 {
	float			l1[3];	
	float			l2[3];
	float			l3[3];
}				t_mat3x3;

typedef struct s_trame {
	t_point			point_2d_px;
	t_point_3d		point_3d;
	t_point2d_fl	point_2d_fl;
	struct s_trame	*down;
	struct s_trame	*right;
	struct s_trame	*next;
	struct s_trame	*previous;
}				t_trame;

typedef struct s_event_param {
	void			*mlx_ptr;
	void			*win_ptr;
	t_data			img;
	t_trame			*trame;
	t_wdim			wdim;
	float			scale_factor;
	float			z_factor;
	t_point2d_fl	orig;
	int				original_color;
	float			angle_x;
	float			angle_y;
	float			angle_z;
	int				proj;
}				t_event_param;

#endif