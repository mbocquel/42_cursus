/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 04:01:22 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/10 14:20:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_exit_2(t_param *prm, char *arg[])
{
	if (arg == NULL || arg[0] == NULL || ft_strcmp(arg[0], "exit"))
	{
		empty_garbage(prm, -1);
		rl_clear_history();
		exit(0);
	}
	if (arg[1] && !ft_isint(arg[1]))
	{
		ft_printf("minishell: exit: %s: numeric argument required\n",
			arg[1]);
		g_return_value = 2;
	}
	else if (get_nb_str(arg) > 2)
	{
		ft_printf("minishell: exit: too many arguments\n");
		g_return_value = 1;
		return (1);
	}
	else if (arg[1] && ft_isint(arg[1]))
		g_return_value = ft_atoi(arg[1]);
	else
		g_return_value = 0;
	empty_garbage(prm, -1);
	rl_clear_history();
	exit(g_return_value);
}

int	exec_exit(t_param *prm, char *arg[])
{
	ft_printf("exit\n");
	return (exec_exit_2(prm, arg));
}
