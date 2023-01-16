/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:07:16 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 00:04:09 by mbocquel         ###   ########.fr       */
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
void get_path(char *str, char **env)
{
	int	i;
	char **path_split;
	char	*path_test;
	char	*path_test2;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	
	printf("%s\n", env[i] + 5);
	path_split = ft_split(env[i] + 5, ":");
	if (path_split == NULL)
		return ;
	i = 0;
	while (path_split[i])
	{
		path_test = ft_strjoin(path_split[i], "/");
		path_test2 = ft_strjoin(path_test, str);
		if(access(path_test2, F_OK) == 0)
			printf("fichier OK : %s\n", path_test2);
		free(path_split[i]);
		free(path_test);
		free(path_test2);
		i++;
	}
}*/

int	main(int argc, char **argv, char **env)
{
	t_pipex px;

	parsing_normal(&px, argc, argv, env);
	print_prog(&px);
	
	//return (ft_exit(&px, EXIT_NORMAL));
}

/*
int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0) //Child process
	{
		if(access("/bin/ls", F_OK) == 0)
			printf("fichier OK\n");
		if (execve(argv[1], argv + 1, env) == -1)
		{
			perror("execve");
			return (1);			
		}
	}
	wait(NULL);
	ft_printf("test\n");
	return (0);
}
	
}*/