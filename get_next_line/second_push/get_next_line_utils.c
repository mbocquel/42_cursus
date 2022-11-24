/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:23:16 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/24 14:39:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	int		test_overfow;
	int		i;

	test_overfow = (int)(nmemb * size);
	if (size && nmemb != (size_t)test_overfow / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < test_overfow)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

void	ft_lstadd_back(t_list_sto **lst, void *content)
{
	t_list_sto	*new;
	t_list_sto	*elem;

	new = malloc(sizeof(t_list_sto));
	if (!new)
		return ;
	new->next = NULL;
	new->content = content;
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

size_t	ft_line_len(t_list_sto *storage)
{
	size_t		len_line;
	int			i;
	t_list_sto	*elem;

	len_line = 0;
	elem = storage;
	while (elem)
	{
		i = -1;
		while ((elem->content)[++i] && (elem->content)[i] != '\n')
			len_line++;
		if ((elem->content)[i] && (elem->content)[i] == '\n')
			len_line++;
		elem = elem->next;
	}
	return (len_line);
}

void	clear_all_memory(t_list_sto **storage)
{
	
}
