/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:21:42 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/14 14:28:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_space_heredoc(t_param *prm, char *str, size_t *cur)
{
	size_t	pos_start;
	char	*space;

	pos_start = *cur;
	if (!str)
		return (NULL);
	while (*cur < ft_strlen(str) && ft_isspace(str[*cur]))
		(*cur)++;
	space = ft_substr_gc(prm, str, pos_start, *cur - pos_start);
	return (space);
}

char	*get_token_heredoc(t_param *prm, char *str, size_t *cur)
{
	size_t	pos_start;
	char	*token;

	if (!str)
		return (NULL);
	while (*cur < ft_strlen(str) && ft_isspace(str[*cur]))
		(*cur)++;
	if (*cur >= ft_strlen(str))
		return (ft_strdup_gc(prm, prm->source.id, ""));
	pos_start = *cur;
	while (*cur < ft_strlen(str) && !ft_isspace(str[*cur])
		&& !ft_strchr(PARSING_STOPPER, str[*cur]))
	{
		if (str[*cur + 1] && (ft_isspace(str[*cur + 1])
				|| ft_strchr(PARSING_STOPPER, str[*cur + 1])))
			break ;
		(*cur)++;
	}
	if (!ft_isspace(str[*cur]))
		(*cur)++;
	token = ft_substr_gc(prm, str, pos_start, *cur - pos_start);
	return (token);
}

char	*substitute_heredoc(t_param *prm, char *str)
{
	size_t	cur;
	char	*new_str;
	char	*token;

	cur = 0;
	new_str = NULL;
	while (cur < ft_strlen(str))
	{
		new_str = ft_strjoin_gc(prm, prm->source.id, new_str,
				get_space_heredoc(prm, str, &cur));
		token = get_token_heredoc(prm, str, &cur);
		if (get_t_token(token) == TK_WORD_SUB)
			new_str = ft_strjoin_gc(prm, prm->source.id, new_str,
					substitute_word(prm, token));
		else
			new_str = ft_strjoin_gc(prm, prm->source.id, new_str, token);
	}
	return (new_str);
}
