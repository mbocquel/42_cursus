/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:37:24 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/19 18:36:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Fonctions autorisees :
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid

J'ai plein de fd encore ouvert en sortie. ==> trouver comment corriger.
Et je comprend pas bien les leak des enfants ==> est ce que ca veut 
dire que valgrind regarde aussi cote enfant ce qui a ete affecte avant que
tout disparraisse ?
valgrind --trace-children=yes --track-fds=yes --leak-check=full*/

int	first_process(t_pipex *px, t_cmd *cmd, char **env)
{
	char	*cmd_path;

	close ((px->pipe_fd)[0]);
	dup2(px->fd_in, STDIN_FILENO);
	close (px->fd_in);
	dup2((px->pipe_fd)[1], STDOUT_FILENO);
	close((px->pipe_fd)[1]);
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], ""));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, "execve", cmd_path));
	return (0);
}

int	last_process(t_pipex *px, t_cmd *cmd, char **env)
{
	char	*cmd_path;

	close((px->pipe_fd)[1]);
	dup2((px->pipe_fd)[0], STDIN_FILENO);
	close ((px->pipe_fd)[0]);
	dup2(px->fd_out, STDOUT_FILENO);
	close(px->fd_out);
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], ""));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, "execve", cmd_path));
	return (0);
}

int	pipex(t_pipex *px, char **env)
{
	int		i;
	t_cmd	*cmd;
	int		status_1;

	status_1 = 0;
	if (pipe(px->pipe_fd) == -1)
		return (ft_exit(px, ERROR_PERROR, "pipe", ""));
	i = -1;
	cmd = px->cmd;
	while (++i < px->nb_cmd)
	{
		(px->pid)[i] = fork();
		if ((px->pid)[i] == 0 && i == 0)
			first_process(px, cmd, env);
		else if ((px->pid)[i] == 0)
			last_process(px, cmd, env);
		cmd = cmd->next;
	}
	close((px->pipe_fd)[0]);
	close((px->pipe_fd)[1]);
	waitpid((px->pid)[0], NULL, 0);
	waitpid((px->pid)[1], &status_1, 0);
	if (status_1)
		return (ft_exit(px, status_1, "", ""));
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	if (argc != 5)
		return (ft_exit(&px, ERROR_ARG_NUM, argv[0], ""));
	px.garbage = NULL;
	px.cmd = NULL;
	parsing_normal(&px, argc, argv, env);
	px.fd_in = open(argv[1], O_RDONLY);
	if (px.fd_in == -1)
		return (ft_exit(&px, ERROR_PERROR, "open", argv[1]));
	px.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px.fd_out == -1)
		return (ft_exit(&px, ERROR_PERROR, "open", argv[argc - 1]));
	pipex(&px, env);
	return (ft_exit(&px, EXIT_NORMAL, "", ""));
}
