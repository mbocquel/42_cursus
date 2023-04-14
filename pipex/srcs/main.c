/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:37:24 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/10 17:26:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Fonctions autorisees :
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/

int	first_process(t_pipex *px, t_cmd *cmd, char **env, char **argv)
{
	char	*cmd_path;

	px->fd_in = open(argv[1], O_RDONLY);
	if (px->fd_in == -1)
	{
		close_pipe(px->pipe_fd);
		return (ft_exit(px, ERROR_PERROR, argv[1], 1));
	}
	if (dup2(px->fd_in, STDIN_FILENO) == -1)
		return (ft_exit(px, ERROR_PERROR, "dup2", 1));
	if (close (px->fd_in) == -1)
		return (ft_exit(px, ERROR_PERROR, "close", 1));
	if (dup2((px->pipe_fd)[1], STDOUT_FILENO) == -1)
		return (ft_exit(px, ERROR_PERROR, "dup2", 1));
	if (close_pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "close", 1));
	if (ft_empty((cmd->cmd_split)[0]))
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, "", 1));
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0], 1);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], 1));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, cmd_path, 1));
	return (0);
}

int	last_process(t_pipex *px, t_cmd *cmd, char **env, char **argv)
{
	char	*cmd_path;

	px->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->fd_out == -1)
	{	
		close_pipe(px->pipe_fd);
		return (ft_exit(px, ERROR_PERROR, argv[4], 2));
	}
	if (dup2((px->pipe_fd)[0], STDIN_FILENO) == -1)
		return (ft_exit(px, ERROR_PERROR, "dup2", 2));
	if (close_pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "close", 2));
	if (dup2(px->fd_out, STDOUT_FILENO) == -1)
		return (ft_exit(px, ERROR_PERROR, "dup2", 2));
	if (close(px->fd_out) == -1)
		return (ft_exit(px, ERROR_PERROR, "close", 2));
	if (ft_empty((cmd->cmd_split)[0]))
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, "", 2));
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0], 2);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], 2));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, cmd_path, 2));
	return (0);
}

int	pipex(t_pipex *px, char **env, char **argv, int i)
{
	t_cmd	*cmd;

	if (pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "pipe", 0));
	cmd = px->cmd;
	while (++i < px->nb_cmd)
	{
		(px->pid)[i] = fork();
		if ((px->pid)[i] == -1)
			return (ft_exit(px, ERROR_PERROR, "fork", 0));
		if ((px->pid)[i] == 0 && i == 0)
			first_process(px, cmd, env, argv);
		else if ((px->pid)[i] == 0)
			last_process(px, cmd, env, argv);
		cmd = cmd->next;
	}
	if (close_pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "close", 0));
	while (px->ret_wait[0] != -1 && px->ret_wait[1] != -1 && errno != ECHILD)
	{
		px->ret_wait[0] = waitpid((px->pid)[0], NULL, 0);
		px->ret_wait[1] = waitpid((px->pid)[1], &(px->code_exit_last), 0);
	}
	return (0);
}

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	if (argc != 5)
	{
		ft_printf_fd(2, "Error: number of argument. ");
		ft_printf_fd(2, "Usage: %s file1 \"cmd1\" \"cmd2\" file2\n", argv[0]);
		return (1);
	}
	px.garbage = NULL;
	px.cmd = NULL;
	parsing_normal(&px, argc, argv, env);
	pipex(&px, env, argv, -1);
	return (ft_exit(&px, EXIT_NORMAL, "", 0));
}
