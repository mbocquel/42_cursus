/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:45 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/10 17:43:47 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem_original;
	t_list	*elem_new_lst;
	t_list	*begin_new_lst;

	if (!lst)
		return (NULL);
	begin_new_lst = ft_lstnew((*f)(lst->content));
	elem_original = lst->next;
	elem_new_lst = begin_new_lst;
	while (elem_original)
	{
		elem_new_lst->next = ft_lstnew((*f)(elem_original->content));
		if (elem_new_lst->next == NULL)
		{
			ft_lstclear(&begin_new_lst, (*del));
			return (NULL);
		}
		elem_original = elem_original->next;
		elem_new_lst = elem_new_lst->next;
	}
	return (begin_new_lst);
}
