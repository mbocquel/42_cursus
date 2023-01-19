/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:08:13 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/19 18:24:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	first_process(t_pipex *px, t_cmd *cmd, char **env)
{
	char	*cmd_path;

	close(((px->pipes)[0])->fd[0]);
	dup2(px->fd_in, STDIN_FILENO);
	close(px->fd_in);
	dup2(((px->pipes)[0])->fd[1], STDOUT_FILENO);
	close(((px->pipes)[0])->fd[1]);
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

	close(((px->pipes)[px->nb_cmd - 2])->fd[1]);
	dup2(((px->pipes)[px->nb_cmd - 2])->fd[0], STDIN_FILENO);
	close(((px->pipes)[px->nb_cmd - 2])->fd[0]);
	dup2(px->fd_out, STDOUT_FILENO);
	close(px->fd_out);
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], ""));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, "execve", cmd_path));
	return (0);
}

int	middle_process(t_pipex *px, t_cmd *cmd, char **env, int i)
{
	char	*cmd_path;

	close(((px->pipes)[i - 1])->fd[1]);
	dup2(((px->pipes)[i - 1])->fd[0], STDIN_FILENO);
	close(((px->pipes)[i - 1])->fd[0]);
	close(((px->pipes)[i])->fd[0]);
	dup2(((px->pipes)[i])->fd[1], STDOUT_FILENO);
	close(((px->pipes)[i])->fd[1]);
	cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
	if (cmd_path == NULL)
		return (ft_exit(px, ERROR_CMD_NOT_FOUND, (cmd->cmd_split)[0], ""));
	if (execve(cmd_path, cmd->cmd_split, env) == -1)
		return (ft_exit(px, ERROR_PERROR, "execve", cmd_path));
	return (0);
}

void	close_all_pipes(t_pipex *px)
{
	int	i;

	i = 0;
	while(i < px->nb_cmd - 1)
	{
		close(((px->pipes)[i])->fd[0]);
		close(((px->pipes)[i])->fd[1]);
		i++;
	}
}

int	wait_for_all(t_pipex *px)
{
	int	i;
	int	status_last;
	
	i = 0;
	status_last = 0;
	while (i < px->nb_cmd - 1)
	{
		waitpid((px->pid)[i], NULL, 0);
		i++;
	}
	waitpid((px->pid)[i], &status_last, 0);
	return (status_last);
}

int	pipex(t_pipex *px, char **env)
{
	int		i;
	t_cmd	*cmd;
	int		status_last;

	status_last = 0;
	i = -1;
	cmd = px->cmd;
	while (++i < px->nb_cmd)
	{
		if (i < px->nb_cmd - 1 && pipe((px->pipes)[i]->fd) == -1)
		{
			ft_printf_fd(2, "error pour i = %d\n", i);
			return (ft_exit(px, ERROR_PERROR, "pipe", "pipex"));
		}
		(px->pid)[i] = fork();
		if ((px->pid)[i] == 0 && i == 0)
			first_process(px, cmd, env);
		else if ((px->pid)[i] == 0 && i == px->nb_cmd - 1)
			last_process(px, cmd, env);
		else if ((px->pid)[i] == 0)
			middle_process(px, cmd, env, i);
		cmd = cmd->next;
	}
	close_all_pipes(px);
	status_last = wait_for_all(px);
	if (status_last)
		return (ft_exit(px, -1, "", ""));
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	if (argc < 5)
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