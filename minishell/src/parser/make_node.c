/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:46:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/08 12:57:02 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*make_node(t_param *prm, int id, int token_type, char *token)
{
	t_node	*node;

	if (token == NULL)
		return (NULL);
	node = ft_malloc_gc(prm, prm->source.id, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	ft_memset(node, 0, sizeof(t_node));
	node->id = id;
	node->token_type = token_type;
	node->token = token;
	return (node);
}

t_node	*make_pipe_node(t_param *prm, t_node *left, t_node *right)
{
	t_node	*node;

	node = ft_malloc_gc(prm, prm->source.id, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	ft_memset(node, 0, sizeof(t_node));
	node->id = prm->source.id;
	node->token_type = TK_PIPE;
	node->token = "|";
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*make_redir_node(t_param *prm, t_node *left,
	int token_type, char *file_name)
{
	t_node	*node;

	node = ft_malloc_gc(prm, prm->source.id, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	ft_memset(node, 0, sizeof(t_node));
	node->id = prm->source.id;
	node->token_type = token_type;
	node->token = get_tk_str(token_type);
	node->mode_open = 00644;
	if (token_type == TK_INF)
		node->flags_open = O_RDONLY;
	else if (token_type == TK_SUP)
		node->flags_open = O_WRONLY | O_CREAT | O_TRUNC;
	else if (token_type == TK_DSUP)
		node->flags_open = O_WRONLY | O_CREAT | O_APPEND;
	if (token_type == TK_INF)
		node->mode_open = 00600;
	node->file_name = file_name;
	node->left = left;
	return (node);
}

t_node	*make_exec_node(t_param *prm, char **cmd)
{
	t_node	*node;

	node = ft_malloc_gc(prm, prm->source.id, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	ft_memset(node, 0, sizeof(t_node));
	node->id = prm->source.id;
	node->token_type = TK_EXEC;
	node->token = get_tk_str(TK_EXEC);
	node->cmd = cmd;
	return (node);
}
