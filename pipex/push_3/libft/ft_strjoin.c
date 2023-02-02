/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:51:30 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/30 14:49:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_join;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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

static void	get_len(int *len, char const *s1, char const *s2, char const *s3)
{
	len[0] = (int)ft_strlen(s1);
	len[1] = (int)ft_strlen(s2);
	len[2] = (int)ft_strlen(s3);
}

char	*ft_strjoin_2(char const *s1, char const *s2, char const *s3)
{
	char	*result_join;
	int		i;
	int		len[3];

	get_len(len, s1, s2, s3);
	result_join = (char *)malloc((len[0] + len[1] + len[2] + 1) * sizeof(char));
	if (result_join == NULL)
		return (NULL);
	i = -1;
	while (++i < len[0])
		result_join[i] = s1[i];
	while (i < len[0] + len[1])
	{
		result_join[i] = s2[i - len[0]];
		i++;
	}
	while (i < len[0] + len[1] + len[2])
	{
		result_join[i] = s3[i - len[0] - len[1]];
		i++;
	}
	result_join[len[0] + len[1] + len[2]] = '\0';
	return (result_join);
}
