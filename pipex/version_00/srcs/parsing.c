/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:11:55 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 00:09:55 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char const *s1, char const *s2)
{
	char	*result_join;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result_join = (char *)malloc((len_s1 + len_s2 + 2) * sizeof(char));
	if (result_join == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result_join[i] = s1[i];
		i++;
	}
	result_join[i] = '/';
	while (++i < len_s1 + len_s2 + 1)
		result_join[i] = s2[i - 1 - len_s1];
	result_join[len_s1 + len_s2 + 1] = '\0';
	return (result_join);
}

/*void get_path(char *str, char **env)
{
	int	i;
	char **path_split;
	char	*path_test;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path_split = ft_split(env[i] + 5, ":");
	if (path_split == NULL)
		return ;
	i = 0;
	while (path_split[i])
	{
		path_test = ft_path(env[i], path_split[i]);
		if(access(path_test, F_OK) == 0)
			printf("fichier OK : %s\n", path_test);
		free(path_split[i]);
		free(path_test);
		i++;
	}
}*/
/*
int	add_prog(t_pipex *px, char *cmd)
{
	char	*cmd_path;
	int		i;
	t_prog	*new;
	char	**cmd_split;
	

	i = 0;
	cmd_path = NULL;
	ft_printf("cmd %s\n", cmd);
	new = (t_prog *)malloc(sizeof(t_prog *));
	if (new == NULL)
		return(ft_exit(px, ERROR_PARSING));
	cmd_split = ft_split(cmd, " ");
	if (cmd_split == 0)
		return(ft_exit(px, ERROR_PARSING));
	i = -1;
	while ((px->path)[++i])
	{
		cmd_path = ft_path( (px->path)[i], cmd_split[0]);
		ft_printf("%s\n", cmd_path);
		if (access(cmd_path, F_OK) == 0)
			break ;
		else
			free(cmd_path);
	}
	new->path_prog = cmd_path;
	new->name = cmd_split[0];
	new->cmd_split = cmd_split;
	i = 0;
	while ((new->cmd_split)[i])
	{
		ft_printf("1 : %s\n", (new->cmd_split)[i]);
		i++;
	}
	new->next = NULL;
	if (px->prog == NULL)
		px->prog = new;
	else
	{
		new->next = px->prog;
		px->prog = new;
	}
	return (0);
}*/

void	print_prog(t_pipex *px)
{
	int		i;
	ft_printf("in_file : %s\n", px->in_file);
	ft_printf("out_file : %s\n", px->out_file);
	ft_printf("\n");
	i = -1;
	while ((px->name)[++i])
		ft_printf("name : %s\n", (px->name)[i]);
	ft_printf("\n");
	i = -1;
	while ((px->path_prog)[++i])
		ft_printf("path_prog : %s\n", (px->path_prog)[i]);
	ft_printf("\n");
	i = -1;
	while ((px->cmd)[++i])
		ft_printf("cmd : %s\n", (px->cmd)[i]);
}
/*
void	parsing_normal(t_pipex *px, int argc, char **argv, char **env)
{
	int		i;
	int		j;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	px->path = ft_split(env[i] + 5, ":");
	ft_printf("2\n");
	if (px->path == NULL)
		ft_exit(px, ERROR_PARSING);
	j = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		px->in_file = argv[1];
		px->out_file = argv[argc - 1];
		px->prog = NULL;
		while (++j < argc - 1)
			add_prog(px, argv[j]);
	}
}*/

char	**get_env_path(char **env)
{
	int		i;
	char	**path_env;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path_env = ft_split(env[i] + 5, ":");
	if (path_env == NULL)
		return (NULL);
	return (path_env);
}

/*void parsing_2(t_pipex *px, char **argv, int argc)
{
	
}*/

char	*get_path_prog(char *name, char **env)
{
	int		i;
	char	*cmd_path;
	
	i = 0;
	while (env[i])
	{
		cmd_path = ft_path(env[i], name);
		if (cmd_path == NULL)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		else
			free(cmd_path);
		i++;
	}
	return (NULL);
}


void	parsing_normal(t_pipex *px, int argc, char **argv, char **env)
{
	int		i;
	char	**cmd_split;

	px->path_env = get_env_path(env);
	if (px->path_env == NULL)
		ft_exit(px, ERROR_PARSING);
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		px->in_file = argv[1];
		px->out_file = argv[argc - 1];
		px->name = (char **)ft_calloc(argc - 2, sizeof(char *));
		px->path_prog = (char **)ft_calloc(argc - 2, sizeof(char *));
		px->cmd = (char **)ft_calloc(argc - 2, sizeof(char *));
		i = 0;
		while (i < argc - 3)
		{
			(px->cmd)[i] = ft_strdup(argv[i + 2]);
			if ((px->cmd)[i] == NULL)
				return ;
			cmd_split = ft_split((px->cmd)[i], " ");
			if (cmd_split == NULL)
				return ;
			(px->name)[i] = ft_strdup(cmd_split[0]);
			free_split(cmd_split);
			(px->path_prog)[i] = get_path_prog((px->name)[i], px->path_env);
			/*Gerer le cas ou le programme n'existe pas*/
			i++;
		}
	}
}

