/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:50:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/12 11:58:50 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_word(t_param *prm)
{
	t_token	peek;
	char	*token;
	char	*word;

	peek = peek_tk(prm);
	if (!(peek == TK_WORD || peek == TK_SQUOTE || peek == TK_WORD_SUB
			|| peek == TK_DQUOTE))
		return (NULL);
	token = get_token(prm);
	if (get_t_token(token) == TK_WORD)
		word = token;
	if (get_t_token(token) == TK_WORD_SUB)
		word = substitute_word(prm, token);
	if (get_t_token(token) == TK_SQUOTE)
		word = get_word_squote(prm);
	if (get_t_token(token) == TK_DQUOTE)
		word = get_word_dquote(prm, TRUE);
	if (prm->source.cur < prm->source.line_size
		&& ft_isspace(prm->source.line[prm->source.cur]))
		return (word);
	else
		return (ft_strjoin_gc(prm, prm->source.id, word, get_word(prm)));
}

char	*get_word_squote(t_param *prm)
{
	char	*word;
	size_t	pos_start;

	word = NULL;
	pos_start = prm->source.cur;
	while (peek_tk(prm) != TK_SQUOTE && peek_tk(prm) != TK_EOF)
		get_token(prm);
	if (peek_tk(prm) == TK_EOF)
	{
		prm->source.error = ERR_SQUOTE_CLOSE;
		return (NULL);
	}
	if (peek_tk(prm) == TK_SQUOTE)
		get_token(prm);
	word = ft_substr_gc(prm, prm->source.line, pos_start,
			prm->source.cur - pos_start - 1);
	return (word);
}

char	*get_word_dquote(t_param *prm, t_bool sub)
{
	char	*word;

	word = NULL;
	while (!(peek_tk(prm) == TK_DQUOTE || peek_tk(prm) == TK_EOF))
	{
		word = ft_strjoin_gc(prm, prm->source.id, word, get_space(prm));
		if (peek_tk(prm) == TK_WORD_SUB && sub == TRUE)
			word = ft_strjoin_gc(prm, prm->source.id, word,
					substitute_word(prm, get_token(prm)));
		else
			word = ft_strjoin_gc(prm, prm->source.id, word, get_token(prm));
	}
	if (peek_tk(prm) == TK_EOF)
	{
		prm->source.error = ERR_DQUOTE_CLOSE;
		return (NULL);
	}
	word = ft_strjoin_gc(prm, prm->source.id, word, get_space(prm));
	get_token(prm);
	return (word);
}

char	*get_endheredoc(t_param *prm)
{
	t_token	peek;
	char	*token;
	char	*word;

	peek = peek_tk(prm);
	if (!(peek == TK_WORD || peek == TK_SQUOTE || peek == TK_WORD_SUB
			|| peek == TK_DQUOTE))
		return (NULL);
	token = get_token(prm);
	if (get_t_token(token) == TK_WORD || TK_WORD_SUB)
		word = token;
	if (get_t_token(token) == TK_SQUOTE)
		word = get_word_squote(prm);
	if (get_t_token(token) == TK_DQUOTE)
		word = get_word_dquote(prm, FALSE);
	if (prm->source.cur < prm->source.line_size
		&& ft_isspace(prm->source.line[prm->source.cur]))
		return (word);
	else
		return (ft_strjoin_gc(prm, prm->source.id, word, get_endheredoc(prm)));
}
