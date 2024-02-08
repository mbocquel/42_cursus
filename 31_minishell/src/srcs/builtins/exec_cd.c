/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:40 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/13 15:33:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	change_pwd_env(t_param *prm, char *old_pwd)
{
	char	*new_pwd;
	int		ret;

	ret = 0;
	new_pwd = getcwd(NULL, 0);
	garbage_col(prm, prm->source.id, new_pwd);
	old_pwd = ft_strjoin_gc(prm, 0, "OLDPWD=", old_pwd);
	new_pwd = ft_strjoin_gc(prm, 0, "PWD=", new_pwd);
	ret += unset_env(prm, "OLDPWD");
	ret += unset_env(prm, "PWD");
	ret += export_env(prm, old_pwd);
	ret += export_env(prm, new_pwd);
	return (ret);
}

int	ft_error_cd(int n_error, int return_value, char *str)
{
	if (n_error == 1)
		ft_printf("minishell: cd: too many arguments\n");
	else if (n_error == 2)
		ft_printf("minishell: cd: %s: No such file or directory\n", str);
	else if (n_error == 3)
		ft_printf("minishell: cd: HOME not set\n", str);
	g_return_value = 1;
	return (return_value);
}

int	exec_cd(t_param *prm, char *arg[])
{
	char	*new_path;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	garbage_col(prm, prm->source.id, old_pwd);
	if (get_nb_str(arg) > 2)
		return (ft_error_cd(1, 1, NULL));
	if (get_nb_str(arg) == 1)
	{
		new_path = get_env_var(prm, "HOME");
		if (ft_strcmp(new_path, "") == 0)
			return (ft_error_cd(3, 1, NULL));
	}
	else
		new_path = arg[1];
	if (chdir(new_path) == -1)
	{
		new_path = ft_strjoin_gc(prm, prm->source.id, "./", new_path);
		if (chdir(new_path) == -1)
			return (ft_error_cd(2, 1, new_path));
	}
	if (change_pwd_env(prm, old_pwd))
		return (1);
	return (0);
}
