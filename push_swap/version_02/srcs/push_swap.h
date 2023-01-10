/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 17:28:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_PARSING 10
# define ERROR_ARG 5
# define ERROR_ACTION 30
# define EXIT_NORMAL 6
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
void	free_pile(t_pile **pile);
int		is_in_pile(t_pile *pile, int val);
void	action_swap(t_pile **pile);
void	action_push(t_pile **pile_from, t_pile **pile_to);
void	action_rotate(t_pile **pile);
void	action_r_rotate(t_pile **pile);
void	print_piles(t_ps *ps);
int		pile_size(t_pile *pile);
void	add_to_pile(t_ps *ps, int val);
int		ft_exit(t_ps *ps, int error_code);
void	get_final_position(t_ps *ps);
void	start_process_3(t_ps *ps);
void	start_process_5(t_ps *ps);
void	start_process_big(t_ps *ps);
void	record_action(t_ps *ps, const char *action);
void	print_instruction(t_ps *ps, int *move);
void	add_action(t_ps *ps, char *str);
int		pile_is_sorted(t_pile *pile);
int		ft_abs(int i);
int		place(t_pile *pile, int pos);
int		next_pos_in_pile(t_ps *ps, int pos, char c);
void	bring_top(t_ps *ps, int i, char c);
int		max_pile_range(t_pile *pile, int start, int end);
void	second_passage_vers_b(t_ps *ps, int nb_chunk, int size);
int		to_bring_top_a(t_pile *pile, int pos, int size);
int		ft_max(int a, int b);
void	second_part_process(t_ps *ps);
void	return_to_a(t_ps *ps, int size);

#endif