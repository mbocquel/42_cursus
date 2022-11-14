/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:29 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 14:33:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*char_s1;
	char	*char_s2;

	char_s1 = (char *)s1;
	char_s2 = (char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && (unsigned char)char_s1[i] == (unsigned char)char_s2[i])
		i++;
	return ((unsigned char)char_s1[i] - (unsigned char)char_s2[i]);
}
