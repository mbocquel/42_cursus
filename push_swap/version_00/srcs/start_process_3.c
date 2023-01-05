/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/05 23:42:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_process_3(t_ps *ps)
{
	record_action(ps, "pb");
	record_action(ps, "pa");
	record_action(ps, "sa");
	//ss
	record_action(ps, "sa");
	record_action(ps, "sb");
	
	record_action(ps, "sb");
	
	//rr
	record_action(ps, "ra");
	record_action(ps, "rb");
	
	record_action(ps, "pb");
	
	//rr
	record_action(ps, "rb");
	record_action(ps, "ra");
	
	//rrr
	record_action(ps, "rra");
	record_action(ps, "rrb");
	
	record_action(ps, "pb");
	
	//rrr
	record_action(ps, "rrb");
	record_action(ps, "rra");
	print_instruction(ps);
}
