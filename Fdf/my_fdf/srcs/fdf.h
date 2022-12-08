/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:13:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:34:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

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

typedef struct s_trame {
	int				line;
	int				col;
	t_point			point;
	struct s_trame	*down;
	struct s_trame	*right;
	struct s_trame	*next;
}				t_trame;

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
t_map			*parsing_fdf(char *fichier);
int				ft_close_fichier(int fd);
int				ft_open_fichier(char *fichier);
void			print_map(t_map *begin_map);
int				check_map(t_map *begin_map);
void			free_map(t_map *begin_map);
void			free_tab_char(char **line_tab_char);
int				get_alt_point(int line, int col, t_map *begin_map);
int				get_nb_line(t_map *begin_map);
int				get_alt_min(t_map *begin_map);
int				get_alt_max(t_map *begin_map);
t_trame			*make_trame(t_map *begin_map);
void			trame_add_back(t_trame *new, t_trame **begin_trame);
t_trame			*get_tram_elem(int line, int col, t_trame *begin);
t_trame			*mk_trame_elem(int line, int col);
void			free_trame(t_trame *begin_trame);

#endif
