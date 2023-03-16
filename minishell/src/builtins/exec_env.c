/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:20:38 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/13 17:02:05 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_env(t_param *prm, char **cmd)
{
	if (cmd == NULL || cmd[0] == NULL || ft_strlen(cmd[0]) != 3
		|| ft_strncmp(cmd[0], "env", 3) != 0)
		return (1);
	return (print_env(prm));
}

int	exec_export(t_param *prm, char **cmd)
{
	int	i;
	int	ret_val;

	i = 1;
	ret_val = 0;
	if (get_nb_str(cmd) == 1)
		return (exec_export_no_args(prm));
	while (i < get_nb_str(cmd))
	{
		ret_val += export_env(prm, cmd[i]);
		if (ret_val != 0)
		{
			ft_put3str_fd("minishell: export: `", cmd[i],
				"`: not a valid identifier\n", 2);
			break ;
		}
		i++;
	}
	return (ret_val);
}

int	exec_unset(t_param *prm, char **cmd)
{
	int	i;
	int	ret_val;

	i = 1;
	ret_val = 0;
	if (cmd == NULL || cmd[0] == NULL || ft_strlen(cmd[0]) != 5
		|| ft_strncmp(cmd[0], "unset", 5) != 0)
		return (1);
	while (i < get_nb_str(cmd))
	{
		ret_val += unset_env(prm, cmd[i]);
		i++;
	}
	return (ret_val);
}
