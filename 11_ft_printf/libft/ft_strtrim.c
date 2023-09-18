/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:52 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/09 17:01:54 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start_trim(char const *s1, char const *set)
{
	int	start;
	int	i;

	i = 0;
	start = -1;
	while (s1[i])
	{
		if (start == -1 && ft_strchr(set, s1[i]) == NULL)
			start = i;
		i++;
	}
	return (start);
}

static int	ft_find_end_trim(char const *s1, char const *set)
{
	int	end;
	int	i;

	i = 0;
	end = -1;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			end = i;
		i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*result;

	i = 0;
	start = ft_find_start_trim(s1, set);
	end = ft_find_end_trim(s1, set);
	if (start != -1 && end != -1)
	{
		result = (char *)malloc((end - start + 2) * sizeof(char));
		if (result == NULL)
			return (NULL);
		while (i < end - start + 1)
		{
			result[i] = s1[start + i];
			i++;
		}
	}
	else
		result = (char *)malloc(sizeof(char));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	return (result);
}
