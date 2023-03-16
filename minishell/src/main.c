/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:32:12 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/14 14:26:58 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

unsigned char	g_return_value = 0;

int	main(int argc, char *argv[], char *env[])
{
	char	*cmd;
	t_param	prm;
	t_node	*root;

	(void)argv;
	cmd = NULL;
	if (argc != 1)
		return (ft_printf_fd(2, "minishell: too many arguments\n"), 1);
	ft_memset(&prm, 0, sizeof(t_param));
	clone_env(&prm, env);
	print_minishell_title();
	while (1)
	{
		init_signal();
		readline_new_prompt(&cmd);
		if (cmd == NULL)
			exec_exit(&prm, NULL);
		if (ft_strlen(cmd) > 0)
			add_history(cmd);
		root = parse(&prm, cmd);
		if (root != NULL)
			exec_root(&prm, root);
	}
	return (g_return_value);
}
