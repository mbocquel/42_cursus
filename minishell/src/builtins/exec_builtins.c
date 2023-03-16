/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:43:07 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/13 15:45:07 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_builtins(t_pipe *pipe, char *arg[])
{
	int	ret_val;

	ret_val = 0;
	if (!ft_strcmp(arg[0], "pwd"))
		ret_val = exec_pwd();
	if (!ft_strcmp(arg[0], "echo"))
		ret_val = exec_echo(arg);
	if (!ft_strcmp(arg[0], "env"))
		ret_val = exec_env(pipe->prm, arg);
	empty_garbage(pipe->prm, -1);
	exit(ret_val);
}

static int	check_exec_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "env"))
		return (1);
	else
		return (0);
}

int	check_is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"))
		return (1);
	else
		return (0);
}

int	exec_cmd(t_pipe *pipe, char *path, char *arg[])
{
	if (check_is_builtin(arg[0]) && check_exec_builtins(arg[0]))
	{
		exec_builtins(pipe, arg);
		return (0);
	}
	else if (!check_is_builtin(arg[0]))
		return (execve(path, arg, pipe->prm->env));
	return (0);
}
