/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:24:56 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/21 15:24:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_lst(t_list_sto *storage)
{
	t_list_sto	*elem;

	elem = storage;
	while (elem)
	{
		printf("----elem-----\n");
		printf("content = \"%s\"\n\n", elem->content);
		elem = elem->next;
	}
}