/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:00:06 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/14 14:12:26 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_argc(t_node *root)
{
	int	n;

	n = 0;
	while (root->token_type != TK_INF && root->token_type != TK_SUP
		&& root->token_type != TK_DINF && root->token_type != TK_DSUP
		&& root->token_type != TK_EXEC)
	{
		root = root->right;
		n++;
	}
	return (n + 1);
}

static void	init_s_pipe(t_pipe *pipe, t_node *root, t_param *prm)
{
	t_node	*right_parent;
	t_node	*left_child;
	int		i;

	pipe->argc = ft_argc(root);
	pipe->prm = prm;
	pipe->root = root;
	pipe->argv = ft_calloc_gc(prm, prm->source.id,
			pipe->argc + 1, sizeof(t_node *));
	right_parent = root;
	i = 0;
	while (right_parent)
	{
		left_child = right_parent;
		while (left_child->left)
		{
			left_child = left_child->left;
		}
		pipe->argv[i] = left_child;
		pipe->argv[i]->redir = right_parent;
		i++;
		right_parent = right_parent->right;
	}
	init_pipex(pipe, &pipe->pids, &pipe->fd_list);
}

static int	interpret_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		return (130);
	}
	if (sig == SIGQUIT)
	{
		ft_printf("Quit (core dumped)\n");
		return (131);
	}
	return (sig);
}

int	execute_all_cmds(t_pipe *args, int *pids, t_fd *fd_list)
{
	int	i;

	init_signal_parent_during_exec();
	i = 0;
	while (i < args->argc && is_parent_process(pids, i))
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			init_signal_child();
			if (redirections(args, args->argv[i]->redir, i, fd_list))
				ft_error(1, args, fd_list);
			close_fd(args, fd_list);
			ft_error(execute_cmd(args, i), args, fd_list);
		}
		if (pids[i] < 0)
			ft_error(5, args, fd_list);
		i++;
	}
	return (0);
}

int	exec_pipe(t_param *prm, t_node *root)
{
	t_pipe	args;
	int		status;

	init_s_pipe(&args, root, prm);
	init_pipes(&args, args.fd_list);
	if (root->token_type == TK_EXEC && root->cmd == NULL)
	{
		g_return_value = 0;
		return (0);
	}
	init_heredoc(&args, args.fd_list);
	execute_all_cmds(&args, args.pids, args.fd_list);
	close_fd(&args, args.fd_list);
	ft_wait(&args, args.pids);
	waitpid(args.pids[args.argc], &status, 0);
	if (WIFEXITED(status))
		g_return_value = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_return_value = interpret_signal(WTERMSIG(status));
	empty_garbage(prm, -1);
	exit (g_return_value);
}
