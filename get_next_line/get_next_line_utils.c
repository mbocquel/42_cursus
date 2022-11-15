/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:36:35 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/15 17:36:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_pos_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_add_elem_reserve(t_list_reserve **lst, t_list_reserve *new)
{
	t_list_reserve	*elem;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	elem = *lst;
	while (elem->next)
	{
		elem = elem->next;
	}
	elem->next = new;
}

t_list_reserve	*ft_new_elem_reserve(char *data)
{
	t_list_reserve	*elem_list;

	elem_list = malloc(sizeof(t_list_reserve));
	if (!elem_list)
	{
		return (NULL);
	}
	elem_list->next = NULL;
	elem_list->data = data;
	elem_list->pos_n = ft_pos_str(data, '\n');
	return (elem_list);
}