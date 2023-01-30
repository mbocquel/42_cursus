/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:37:24 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/30 16:09:55 by mbocquel         ###   ########.fr       */
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
		return (ft_exit(px, ERROR_PERROR, argv[1], 1));
	close ((px->pipe_fd)[0]);
	dup2(px->fd_in, STDIN_FILENO);
	close (px->fd_in);
	dup2((px->pipe_fd)[1], STDOUT_FILENO);
	close((px->pipe_fd)[1]);
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
		return (ft_exit(px, ERROR_PERROR, argv[4], 2));
	close((px->pipe_fd)[1]);
	dup2((px->pipe_fd)[0], STDIN_FILENO);
	close ((px->pipe_fd)[0]);
	dup2(px->fd_out, STDOUT_FILENO);
	close(px->fd_out);
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0], 2);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], 2));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, cmd_path, 2));
	return (0);
}

int	pipex(t_pipex *px, char **env, char **argv)
{
	int		i;
	t_cmd	*cmd;

	if (pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "pipe", 0));
	i = -1;
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
	close((px->pipe_fd)[0]);
	close((px->pipe_fd)[1]);
	waitpid((px->pid)[1], &(px->code_exit_last), 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	if (argc != 5)
		return (ft_exit(&px, ERROR_ARG_NUM, argv[0], 0));
	px.garbage = NULL;
	px.cmd = NULL;
	parsing_normal(&px, argc, argv, env);
	pipex(&px, env, argv);
	return (ft_exit(&px, EXIT_NORMAL, "", 0));
}
