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

int	ft_pos_str(char *s, char c)
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

t_list_reserve	*ft_add_elem_reserve(t_list_reserve **lst, char *data, int fd)
{
	t_list_reserve	*elem;
	t_list_reserve	*new;

	new = malloc(sizeof(t_list_reserve));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->data = data;
	new->fd = fd;
	new->pos_n = ft_pos_str(data, '\n');
	if (*lst == NULL)
	{
		*lst = new;
		return (new);
	}
	elem = *lst;
	while (elem->next)
	{
		elem = elem->next;
	}
	elem->next = new;
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strcat_upto(char *dest, const char *src, size_t size, int end_cat)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;
	size_t	max_cat;

	i = 0;
	len_src = ft_strlen(src);
	max_cat = len_src;
	if (end_cat >= 0)
		max_cat = (size_t)end_cat;
	if (dest == NULL && size == 0)
		return (len_src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (len_src + size);
	if (dest == NULL)
		return (len_dest + len_src);
	while (src[i] && i < (size - len_dest - 1) && i <= max_cat)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
