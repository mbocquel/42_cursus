/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:35:45 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/13 12:09:03 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_join;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_len(s1);
	len_s2 = ft_len(s2);
	result_join = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (result_join == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result_join[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		result_join[i] = s2[i - len_s1];
		i++;
	}
	result_join[i] = '\0';
	return (result_join);
}
