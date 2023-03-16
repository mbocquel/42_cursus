/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:51:30 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/13 12:52:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	init_source(t_param *prm)
{
	prm->source.cur = 0;
	prm->source.error = 0;
	if (prm->source.line == NULL)
		return (1);
	prm->source.line_size = ft_strlen(prm->source.line);
	if (peek_tk(prm) == TK_EOF)
		return (1);
	return (0);
}

char	*sub_line_cas_squote(t_param *prm, char *word)
{
	char	*to_return;

	to_return = word;
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_token(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return,
			get_word_squote(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, "\'");
	return (to_return);
}

char	*sub_line_cas_dquote(t_param *prm, char *word)
{
	char	*to_return;

	to_return = word;
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_token(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return,
			get_word_dquote(prm, FALSE));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, "\"");
	return (to_return);
}

char	*sub_line_cas_redir_simple(t_param *prm, char *word)
{
	char	*to_return;

	to_return = word;
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_token(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_space(prm));
	if (peek_tk(prm) == TK_DQUOTE)
		to_return = sub_line_cas_dquote(prm, to_return);
	else if (peek_tk(prm) == TK_SQUOTE)
		to_return = sub_line_cas_squote(prm, to_return);
	else
		to_return = ft_strjoin_gc(prm, prm->source.id, to_return,
				get_word(prm));
	return (to_return);
}

char	*sub_line_cas_redir_heredoc(t_param *prm, char *word)
{
	char	*to_return;

	to_return = word;
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_token(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return, get_space(prm));
	to_return = ft_strjoin_gc(prm, prm->source.id, to_return,
			get_endheredoc(prm));
	return (to_return);
}
