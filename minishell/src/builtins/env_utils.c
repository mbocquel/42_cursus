/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:20:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/14 14:35:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error_print_env(int ret_val)
{
	write(2, "minishell: env: write error: No space left on device\n",
		ft_strlen("minishell: env: write error: No space left on device\n"));
	return (ret_val);
}

int	print_env(t_param *prm)
{
	int	i;

	i = 0;
	if (prm->env == NULL && write(1, "\n", ft_strlen("\n")) == -1)
		return (ft_error_print_env(1));
	while (prm->env[i])
	{
		if (write(1, prm->env[i], ft_strlen(prm->env[i])) == -1)
			return (ft_error_print_env(1));
		if (write(1, "\n", ft_strlen("\n")) == -1)
			return (ft_error_print_env(1));
		i++;
	}
	return (0);
}

void	garbage_env(t_param *prm)
{
	int	i;

	i = -1;
	while (prm->env && prm->env[++i])
		remove_from_garb(prm, prm->env[i]);
	remove_from_garb(prm, prm->env);
}

int	increment_shlvl(t_param *prm)
{
	char	*new_level;
	char	*new_shlvl;

	new_level = ft_itoa(ft_atoi(get_env_var(prm, "SHLVL")) + 1);
	if (new_level == NULL)
		return (1);
	unset_env(prm, "SHLVL");
	new_shlvl = ft_strjoin_gc(prm, 0, "SHLVL=", new_level);
	free(new_level);
	if (new_shlvl == NULL)
		return (1);
	export_env(prm, new_shlvl);
	return (0);
}

void	clone_env(t_param *prm, char **env)
{
	int	i;

	prm->env = ft_calloc_gc(prm, 0, get_nb_str(env) + 1, sizeof(char *));
	if (prm->env == NULL)
	{
		empty_garbage(prm, -1);
		exit (1);
	}
	i = -1;
	while (env && env[++i])
	{
		(prm->env)[i] = ft_strdup_gc(prm, 0, env[i]);
		if ((prm->env)[i] == NULL)
		{
			empty_garbage(prm, -1);
			exit (1);
		}
	}
	if (increment_shlvl(prm))
	{
		empty_garbage(prm, -1);
		exit (1);
	}
}
