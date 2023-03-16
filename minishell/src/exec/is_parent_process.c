/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:51:53 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 18:08:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_parent_process(int *pids, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pids[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
