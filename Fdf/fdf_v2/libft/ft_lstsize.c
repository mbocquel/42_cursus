/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:44:12 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/10 17:44:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*elem;

	if (!lst)
		return (0);
	elem = lst;
	size = 1;
	while (elem->next)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}
