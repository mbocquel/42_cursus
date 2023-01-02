/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:20:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/02 19:09:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str_split, int nb_arg, int w)
{
	int	i;

	i = nb_arg - 1;
	while (i >= w)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}
