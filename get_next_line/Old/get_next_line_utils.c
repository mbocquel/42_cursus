/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:41:36 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 16:39:36 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

	i = -1;
	char_dest = (char *)dest;
	char_src = (char *)src;
	if (dest - src > 0 && (size_t)(dest - src) < n)
	{
		while (++i < n)
			char_dest[n - 1 - i] = char_src[n - 1 - i];
	}
	else if (dest != src)
	{
		while (++i < n)
			char_dest[i] = char_src[i];
	}
	return (dest);
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