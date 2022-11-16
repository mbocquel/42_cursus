/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:50:00 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 10:09:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
