/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:31:33 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/14 14:30:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*parse(t_param *prm, char *line)
{
	t_node	*root;

	if (prm->source.id != 0)
		empty_garbage(prm, prm->source.id);
	(prm->source.id)++;
	prm->source.line = line;
	garbage_col(prm, prm->source.id, line);
	if (init_source(prm))
		return (NULL);
	prm->source.line = substitute_line(prm);
	prm->source.line_before = line;
	if (prm->source.line == NULL || init_source(prm))
	{
		g_return_value = 1;
		return (NULL);
	}
	root = parse_pipe(prm);
	if (check_error_parsing(prm) || peek_tk(prm) != TK_EOF)
	{
		g_return_value = 1;
		return (NULL);
	}
	return (root);
}

t_node	*parse_pipe(t_param *prm)
{
	t_node	*node;

	if (!(is_redir(peek_tk(prm)) || is_word(peek_tk(prm))))
	{
		prm->source.error = ERR_PARSING;
		return (NULL);
	}
	node = parse_exec(prm);
	if (peek_tk(prm) == TK_PIPE)
	{
		get_token(prm);
		node = make_pipe_node(prm, node, parse_pipe(prm));
	}
	return (node);
}

t_node	*parse_exec(t_param *prm)
{
	t_node	*node;
	char	**cmd;
	char	*arg;

	node = NULL;
	cmd = NULL;
	if (prm->source.cur == 0 && peek_tk(prm) == TK_EOF)
		return (make_exec_node(prm, add_cmd_arg(prm, cmd, "")));
	if (is_redir(peek_tk(prm)))
		node = parse_redir(prm);
	while (is_word(peek_tk(prm)) || is_redir(peek_tk(prm)))
	{
		if (is_word(peek_tk(prm)))
		{
			arg = get_word(prm);
			if (arg == NULL)
				return (NULL);
			cmd = add_cmd_arg(prm, cmd, arg);
		}
		else
			add_last_left(&node, parse_redir(prm));
	}
	add_last_left(&node, make_exec_node(prm, cmd));
	return (node);
}

t_node	*parse_redir(t_param *prm)
{
	t_node	*node;
	t_token	token;
	t_token	peek;
	char	*file_name;

	token = get_t_token(get_token(prm));
	file_name = NULL;
	peek = peek_tk(prm);
	if (!(peek == TK_WORD || peek == TK_SQUOTE
			|| peek == TK_DQUOTE || peek == TK_WORD_SUB))
	{
		prm->source.error = ERR_PARSING;
		return (NULL);
	}
	if (token == TK_DINF)
		file_name = get_endheredoc(prm);
	else
		file_name = get_word(prm);
	if (file_name == NULL)
		prm->source.error = ERR_PARSING;
	node = make_redir_node(prm, NULL, token, file_name);
	return (node);
}

char	*substitute_line(t_param *prm)
{
	char	*word;

	word = NULL;
	while (peek_tk(prm) != TK_EOF)
	{
		word = ft_strjoin_gc(prm, prm->source.id, word, get_space(prm));
		if (peek_tk(prm) == TK_WORD_SUB)
			word = ft_strjoin_gc(prm, prm->source.id, word,
					substitute_word(prm, get_token(prm)));
		else if (peek_tk(prm) == TK_WORD || peek_tk(prm) == TK_PIPE)
			word = ft_strjoin_gc(prm, prm->source.id, word, get_token(prm));
		else if (peek_tk(prm) == TK_SQUOTE)
			word = sub_line_cas_squote(prm, word);
		else if (peek_tk(prm) == TK_DQUOTE)
			word = sub_line_cas_dquote(prm, word);
		else if (peek_tk(prm) == TK_DSUP || peek_tk(prm) == TK_SUP
			|| peek_tk(prm) == TK_INF)
			word = sub_line_cas_redir_simple(prm, word);
		else if (peek_tk(prm) == TK_DINF)
			word = sub_line_cas_redir_heredoc(prm, word);
		else
			return (NULL);
	}
	return (word);
}
