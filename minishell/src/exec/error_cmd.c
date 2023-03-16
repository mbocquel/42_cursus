/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:52:00 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/13 03:38:31 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	permission_denied(char **cmd)
{
	ft_put3str_fd("minishell: ", cmd[0], ": Permission denied\n", 2);
	return (126);
}

int	command_not_found(char **cmd)
{
	ft_put3str_fd("minishell: ", cmd[0], ": Command not found\n", 2);
	return (127);
}

int	no_such_file_or_directory(char **cmd)
{
	ft_put3str_fd("minishell: ", cmd[0], ": No such file or directory\n", 2);
	return (127);
}

int	not_a_command(char **cmd)
{
	if (!strncmp(cmd[0], "/", 1) || !strncmp(cmd[0], "./", 2))
		return (no_such_file_or_directory(cmd));
	return (command_not_found(cmd));
}

int	error_ft_strjoin3(char **path_tab, char **cmd)
{
	ft_putstr_fd("minishell: error ft_strjoin3\n", 2);
	return (7);
	(void)path_tab;
	(void)cmd;
}
