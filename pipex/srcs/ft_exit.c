/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/06 12:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_fd(t_pipex *px)
{
	int	res;

	res = 0;
	if (px->fd_in != -1)
	{
		if (close(px->fd_in) == -1)
			res = -1;
	}
	if (px->fd_out != -1)
	{
		if (close(px->fd_out) == -1)
			res = -1;
	}
	return (res);
}

int	close_pipe(int pipe[2])
{
	int	res;

	res = 0;
	if (close(pipe[0]) == -1)
		res = -1;
	if (close(pipe[1]) == -1)
		res = -1;
	return (res);
}

int	ft_exit_child(t_pipex *px, int code_exit, char *str1)
{
	char	*message_short;
	char	*message_long;

	message_short = NULL;
	message_long = NULL;
	if (code_exit == ERROR_MALLOC)
		message_short = ft_strjoin("Error: memory allocaton problem in ", str1);
	else if (code_exit == ERROR_CMD_NOT_FOUND)
		message_short = ft_strjoin(str1, ": command not found");
	else if (code_exit == ERROR_PERROR)
		message_short = ft_strjoin_2(str1, ": ", strerror(errno));
	message_long = ft_strjoin(message_short, "\n");
	if (message_long && write(2, message_long, ft_strlen(message_long)))
		free(message_long);
	else
		free(message_long);
	empty_garbage(px);
	close_fd(px);
	free(message_short);
	exit(EXIT_FAILURE);
}

int	ft_exit_parent(t_pipex *px, int code_exit, char *str1)
{
	if (code_exit == ERROR_PERROR)
		ft_printf_fd(2, "Error: %s: %s\n", strerror(errno), str1);
	if (code_exit == ERROR_MALLOC)
		ft_printf_fd(2, "Error: memory allocaton problem in %s\n", str1);
	empty_garbage(px);
	close_fd(px);
	if (px->code_exit_last != 0 || code_exit == ERROR_PERROR
		|| code_exit == ERROR_ARG_NUM || code_exit == ERROR_MALLOC)
		exit(EXIT_FAILURE);
	exit(0);
}

int	ft_exit(t_pipex *px, int code_exit, char *str1, int child)
{
	if (child == 0)
		return (ft_exit_parent(px, code_exit, str1));
	else
		return (ft_exit_child(px, code_exit, str1));
}
