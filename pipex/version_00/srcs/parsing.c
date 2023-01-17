/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:11:55 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 15:53:10 by mbocquel         ###   ########.fr       */
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

char	**get_env_path(t_pipex *px, char **env)
{
	int		i;
	char	**path_env;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path_env = ft_split(env[i] + 5, ":");
	if (path_env == NULL)
		return (NULL);
	garbage_split(px, path_env);
	return (path_env);
}

char	*get_path_prog(t_pipex *px, char *name)
{
	int		i;
	char	*cmd_path;
	char	**path_strs;	

	i = 0;
	path_strs = px->path_env;
	while (path_strs[i])
	{
		cmd_path = ft_path(path_strs[i], name);
		if (cmd_path == NULL)
			ft_exit(px, ERROR_PARSING);
		else
			garbage_col(px, (void *)cmd_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

int	add_cmd(t_pipex *px, char *cmd)
{
	t_cmd	*new;
	char	**cmd_split;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (ft_exit(px, ERROR_PARSING));
	garbage_col(px, (void *)new);
	cmd_split = ft_split(cmd, " ");
	if (cmd_split == NULL)
		return (ft_exit(px, ERROR_PARSING));
	garbage_split(px, cmd_split);
	new->cmd_split = cmd_split;
	new->next = NULL;
	if (px->cmd == NULL)
		px->cmd = new;
	else
	{
		new->next = px->cmd;
		px->cmd = new;
	}
	return (0);
}

void	parsing_normal(t_pipex *px, int argc, char **argv, char **env)
{
	int	i;

	i = argc - 2;
	px->path_env = get_env_path(px, env);
	if (px->path_env == NULL)
		ft_exit(px, ERROR_PARSING);
	px->in_file = argv[1];
	px->out_file = argv[argc - 1];
	while (i > 1)
	{
		add_cmd(px, argv[i]);
		i--;
	}
}
