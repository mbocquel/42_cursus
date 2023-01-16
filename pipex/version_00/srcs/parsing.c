/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:11:55 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/16 20:03:55 by mbocquel         ###   ########.fr       */
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
	while (++i <= len_s1 + len_s2)
	{
		result_join[i] = s2[i - len_s1];
	}
	result_join[len_s1 + len_s2 + 1] = '\0';
	return (result_join);
}

void get_path(char *str, char **env)
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
}

int	add_prog(t_pipex *px, char *cmd)
{
	char	**cmd_split;
	char	*cmd_path;
	int		i;
	t_prog	*new;

	i = 0;
	new = (t_prog *)malloc(sizeof(t_prog *));
	if (new == NULL)
		return(ft_exit(px, ERROR_PARSING));
	cmd_split = ft_split(cmd, " ");
	if (cmd_split == 0)
		return(ft_exit(px, ERROR_PARSING));
	while ((px->path)[i])
	{
		cmd_path = ft_path((px->path)[i], cmd_split[0]);
		if (cmd_path == NULL)
			return (ft_exit(px, ERROR_PARSING));
		if (access(cmd_path, F_OK) == 0)
			break ;
		else
			free(cmd_path);
	}
	new->name = cmd_split[0];
	new->path_prog = cmd_path;
	new->args = cmd_split + 1;
	new->next = NULL;
	if (px->prog == NULL)
		px->prog = new;
	else
	{
		new->next = px->prog;
		px->prog = new;
	}
	return (0);
}

void	print_prog(t_pipex *px)
{
	t_prog	*prog;
	int		i;

	prog = px->prog;
	while (prog)
	{
		ft_printf("name : %s\n", prog->name);
		ft_printf("path_prog : %s\n", prog->path_prog);
		i = -1;
		while (prog->args[++i])
			ft_printf("arg : %s\n", prog->args[++i]);
		prog = prog->next;
	}
}

void	parsing_normal(t_pipex *px, int argc, char **argv, char **env)
{
	int		i;
	int		j;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	px->path = ft_split(env[i] + 5, ":");
	if (px->path == NULL)
		return(ft_exit(px, ERROR_PARSING));
	j = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		px->in_file = argv[1];
		px->out_file = argv[argc - 1];
		px->prog = NULL;
		while (++j < argc - 1)
			add_prog(px, argv[j]);
	}
}
