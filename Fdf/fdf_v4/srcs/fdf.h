/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:13:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 21:51:15 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

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
}				t_point;

typedef struct s_point2d_fl {
	float	xf;
	float	yf;
}				t_point2d_fl;

typedef struct s_point_3d {
	int	x_3d;
	int	y_3d;
	int	z_3d;
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
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}				t_event_param;

void			put_circle_img(t_data *img, t_point center,
					int radius, t_wdim wdim);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			put_segment_img(t_data *img, t_seg seg, t_wdim wdim);
void			ft_swap_seg(t_seg *seg, t_point *delt);
int				create_trgb(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int				get_color_gradian(t_point p_s, t_point p_e, t_point p);
t_trame			*parsing_fdf(char *fichier);
int				ft_close_fichier(int fd);
int				ft_open_fichier(char *fichier);
void			print_map(t_map *begin_map);
int				check_map(t_map *begin_map);
void			free_map(t_map *begin_map);
void			free_tab_char(char **line_tab_char);
int				get_nb_line(t_map *begin_map);
t_trame			*make_trame(t_map *begin_map);
t_trame			*get_tram_elem(int line, int col, t_trame *begin);
t_trame			*mk_trame_elem(int line, int col, char *str_alt_color);
void			free_trame(t_trame *begin_trame);
int				va_abs(int i);
int				get_max_high_up(t_map *map);
int				get_px_unit_x(t_map *map, t_wdim wdim);
int				get_px_unit_y(t_map *map, t_wdim wdim);
t_point2d_fl	get_origin_coord(t_trame *trame);
void			position_trame(t_trame *trame, t_map *map, t_wdim wdim);
void			tracer_trame(t_data *img, t_trame *trame, t_wdim wdim);
void			print_tram(t_trame *trame);
int				trame_add_back(t_trame *new, t_trame **begin_trame);
int				key_win(int key, void *p);
t_point2d_fl	prod_mat3x2_p3d(t_mat3x2 mat, t_point_3d point_3d);
t_point_3d	prod_mat3x3_p3d(t_mat3x3 mat, t_point_3d p_3d);
void			apply_2d_projection_trame(t_trame *trame, t_map *map,
					t_wdim wdim);
float			get_yf_max(t_trame *trame);
float			get_yf_min(t_trame *trame);
float			get_xf_max(t_trame *trame);
float			get_xf_min(t_trame *trame);
void			calculate_point_pos(t_trame *trame, t_wdim wdim);
float			get_scale_factor(t_trame *trame, t_wdim wdim);
void			apply_isometric_proj(t_trame *trame);
void			free_all(t_map *begin_map, t_trame *begin_trame);
void			process_trame(t_trame *trame, t_wdim wdim, t_data *img);
int				ft_atoi_color(const char *nptr);
int				free_line_split(char **tab_str_alt_color);
int				ft_strtab_size(char **tab_str_alt_color);
int				trame_add_front(t_trame *new, t_trame **begin_trame);
t_trame			*get_tram_elem_from_end(int line, int col, t_trame *begin);
void			print_tram_elem(t_trame *trame);

#endif
