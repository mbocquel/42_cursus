/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:17:21 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/14 14:20:32 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	redir_heredoc(t_node *redir)
{
	int		pipe_heredoc[2];
	t_list	*lst;
	int		ret;

	ret = 0;
	if (pipe(pipe_heredoc) == -1)
		return (1);
	if (!ret && no_other_redir_in(redir->left))
	{
		if (dup2(pipe_heredoc[0], 0) == -1)
			ret = 1;
	}
	lst = redir->lst_heredoc;
	while (!ret && lst && lst->content
		&& (ft_strcmp((char *)(lst->content), redir->file_name)))
	{
		ft_putendl_fd((char *)(lst->content), pipe_heredoc[1]);
		lst = lst->next;
	}
	if (close (pipe_heredoc[0]) == -1)
		ret = 1;
	if (close (pipe_heredoc[1]) == -1)
		ret = 1;
	return (ret);
}

int	redirection_stdin(t_pipe *args, t_node *redir, int i, t_fd *fd_list)
{
	if (redir == NULL || redir->token_type == TK_EXEC)
		return (0);
	if (redir->token_type == TK_SUP || redir->token_type == TK_DSUP)
		return (redirection_stdin(args, redir->left, i, fd_list));
	if (redir->token_type == TK_INF)
		redir_in(redir);
	if (redir->token_type == TK_DINF && no_other_redir_in(redir->left))
		redir_heredoc(redir);
	return (redirection_stdin(args, redir->left, i, fd_list));
}

int	redirection_stdout(t_pipe *args, t_node *redir, int i, t_fd *fd_list)
{
	if (redir == NULL || redir->token_type == TK_EXEC)
		return (0);
	if (redir->token_type == TK_INF || redir->token_type == TK_DINF)
		return (redirection_stdout(args, redir->left, i, fd_list));
	if (redir->token_type == TK_SUP || redir->token_type == TK_DSUP)
		redir_out(redir);
	return (redirection_stdout(args, redir->left, i, fd_list));
}

int	redirections(t_pipe *args, t_node *redir, int i, t_fd *fd_list)
{
	int	ret;

	ret = 0;
	if (i + 1 != args->argc)
	{
		if (dup2(fd_list[i + 1].fd[1], 1) == -1)
			perror("error dupout");
	}
	if (i != 0)
	{
		if (dup2(fd_list[i].fd[0], 0) == -1)
			perror("error dupin");
	}
	ret += redirection_stdin(args, redir, i, fd_list);
	ret += redirection_stdout(args, redir, i, fd_list);
	if (ret)
		return (1);
	return (0);
}
