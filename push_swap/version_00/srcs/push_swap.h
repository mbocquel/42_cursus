/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_pile {
	int				val;
	int				pos;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

void		free_split(char **str_split);
void		parsing_arg(char *str, t_pile **pile_a, int *error);
t_pile	*parsing(int argc, char **argv, int *error);
void		push_front_lst(t_pile **pile_a, int arg, int *error);
void		free_unit_pile(t_pile **pile);
void		free_piles(t_pile **pile_a, t_pile **pile_b);
int			is_in_pile(t_pile *pile, int val);
void		action_swap(t_pile **pile);
void		action_d_swap(t_pile **pile_a, t_pile **pile_b);
void		action_push(t_pile **pile_from, t_pile **pile_to);
void		action_rotate(t_pile **pile);
void		action_d_rotate(t_pile **pile_a, t_pile **pile_b);
void		action_r_rotate(t_pile **pile);
void		action_d_r_rotate(t_pile **pile_a, t_pile **pile_b);
void		print_piles(t_pile *pile_a, t_pile *pile_b);

#endif