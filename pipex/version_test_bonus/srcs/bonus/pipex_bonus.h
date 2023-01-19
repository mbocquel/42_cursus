/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:09:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/19 18:20:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
# include "../../libft/libft.h"

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

typedef struct s_pipe
{
	int				fd[2];
}					t_pipe;

typedef struct s_pipex
{
	int				fd_in;
	int				fd_out;
	int				nb_cmd;
	int				*pid;
	t_pipe			**pipes;
	char			**path_env;
	t_gar_col		*garbage;
	t_cmd			*cmd;
}					t_pipex;

char	*ft_path(char const *s1, char const *s2);
int		parsing_normal(t_pipex *px, int argc, char **argv, char **env);
void	print_prog(t_pipex *px);
int		ft_exit(t_pipex *px, int code_exit, char *str1, char *str2);
void	garbage_split(t_pipex *px, char **strs);
void	garbage_col(t_pipex *px, void *ptr);
char	*get_path_prog(t_pipex *px, char *name);

#endif
