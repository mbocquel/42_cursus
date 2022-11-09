/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:58:55 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 14:31:08 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_char;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_char = (char *)s;
	while (i < n)
	{
		if (s_char[i] == c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
