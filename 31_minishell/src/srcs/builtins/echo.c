/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/13 16:03:43 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_bool	valid_n(char *str)
{
	int	i;

	i = 1;
	if (!str || str[0] != '-')
		return (FALSE);
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_print_echo(char *str, int *ret)
{
	char	*working_dir;
	int		return_val;

	return_val = 0;
	working_dir = NULL;
	if (ft_strcmp(str, "~") == 0)
	{
		working_dir = getcwd(NULL, 0);
		if (working_dir != NULL)
		{
			return_val = write(1, working_dir, ft_strlen(working_dir));
			free(working_dir);
		}
	}
	else
		return_val = write(1, str, ft_strlen(str));
	if (return_val == -1 && *ret > 0)
		*ret = -1;
}

int	ft_error_echo(int ret_val)
{
	write(2, "minishell: echo: write error: No space left on device\n",
		ft_strlen("minishell: echo: write error: No space left on device\n"));
	return (ret_val);
}

int	exec_echo(char **cmd)
{
	t_bool	print_nl;
	int		i;
	int		ret;

	print_nl = TRUE;
	i = 1;
	ret = 1;
	while (cmd[i] && valid_n(cmd[i]))
	{
		print_nl = FALSE;
		i++;
	}
	while (i < get_nb_str(cmd))
	{
		ft_print_echo(cmd[i], &ret);
		if (i != get_nb_str(cmd) - 1)
			ft_print_echo(" ", &ret);
		i++;
	}
	if (print_nl == TRUE)
		ft_print_echo("\n", &ret);
	if (ret < 0)
		return (ft_error_echo(1));
	return (0);
}
