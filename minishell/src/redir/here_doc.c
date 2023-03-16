/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:47:07 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/16 12:50:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	redirection_heredoc(t_pipe *args, t_node *redir,
	int i, t_fd *fd_list)
{
	if (redir == NULL)
		return (0);
	if (redir->token_type == TK_DINF)
	{
		do_heredoc(args, fd_list, redir);
	}
	return (redirection_heredoc(args, redir->left, i, fd_list));
}

int	init_heredoc(t_pipe *args, t_fd *fd_list)
{
	int	i;

	i = 0;
	while (i < args->argc)
	{
		init_signal_heredoc();
		redirection_heredoc(args, args->argv[i]->redir, i, fd_list);
		i++;
	}
	return (0);
}
