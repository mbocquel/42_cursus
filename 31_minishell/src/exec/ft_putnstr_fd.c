/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:42:18 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/10 11:40:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_put2str_fd(char *s1, char *s2, int fd)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (tmp == NULL)
		return ;
	ft_putstr_fd(tmp, fd);
	free(tmp);
}

void	ft_put3str_fd(char *s1, char *s2, char *s3, int fd)
{
	char	*tmp;

	tmp = ft_strjoin3(s1, s2, s3);
	if (tmp == NULL)
		return ;
	ft_putstr_fd(tmp, fd);
	free(tmp);
}
