/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:07:16 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 17:39:20 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Fonctions autorisees :
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/
/*
void	get_fd_in_out(t_pipex *px, t_cmd *cmd)
{
	if (cmd == px->cmd) //On est sur la premiere commande
	{
		cmd->fd_in = open(px->in_file, O_RDONLY);
		if (cmd->fd_in == -1)
		{
			perror("open");
			ft_exit(px, ERROR_OPEN);
		}
	}
	else
		cmd->fd_in = (px->pipe_fd)[0];
	if (cmd->next == NULL)
	{
		cmd->fd_out = open(px->out_file, O_WRONLY | O_CREAT, 0777);
		if (cmd->fd_out == -1)
		{
			perror("open");
			ft_exit(px, ERROR_OPEN);
		}
	}
	else
		cmd->fd_out = (px->pipe_fd)[1];
}*/
/*
void	execute_cmd(t_pipex *px, t_cmd *cmd, char **env)
{
	int		pid;
	char	*cmd_path;
	//int fd;

	if (cmd == NULL)
		return ;
	get_fd_in_out(px, cmd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_exit(px, ERROR_DUP2);
	}
	if (pid == 0)
	{
		ft_printf("cmd %s, fd in : %d\n", (cmd->cmd_split)[0],cmd->fd_in);
		ft_printf("cmd %s, fd out : %d\n", (cmd->cmd_split)[0],cmd->fd_out);
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
		{
			perror("dup2");
			ft_exit(px, ERROR_DUP2);
		}
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			ft_exit(px, ERROR_DUP2);
		}
		ft_printf("cmd %s, fd in : %d\n", (cmd->cmd_split)[0],cmd->fd_in);
		ft_printf("cmd %s, fd out : %d\n", (cmd->cmd_split)[0],cmd->fd_out);
		if (cmd == px->cmd)
		{
			close ((px->pipe_fd)[0]);
			close (cmd->fd_in);
		}
			
		if (cmd->next == NULL)
		{
			close ((px->pipe_fd)[1]);
			close (cmd->fd_out);
		}
			
		fd = open(px->in_file, O_RDONLY);
		
		if (dup2(fd, STDIN_FILENO) == -1)
			perror("dup2");
		cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
		if (execve(cmd_path, cmd->cmd_split, env) == -1)
		{
			perror("execve");
			ft_exit(px, ERROR_EXECVE);
		}
		ft_printf("test\n");
	}
	else
	{
		waitpid(pid, NULL, 0);
		execute_cmd(px, cmd->next, env);
	}
}*/


