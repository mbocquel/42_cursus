/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:09:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/16 20:07:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERROR_PARSING 10
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_prog
{
	int				fd_in;
	int				fd_out;
	char			*name;
	char			*path_prog;
	char			**args;
	struct s_prog	*next;
}					t_prog;

typedef struct s_pipex
{
	char			*in_file;
	char			*out_file;
	char			**path;
	t_prog			*prog;
}					t_pipex;

char	*ft_path(char const *s1, char const *s2);
void	parsing_normal(t_pipex *px, int argc, char **argv, char **env);
void	print_prog(t_pipex *px);
int	ft_exit(t_pipex *px, int code_exit);

# endif
