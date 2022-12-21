/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:13:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 13:41:40 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>
# include "type_fdf.h"
# define KEY_R 114
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122
# define KEY_R 114
# define KEY_H 104
# define KEY_L 108
# define KEY_C 99
# define KEY_V 118
# define KEY_UP_ARROW 65362
# define KEY_LOW_ARROW 65364
# define KEY_LEFT_ARROW 65361
# define KEY_RIGHT_ARROW 65363
# define KEY_ESC 0xFF1B
# define MOUSE_ROLL_ZOOM 4
# define MOUSE_ROLL_UNZOOM 5

/*  --- apply_isometric_proj.c 		----*/
void			apply_isometric_proj(t_event_param *param);

/*  --- calculate_point_pos.c 		----*/
void			calculate_point_pos(t_event_param *param);

/*  --- change_z_scale.c 			----*/
void			change_z_scale(t_event_param *param, int key);

/*  --- clear_all_change.c 			----*/
void			clear_all_change(t_event_param *param);

/*  --- clear_img.c 				----*/
void			clear_img(t_event_param *param);

/*  --- create_color_code.c 		----*/
int				create_trgb(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

/*  --- event_key.c 				----*/
int				handle_key(int key, void *p);
int				close_win(void *p);
int				handle_mouse(int button, int x, int y, void *param);
void			colorise(t_event_param *param, int key);

/*  --- free_functions.c 			----*/
void			free_trame(t_trame *begin_trame);
int				free_line_split(char **tab_str_alt_color, int return_val);

/*  --- ft_atoi_color.c 			----*/
int				ft_atoi_color(const char *nptr);

/*  --- ft_swap_seg.c 				----*/
void			ft_swap_seg(t_seg *seg, t_point *delt);

/*  --- get_alt_min_max.c 			----*/
void			get_alt_min_max(t_trame *trame, float *min, float *max);

/*  --- get_color_gradian.c 		----*/
int				get_color_gradian(t_point p_s, t_point p_e, t_point p);
int				get_color_altitude(float min, float max, float z);
int				get_color_altitude_pos(int e, int col_max, int col_zero);
int				get_color_altitude_neg(int e, int col_zero, int col_min);

/*  --- get_origin_coord.c 			----*/
t_point2d_fl	get_origin_coord(t_event_param *param);

/*  --- get_scale_factor.c 			----*/
float			get_scale_factor(t_trame *trame, t_wdim wdim);

/*  --- get_tram_elem.c 			----*/
t_trame			*get_tram_elem(int line, int col, t_trame *begin);

/*  --- get_xf_min_and_max.c 		----*/
float			get_xf_min(t_trame *trame);
float			get_xf_max(t_trame *trame);

/*  --- get_yf_min_and_max.c 		----*/
float			get_yf_min(t_trame *trame);
float			get_yf_max(t_trame *trame);

/*  --- main.c 						----*/
void			process_trame(t_event_param *param);
t_event_param	initiate_img(int width, int height);
void			initiate_param(t_event_param *param);

/*  --- make_colored_trame.c 		----*/
void			make_colored_trame(t_trame *trame);

/*  --- make_trame.c 				----*/
t_trame			*mk_trame_elem(int line, int col, char *str_alt_color);
void			trame_add_front(t_trame *new, t_trame **begin_trame);

/*  --- my_mlx_pixel_put.c 			----*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*  --- parsing.c 					----*/
int				ft_check_fdf_extention(char *str);
int				ft_open_fichier(char *fichier);
int				ft_close_fichier(int fd);
int				process_line(t_trame **begin_trame, char **tab,
					int num_l, int *e);
t_trame			*parsing_fdf(char *fichier);

/*  --- print_command_list.c 		----*/
void			print_command_list(void);
void			print_command_list_part2(void);

/*  --- prod_mat.c 					----*/
t_point2d_fl	prod_mat3x2_p3d(t_mat3x2 mat, t_point_3d point_3d);
t_point_3d		prod_mat3x3_p3d(t_mat3x3 mat, t_point_3d p_3d);
int				va_abs(int i);

/*  --- put_segment_img.c 			----*/
void			put_segment_img(t_data *img, t_seg seg, t_wdim wdim);

/*  --- rotate_functions.c 			----*/
t_point_3d		rotate(t_event_param *param, t_point_3d p3d);
void			rotate_trame(t_event_param *param, int key);

/*  --- tracer_trame.c 				----*/
t_trame			*get_last_point(t_trame *begin_trame);
void			tracer_trame(t_event_param *param);
void			tracer_trame_color(t_event_param *param);

/*  --- translation.c 				----*/
void			translation(t_event_param *param, int key);
void			focus_point(t_event_param *param, int x, int y);

/*  --- zoom_unzoom.c 				----*/
void			zoom_function(t_event_param *param, int button);

#endif
