/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:36:35 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 15:22:26 by mbocquel         ###   ########.fr       */
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

void	voir_chaine(t_list_reserve **begin)
{
	t_list_reserve	*elem;

	elem = *begin;
	while (elem)
	{
		printf("-----elem----\ndata = %s\n", elem->data);
		printf("fd = %d\n", elem->fd);
		printf("pos_n = %d\n", elem->pos_n);
		elem = elem->next;
	}
}
