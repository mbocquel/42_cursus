/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent_during_heredoc.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:26:41 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 10:09:22 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sigint_parent_during_heredoc(int sig)
{
	ft_printf("^C\n");
	g_return_value = 130;
	(void)sig;
}

void	init_signal_parent_during_heredoc(void)
{
	signal(SIGINT, &handle_sigint_parent_during_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
