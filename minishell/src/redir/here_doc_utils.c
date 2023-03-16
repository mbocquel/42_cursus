/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:40:18 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/16 12:50:07 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	stdin_closed_heredoc(t_pipe *args, t_fd *fd_list, t_list *lst_str)
{
	close_fd(args, fd_list);
	ft_lstclear(&lst_str, &free);
	empty_garbage(args->prm, -1);
	exit (130);
}

static int	is_fd_open(int fd)
{
	int	test;

	test = dup(fd);
	if (test == -1)
		return (0);
	close(test);
	return (1);
}

void	do_heredoc(t_pipe *args, t_fd *fd_list, t_node *node)
{
	t_list	*lst_str;
	t_list	*new;
	char	*str;

	lst_str = NULL;
	str = "";
	while (str && ft_strcmp(str, node->file_name))
	{
		str = readline("> ");
		garbage_col(args->prm, args->prm->source.id, str);
		new = ft_lstnew((void *)ft_strdup_gc(args->prm, args->prm->source.id,
					substitute_heredoc(args->prm, str)));
		garbage_col(args->prm, args->prm->source.id, new);
		if (ft_strcmp(str, node->file_name) != 0)
			ft_lstadd_back(&lst_str, new);
	}
	if (is_fd_open(0))
	{
		if (!str)
			ft_printf("minishell: warning: here-document delimited by %s%s%s",
				"end-of-file (wanted '", node->file_name, "')\n");
		node->lst_heredoc = lst_str;
	}
	else
		stdin_closed_heredoc(args, fd_list, lst_str);
}
