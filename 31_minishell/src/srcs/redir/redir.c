/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:15:18 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/14 14:18:19 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	no_other_redir_in(t_node *redir)
{
	if (redir == NULL)
		return (1);
	if (redir->token_type == TK_INF || redir->token_type == TK_DINF)
		return (0);
	else
		return (no_other_redir_in(redir->left));
}

int	no_other_redir_out(t_node *redir)
{
	if (redir == NULL)
		return (1);
	if (redir->token_type == TK_SUP || redir->token_type == TK_DSUP)
		return (0);
	else
		return (no_other_redir_out(redir->left));
}

int	redir_in(t_node *redir)
{
	int	fd_input;

	fd_input = open(redir->file_name, redir->flags_open, redir->mode_open);
	if (fd_input == -1)
	{
		if (!access(redir->file_name, F_OK))
			ft_put3str_fd("minishell: ", redir->file_name,
				": Permission denied\n", 2);
		else
			ft_put3str_fd("minishell: ", redir->file_name,
				": No such file or directory\n", 2);
		return (1);
	}
	if (no_other_redir_in(redir->left))
	{
		if (dup2(fd_input, 0) == -1)
			perror("dup redir in error");
	}
	close(fd_input);
	return (0);
}

int	redir_out(t_node *redir)
{
	int	fd_output;

	fd_output = open(redir->file_name, redir->flags_open, redir->mode_open);
	if (fd_output == -1)
	{
		ft_put3str_fd("minishell: ", redir->file_name,
			": Permission denied\n", 2);
		return (1);
	}
	if (no_other_redir_out(redir->left))
	{
		if (dup2(fd_output, 1) == -1)
			perror("dup redir out error");
	}
	close(fd_output);
	return (0);
}
