/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_process(t_pile **pile_a, t_pile **pile_b, int *error)
{
	(void) error;
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> swap a\n\n");
	action_swap(pile_a);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> push b\n\n");
	action_push(pile_a, pile_b);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> push b\n\n");
	action_push(pile_a, pile_b);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> push b\n\n");
	action_push(pile_a, pile_b);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> push b\n\n");
	action_push(pile_a, pile_b);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> push a\n\n");
	action_push(pile_b, pile_a);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> rotate a\n\n");
	action_rotate(pile_a);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> reverse rotate b\n\n");
	action_r_rotate(pile_b);
	print_piles(*pile_a, *pile_b);
	ft_printf("\n\n-------> reverse rotate a and b\n\n");
	action_d_r_rotate(pile_a, pile_b);
	print_piles(*pile_a, *pile_b);
}

int	main(int argc, char **argv)
{
	int			error;
	int			i;
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	error = 0;
	i = argc;
	if (argc == 1)
		error = 1;
	else
		pile_a = parsing(argc, argv, &error);
	if (error == 1 || pile_a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	start_process(&pile_a, &pile_b, &error);
	free_piles(&pile_a, &pile_b);
	return (0);
}
