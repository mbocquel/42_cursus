/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:07:59 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/07 17:22:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j]
				&& little[j] && i + j < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
