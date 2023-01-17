/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:09:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 17:21:49 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERROR_PARSING 10
# define ERROR_GARBAGE_COL 10
# define EXIT_NORMAL 6
# define ERROR_NB_ARG 1
# define ERROR_OPEN 2
# define ERROR_DUP2 3
# define ERROR_EXECVE 5 
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
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
	int				pid;
	char			**cmd_split;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pipex
{
	int				fd_in;
	int				fd_out;
	char			*in_file;
	char			*out_file;
	char			**path_env;
	int				pipe_fd[2];
	int				pipe_sauv[2];
	t_gar_col		*garbage;
	t_cmd			*cmd;
}					t_pipex;

char	*ft_path(char const *s1, char const *s2);
void	parsing_normal(t_pipex *px, int argc, char **argv, char **env);
void	print_prog(t_pipex *px);
int		ft_exit(t_pipex *px, int code_exit);
void	free_split(char **strs);
void	garbage_split(t_pipex *px, char **strs);
void	garbage_col(t_pipex *px, void *ptr);
char	*get_path_prog(t_pipex *px, char *name);

#endif
