/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/02 19:26:45 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			error;
	int			i;
	t_lst_ps	*pile_a;
	t_lst_ps	*pile_b;

	pile_a = NULL;
	error = 0;
	i = argc;
	if (argc == 1)
		error = 1;
	else
	{
		while (--i > 0)
			parsing(argv[i], &pile_a, &error);
	}
	if (error == 1)
		return (1);
	return (0);
}
