/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:23:16 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/21 17:31:27 by mbocquel         ###   ########.fr       */
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

void	ft_lstadd_back(t_list_sto **lst, t_list_sto *new)
{
	t_list_sto	*elem;

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

t_list_sto	*ft_lstnew(void *content)
{
	t_list_sto	*elem_list;

	elem_list = malloc(sizeof(t_list_sto));
	if (!elem_list)
		return (NULL);
	elem_list -> next = NULL;
	elem_list -> content = content;
	return (elem_list);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
