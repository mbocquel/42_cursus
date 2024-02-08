/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:51:58 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/07 18:28:24 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*result;
	unsigned char	uc;

	i = 0;
	result = NULL;
	uc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc)
			result = (char *)s + i;
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (result);
}
