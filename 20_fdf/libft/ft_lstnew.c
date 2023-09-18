/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:57 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/10 17:44:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem_list;

	elem_list = malloc(sizeof(t_list));
	if (!elem_list)
	{
		return (NULL);
	}
	elem_list -> next = NULL;
	elem_list -> content = content;
	return (elem_list);
}
