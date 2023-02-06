/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:09:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/06 13:49:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERROR_MALLOC 1
# define EXIT_NORMAL 0
# define ERROR_ARG_NUM 3
# define ERROR_PERROR 5
# define ERROR_CMD_NOT_FOUND 7
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_gar_col
{
	void				*ptr;
	struct s_gar_col	*next;
}						t_gar_col;

typedef struct s_cmd
{
	char			**cmd_split;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pipex
{
	int				fd_in;
	int				fd_out;
	int				nb_cmd;
	int				pid[2];
	char			**path_env;
	int				pipe_fd[2];
	int				ret_wait[2];
	int				code_exit_last;
	t_gar_col		*garbage;
	t_cmd			*cmd;
}					t_pipex;

/* main.c */
int		first_process(t_pipex *px, t_cmd *cmd, char **env, char **argv);
int		last_process(t_pipex *px, t_cmd *cmd, char **env, char **argv);
int		pipex(t_pipex *px, char **env, char **argv, int i);
int		ft_empty(char *str);

/* parsing.c */
char	*ft_path(char const *s1, char const *s2);
char	**get_env_path(t_pipex *px, char **env);
char	*get_path_prog(t_pipex *px, char *name, int child);
int		add_cmd(t_pipex *px, char *cmd);
int		parsing_normal(t_pipex *px, int argc, char **argv, char **env);

/* ft_exit.c */
int		close_fd(t_pipex *px);
int		ft_exit_child(t_pipex *px, int code_exit, char *str1);
int		ft_exit_parent(t_pipex *px, int code_exit, char *str1);
int		ft_exit(t_pipex *px, int code_exit, char *str1, int child);
int		close_pipe(int pipe[2]);

/* garbage.c */
void	garbage_col(t_pipex *px, void *ptr);
void	garbage_split(t_pipex *px, char **strs);
void	empty_garbage(t_pipex *px);

#endif
