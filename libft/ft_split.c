/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:30:26 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/09 17:30:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pos_start_word(const char *s, int w, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[0] && s[0] != c)
	{
		count = 1;
		if (w == 0)
			return (0);
	}
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
		{
			count++;
			if (w == count - 1)
				return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_len_word(const char *s, int word, char c)
{
	int	i;
	int	l;

	i = ft_pos_start_word(s, word, c);
	l = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	if (s[0] && s[0] != c)
		count = 1;
	else
		count = 0;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		w;

	w = 0;
	strs = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (strs == 0)
		return (0);
	while (w < ft_count_words(s, c))
	{
		i = 0;
		strs[w] = (char *)malloc((ft_len_word(s, w, c) + 1) * sizeof(char));
		while (i < ft_len_word(s, w, c))
		{
			strs[w][i] = s[ft_pos_start_word(s, w, c) + i];
			i++;
		}
		strs[w][i] = '\0';
		w++;
	}
	strs[ft_count_words(s, c)] = 0;
	return (strs);
}
