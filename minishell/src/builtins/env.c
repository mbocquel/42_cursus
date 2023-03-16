/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:06:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/10 15:36:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_last_return(t_param *prm)
{
	char	*result;

	result = ft_itoa((int)g_return_value);
	if (result == NULL)
		return ("");
	garbage_col(prm, prm->source.id, result);
	return (result);
}

char	*get_env_var(t_param *prm, char *name)
{
	int		i;
	size_t	len_name;
	size_t	len;
	size_t	pos;

	i = 0;
	if (ft_strcmp(name, "?") == 0)
		return (get_last_return(prm));
	len_name = ft_strlen(name);
	while (prm->env && prm->env[i])
	{
		len = len_name;
		pos = pos_str(prm->env[i], '=');
		if (pos > len_name)
			len = pos;
		if (ft_strncmp(prm->env[i], name, len) == 0)
			return (prm->env[i] + pos + 1);
		i++;
	}
	return ("");
}

int	export_env(t_param *prm, char *str)
{
	char	**new_env;
	int		i;

	if (check_valid_export(str))
		return (check_valid_export(str));
	if (pos_str(str, '=') == -1)
		return (0);
	unset_env(prm, ft_substr_gc(prm, str, 0, pos_str(str, '=')));
	new_env = ft_calloc_gc(prm, 0, get_nb_str(prm->env) + 2, sizeof(char *));
	if (new_env == NULL)
		return (1);
	i = -1;
	while (prm->env && prm->env[++i])
	{
		new_env[i] = ft_strdup_gc(prm, 0, prm->env[i]);
		if (new_env[i] == NULL)
			return (1);
	}
	new_env[i] = ft_strdup_gc(prm, 0, str);
	if (new_env[i] == NULL)
		return (1);
	garbage_env(prm);
	prm->env = new_env;
	return (0);
}

int	pos_in_env(t_param *prm, char *str)
{
	int		i;
	size_t	len;
	size_t	len_str;

	i = 0;
	if (str == NULL)
		return (-1);
	len_str = ft_strlen(str);
	while (prm->env && prm->env[i])
	{
		len = len_str;
		if ((size_t)pos_str(prm->env[i], '=') > len_str)
			len = (size_t)pos_str(prm->env[i], '=');
		if (ft_strncmp(prm->env[i], str, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	unset_env(t_param *prm, char *str)
{
	char	**new_env;
	int		len_env;
	int		i;
	int		j;

	len_env = get_nb_str(prm->env);
	if (pos_in_env(prm, str) == -1)
		return (0);
	new_env = ft_calloc_gc(prm, 0, len_env, sizeof(char *));
	if (new_env == NULL)
		return (1);
	i = -1;
	j = 0;
	while (++i < len_env)
	{
		if (i == pos_in_env(prm, str))
			continue ;
		new_env[j] = ft_strdup_gc(prm, 0, prm->env[i]);
		if (new_env[j] == NULL)
			return (1);
		j++;
	}
	garbage_env(prm);
	prm->env = new_env;
	return (0);
}
