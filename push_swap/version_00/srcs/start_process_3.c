/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 17:12:20 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_process_3(t_ps *ps)
{
	int i;

	i = 0;
	record_action(ps, "pb");
	record_action(ps, "pa");
	record_action(ps, "sa");
	while (ps->inst && (ps->inst)[i])
	{
		ft_printf("%s\n", (ps->inst)[i]);
		i++;
	}
	print_piles(ps);
}