int	run_program(t_pipex *px, t_cmd *cmd, char **env)
{
	int		pid;
	char	*cmd_path;
	
	ft_printf("Je suis %s\n",(cmd->cmd_split)[0]);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (cmd == px->cmd)
		{
			px->fd_in = open(px->in_file, O_RDONLY);
			dup2(px->fd_in, STDIN_FILENO);
			close(px->fd_in);
		}
		else
		{
			dup2((px->pipe_fd)[0], STDIN_FILENO);
		}
		if (cmd->next != NULL)
		{
			dup2((px->pipe_fd)[1], STDOUT_FILENO);
		}
		else
		{
			px->fd_out = open(px->out_file, O_WRONLY | O_CREAT, 0777);
			dup2(px->fd_out, STDOUT_FILENO);
			close(px->fd_out);
		}
		close((px->pipe_fd)[1]);
		close((px->pipe_fd)[0]);
		cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
		execve(cmd_path, cmd->cmd_split, env);
	}
	ft_printf ("J'attend %d\n", pid);
	//close((px->pipe_fd)[1]);
	//close((px->pipe_fd)[0]);
	waitpid(pid, NULL, 0);
	return (0);
}
/*
int	main(int argc, char **argv, char **env)
{
	t_pipex	px;
	t_cmd *cmd;
	
	if (argc < 5)
	{
		ft_putstr_fd("Error - wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(px.pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	parsing_normal(&px, argc, argv, env);
	cmd = px.cmd;
	while (cmd)
	{
		ft_printf("adresse cmd %p\n", cmd);
		run_program(&px, cmd, env);
		cmd = cmd->next;
		
	}
	close((px.pipe_fd)[1]);
	close((px.pipe_fd)[0]);
	return (0);
}

*/
void	manage_redirect_out(t_pipex *px, t_cmd *cmd)
{
	int	fd_out;

	if (cmd->next != NULL)
	{
		dup2((px->pipe_fd)[1], STDOUT_FILENO);
	}
	else
	{
		fd_out = open(px->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

void	manage_redirect(t_pipex *px, t_cmd *cmd)
{
	int	fd_in;

	if (cmd == px->cmd)
	{
		fd_in = open(px->in_file, O_RDONLY);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	else
	{
		dup2((px->pipe_fd)[0], STDIN_FILENO);
	}
	manage_redirect_out(px, cmd);
}

void	close_mul_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

int	start_execution(t_pipex *px, t_cmd *cmd, char **env)
{
	char *cmd_path;
	
	if (pipe(px->pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	/*(px->pipe_sauv)[0] = dup((px->pipe_fd)[0]);
	(px->pipe_sauv)[1] = dup((px->pipe_fd)[1]);*/
	while (cmd != NULL)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (1);
		if (cmd->pid == 0)
		{
			manage_redirect(px, cmd);
			close_mul_fd((px->pipe_fd)[0], (px->pipe_fd)[1]);
			cmd_path = get_path_prog(px, (cmd->cmd_split)[0]);
			if (cmd_path == NULL)
			{
				ft_putstr_fd((cmd->cmd_split)[0], 2);
				ft_putstr_fd("je trouve pas", 2);
			}
			else 
				ft_putstr_fd(cmd_path, 2);
			execve(cmd_path, cmd->cmd_split, env);
		}
		if (cmd->next == NULL)
			close_mul_fd((px->pipe_fd)[0], (px->pipe_fd)[1]);
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	//close_mul_fd((px->pipe_fd)[0], (px->pipe_fd)[1]);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	/*if (argc < 5)
	{
		ft_putstr_fd("Error - wrong number of arguments\n", 2);
		return (1);
	}*/
	parsing_normal(&px, argc, argv, env);
	start_execution(&px, px.cmd, env);
//	print_prog(&px);

	return (0);
}

/*
int	main(int argc, char **argv, char **env)
{
	t_pipex	px;
	int	pid1;
	int	pid2;
	char *cmd_path;
	t_cmd *cmd;

	if (argc < 5)
	{
		ft_putstr_fd("Error - wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(px.pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	parsing_normal(&px, argc, argv, env);
	ft_printf("pipe_read %d\n", px.pipe_fd[0]);
	ft_printf("pipe_write %d\n\n", px.pipe_fd[1]);
	cmd = px.cmd;
	if (cmd)
	{
		pid1 = fork();
		if (pid1 == -1)
			return (1);
		if (pid1 == 0)
		{
			int fd = open(px.in_file, O_RDONLY);
			cmd_path = get_path_prog(&px, (cmd->cmd_split)[0]);
			dup2(fd, STDIN_FILENO);
			dup2((px.pipe_fd)[1], STDOUT_FILENO);
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);
			close(fd);
			execve(cmd_path, cmd->cmd_split, env);
		}
		waitpid(pid1, NULL, 0);
		cmd = cmd->next;
	}
	if (cmd)
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		if (pid2 == 0)
		{
			//int fd = open(px.in_file, O_RDONLY);
			cmd_path = get_path_prog(&px, (cmd->cmd_split)[0]);
			dup2((px.pipe_fd)[0], STDIN_FILENO);
			//dup2((px.pipe_fd)[1], STDOUT_FILENO);
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);
			//close(fd);
			execve(cmd_path, cmd->cmd_split, env);
		}
		waitpid(pid1, NULL, 0);
		cmd = cmd->next;
	}
	return (ft_exit(&px, EXIT_NORMAL));
}
*/

/*
MAIN OK POUR DEUX CMD
int	main(int argc, char **argv, char **env)
{
	t_pipex	px;
	int	pid1;
	int	pid2;
	char *cmd_path;
	t_cmd *cmd;
	int	fd_in;
	int	fd_out;

	if (argc < 5)
	{
		ft_putstr_fd("Error - wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(px.pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	parsing_normal(&px, argc, argv, env);
	cmd = px.cmd;
	if (cmd)
	{
		pid1 = fork();
		if (pid1 == -1)
			return (1);
		if (pid1 == 0)
		{
			//premier programme
			if (cmd == px.cmd)
			{
				ft_printf("YES 1\n");
				fd_in = open(px.in_file, O_RDONLY);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			else
			{
				ft_printf("YES 2\n");
				dup2((px.pipe_fd)[0], STDIN_FILENO);
			}
			if (cmd->next != NULL)
			{
				ft_printf("YES 3\n");
				dup2((px.pipe_fd)[1], STDOUT_FILENO);
			}
			else
			{
				ft_printf("YES 4\n");
				fd_out = open(px.out_file, O_WRONLY | O_CREAT, 0777);
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
			}
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);
			cmd_path = get_path_prog(&px, (cmd->cmd_split)[0]);
			execve(cmd_path, cmd->cmd_split, env);
		}
		waitpid(pid1, NULL, 0);
		ft_printf("J'ai attendu 4\n");
		cmd = cmd->next;
	}
	if (cmd)
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		if (pid2 == 0)
		{
			//premier programme
			if (cmd == px.cmd)
			{
				ft_printf("YES 1\n");
				fd_in = open(px.in_file, O_RDONLY);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			else
			{
				ft_printf("YES 2\n");
				dup2((px.pipe_fd)[0], STDIN_FILENO);
			}
			if (cmd->next != NULL)
			{
				ft_printf("YES 3\n");
				dup2((px.pipe_fd)[1], STDOUT_FILENO);
			}
			else
			{
				ft_printf("YES 4\n");
				fd_out = open(px.out_file, O_WRONLY | O_CREAT, 0777);
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
			}
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);
			cmd_path = get_path_prog(&px, (cmd->cmd_split)[0]);
			execve(cmd_path, cmd->cmd_split, env);
		}
		close((px.pipe_fd)[1]);
		close((px.pipe_fd)[0]);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}*/

/*int	main(int argc, char **argv, char **env)
{
	t_pipex	px;
	char *cmd_path;
	t_cmd *cmd;
	int	fd_in;
	int	fd_out;

	if (argc < 5)
	{
		ft_putstr_fd("Error - wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(px.pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	parsing_normal(&px, argc, argv, env);
	cmd = px.cmd;
	while (cmd != NULL)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (1);
		if (cmd->pid == 0)
		{
			if (cmd == px.cmd)
			{
				fd_in = open(px.in_file, O_RDONLY);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			else
			{
				dup2((px.pipe_fd)[0], STDIN_FILENO);
			}
			if (cmd->next != NULL)
			{
				dup2((px.pipe_fd)[1], STDOUT_FILENO);
			}
			else
			{
				fd_out = open(px.out_file, O_WRONLY | O_CREAT, 0777);
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
			}
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);
			cmd_path = get_path_prog(&px, (cmd->cmd_split)[0]);
			execve(cmd_path, cmd->cmd_split, env);
		}
		if (cmd->next == NULL)
		{
			close((px.pipe_fd)[1]);
			close((px.pipe_fd)[0]);		
		}
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	return (0);
}*/