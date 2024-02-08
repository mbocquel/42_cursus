/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:00:14 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/14 14:31:17 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error_write_export(int ret_val)
{
	write(2, "minishell: export: write error: No space left on device\n",
		ft_strlen("minishell: export: write error: No space left on device\n"));
	return (ret_val);
}

int	exec_export_no_args(t_param *prm)
{
	char	**env_tab;
	int		i;

	env_tab = ft_calloc_gc(prm, prm->source.id, get_nb_str(prm->env) + 1,
			sizeof(char *));
	if (env_tab == NULL)
		return (1);
	i = -1;
	while ((prm->env)[++i])
		env_tab[i] = (prm->env)[i];
	ft_sort_strs(env_tab, get_nb_str(prm->env));
	i = -1;
	while (env_tab[++i])
	{
		if (write(1, env_tab[i], ft_strlen(env_tab[i])) == -1
			|| write(1, "\n", ft_strlen("\n")) == -1)
			return (ft_error_write_export(1));
	}
	return (0);
}

char	**ft_sort_strs(char **strs, int size)
{
	int		test_finish;
	char	*temp;
	int		i;

	test_finish = 0;
	while (test_finish == 0)
	{
		test_finish = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (ft_strcmp(strs[i], strs[i + 1]) > 0)
			{
				test_finish = 0;
				temp = strs[i];
				strs[i] = strs[i + 1];
				strs[i + 1] = temp;
			}
			i++;
		}
	}
	return (strs);
}

int	check_valid_export(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = pos_str(str, '=');
	if (len == -1 && str)
		len = ft_strlen(str);
	while (i < len)
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (2);
		if (i == 0 && ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
