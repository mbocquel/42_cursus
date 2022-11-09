/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:47 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 14:03:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*char_s;

	i = 0;
	if (s == NULL)
		return (NULL);
	char_s = (char *)s;
	while (i < n)
	{
		char_s[i] = c;
		i++;
	}
	return (s);
}
