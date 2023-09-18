/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:48:44 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/10 12:45:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	test_double_token(t_param *prm, size_t cur)
{
	if (cur + 1 < prm->source.line_size && prm->source.line[cur + 1]
		&& ((prm->source.line[cur] == '<' && prm->source.line[cur + 1] == '<')
			|| (prm->source.line[cur] == '>'
				&& prm->source.line[cur + 1] == '>')))
		cur++;
	if (!ft_isspace(prm->source.line[cur]))
		cur++;
	return (cur);
}

char	*get_token(t_param *prm)
{
	size_t	pos_start;
	char	*token;
	size_t	cur;

	cur = prm->source.cur;
	if (!prm->source.line)
		return (NULL);
	while (cur < prm->source.line_size && prm->source.line[cur]
		&& ft_isspace(prm->source.line[cur]))
		cur++;
	if (cur >= prm->source.line_size)
		return (ft_strdup_gc(prm, prm->source.id, ""));
	pos_start = cur;
	while (cur < prm->source.line_size && !ft_isspace(prm->source.line[cur])
		&& !ft_strchr(PARSING_STOPPER, prm->source.line[cur]))
	{
		if (prm->source.line[cur + 1] && (ft_isspace(prm->source.line[cur + 1])
				|| ft_strchr(PARSING_STOPPER, prm->source.line[cur + 1])))
			break ;
		cur++;
	}
	cur = test_double_token(prm, cur);
	token = ft_substr_gc(prm, prm->source.line, pos_start, cur - pos_start);
	prm->source.cur = cur;
	return (token);
}

t_token	peek_tk(t_param *prm)
{
	int			pos_start;
	char		*token;
	size_t		cur;

	cur = prm->source.cur;
	if (!prm->source.line)
		return (TK_ERROR);
	while (cur < prm->source.line_size
		&& prm->source.line[cur] && ft_isspace(prm->source.line[cur]))
		cur++;
	if (cur >= prm->source.line_size)
		return (TK_EOF);
	pos_start = cur;
	while (cur < prm->source.line_size && !ft_isspace(prm->source.line[cur])
		&& !ft_strchr(PARSING_STOPPER, prm->source.line[cur]))
	{
		if (prm->source.line[cur + 1] && (ft_isspace(prm->source.line[cur + 1])
				|| ft_strchr(PARSING_STOPPER, prm->source.line[cur + 1])))
			break ;
		cur++;
	}
	cur = test_double_token(prm, cur);
	token = ft_substr_gc(prm, prm->source.line, pos_start, cur - pos_start);
	return (get_t_token(token));
}

static t_token	get_t_token_2(char *token)
{
	if (ft_strncmp(token, ">", 2) == 0)
		return (TK_SUP);
	if (ft_strncmp(token, "<<", 2) == 0)
		return (TK_DINF);
	if (ft_strncmp(token, ">>", 2) == 0)
		return (TK_DSUP);
	if (ft_strncmp(token, "\'", 1) == 0)
		return (TK_SQUOTE);
	if (ft_strncmp(token, "\"", 1) == 0)
		return (TK_DQUOTE);
	if (pos_str(token, '$') != -1 && ft_strlen(token) > 1)
		return (TK_WORD_SUB);
	return (TK_WORD);
}

t_token	get_t_token(char *token)
{
	if (token == NULL)
		return (TK_ERROR);
	if (token[0] == '\0')
		return (TK_EOF);
	if (ft_strncmp(token, "|", 2) == 0)
		return (TK_PIPE);
	if (ft_strncmp(token, "<", 2) == 0)
		return (TK_INF);
	return (get_t_token_2(token));
}
