/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:41 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 18:04:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
