/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/05 22:51:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_PARSING 10
# define ERROR_ARG 5
# define ERROR_ACTION 30
# include "../libft/libft.h"

typedef struct s_pile {
	int				val;
	int				pos;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct s_ps {
	t_pile			*pile_a;
	t_pile			*pile_b;
	char			**inst;
}					t_ps;

void	free_split(char **str_split);
void	parsing_arg(char *str, t_ps *ps);
void	parsing(int argc, char **argv, t_ps *ps);
void	push_front_lst(t_pile **pile_a, int arg, int *error);
void	free_pile(t_pile **pile);
int		is_in_pile(t_pile *pile, int val);
void	action_swap(t_pile **pile);
void	action_d_swap(t_pile **pile_a, t_pile **pile_b);
void	action_push(t_pile **pile_from, t_pile **pile_to);
void	action_rotate(t_pile **pile);
void	action_d_rotate(t_pile **pile_a, t_pile **pile_b);
void	action_r_rotate(t_pile **pile);
void	action_d_r_rotate(t_pile **pile_a, t_pile **pile_b);
void	print_piles(t_ps *ps);
int		pile_size(t_pile *pile);
void	add_to_pile(t_ps *ps, int val);
int		ft_exit(t_ps *ps, int error_code);
void	get_final_position(t_ps *ps);
void	start_process_3(t_ps *ps);
void	start_process_5(t_ps *ps);
void	start_process_100(t_ps *ps);
void	start_process_big(t_ps *ps);
void	record_action(t_ps *ps, const char *action);
void	print_instruction(t_ps *ps);

#endif