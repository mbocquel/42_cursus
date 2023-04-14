/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:57 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/10 17:42:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*temp;

	if (*lst == NULL)
		return ;
	elem = *lst;
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		(*del)(temp->content);
		free(temp);
	}
	*lst = NULL;
}
