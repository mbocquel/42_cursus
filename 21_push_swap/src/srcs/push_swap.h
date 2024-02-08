/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/12 15:17:46 by mbocquel         ###   ########.fr       */
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

typedef struct s_cost {
	int				total;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rev_a;
	int				rev_b;
}					t_cost;

// ----------------------------------------------
//		print.c ---------------------------------
void	print_instruction(t_ps *ps, int *move);
void	print_piles(t_ps *ps);
void	print_piles_2(t_pile *e_a, t_pile *e_b, int b_a, int b_b);

//		process_big_back_to_a.c -----------------
t_cost	cost_bring_back_to_a(t_ps *ps, int pos);
int		to_bring_top_a(t_ps *ps, int pos);
int		find_elem_to_bring_back(t_ps *ps);
void	return_to_a(t_ps *ps);

//		process_big_to_b.c ----------------------
void	start_process_big(t_ps *ps);
void	process_big_part_2(int med, t_ps *ps);

//		process_small.c -------------------------
void	start_process_3(t_ps *ps);
void	start_process_5(t_ps *ps);

// ACTIONS --------------------------------------
//		actions/actions_elem.c ------------------
void	action_swap(t_pile **pile);
void	action_push(t_pile **pile_from, t_pile **pile_to);
void	action_rotate(t_pile **pile);
void	action_r_rotate(t_pile **pile);

//		actions/actions_elem2.c ------------------
void	action_double_swap(t_ps *ps);
void	action_double_rotate(t_ps *ps);
void	action_double_r_rotate(t_ps *ps);

//		action_free/add_action.c ----------------
int		get_nb_action(char **inst);
void	record_action(t_ps *ps, const char *action);
void	add_action(t_ps *ps, char *str);

//		action_free/add_action.c ----------------
void	rotate_ra_rb(t_ps *ps, t_cost c);
void	rotate_rra_rrb(t_ps *ps, t_cost c);
void	rotate_rra_rb(t_ps *ps, t_cost c);
void	rotate_ra_rrb(t_ps *ps, t_cost c);

// PARSING --------------------------------------
//		parsing/add_to_pile.c -------------------
int		is_in_pile(t_pile *pile, int val);
void	add_to_pile(t_ps *ps, int val);

//		parsing/get_final_position.c ------------
int		pile_size(t_pile *pile);
int		get_elem_pos(int val, int *tab, int size);
void	ft_sort_tab(int *tab, int size);
void	add_position(t_ps *ps, int *tab, int size);
void	get_final_position(t_ps *ps);

//		parsing/parsing.c -----------------------
int		ft_atoi_arg_error(const char *nptr, int *val);
t_pile	*last_pile_elem(t_pile *lst);
void	parsing(int argc, char **argv, t_ps *ps);
void	parsing_arg(char *str, t_ps *ps);

// UTILS ----------------------------------------
//		utils/free_functions.c ------------------
int		ft_exit(t_ps *ps, int error_code);
void	free_split(char **str_split);
void	free_pile(t_pile **pile);

//		utils/ft_math.c -------------------------
int		ft_abs(int i);
int		ft_max(int a, int b);
int		ft_min4(int a, int b, int c, int d);

//		utils/push_swap_utils.c -----------------
int		pile_is_sorted(t_pile *pile);
int		place(t_pile *pile, int pos);
void	bring_top(t_ps *ps, int i, char c);
void	init_cost(t_cost *c);

#endif