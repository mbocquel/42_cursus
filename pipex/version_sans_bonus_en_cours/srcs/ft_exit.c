/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:07:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/20 16:01:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	garbage_col(t_pipex *px, void *ptr)
{
	t_gar_col	*new_garb;

	if (ptr == NULL)
		return ;
	new_garb = (t_gar_col *)malloc(sizeof(t_gar_col));
	if (new_garb == NULL)
		ft_exit(px, ERROR_MALLOC, "garbage_col -> new_garb", 0);
	new_garb->ptr = ptr;
	new_garb->next = NULL;
	if (px->garbage == NULL)
		px->garbage = new_garb;
	else
	{
		new_garb->next = px->garbage;
		px->garbage = new_garb;
	}
}

void	garbage_split(t_pipex *px, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		garbage_col(px, (void *)(strs[i]));
		i++;
	}
	garbage_col(px, (void *)strs);
}

void	empty_garbage(t_pipex *px)
{
	t_gar_col	*elem_garb;
	t_gar_col	*temp;

	elem_garb = px->garbage;
	while (elem_garb)
	{
		temp = elem_garb;
		free(elem_garb->ptr);
		elem_garb = temp->next;
		free(temp);
	}
}

char	*get_message_perror(char *s1, char *s2)
{
	char	*result_join;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result_join = (char *)malloc((len_s1 + len_s2 + 3) * sizeof(char));
	if (result_join == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result_join[i] = s1[i];
		i++;
	}
	result_join[i++] = ':';
	result_join[i] = ' ';
	while (++i < len_s1 + len_s2 + 2)
		result_join[i] = s2[i - 2 - len_s1];
	result_join[len_s1 + len_s2 + 2] = '\0';
	return (result_join);
}

void	close_fd(t_pipex *px)
{
	close(0);
	close(1);
	close(2);
	close(px->fd_in);
	close(px->fd_out);
}

int	ft_exit_child(t_pipex *px, int code_exit, char *str1, int child)
{
	ft_printf_fd(2, "je tente de fare qqch %d %d\n",child, code_exit );
	if (code_exit == ERROR_MALLOC && child == 1)
		px->error_child_1 = ft_strjoin("Error: memory allocaton problem in ", str1);
	if (code_exit == ERROR_MALLOC && child == 2)
		px->error_child_2 = ft_strjoin("Error: memory allocaton problem in ", str1);
	//if (code_exit == ERROR_PERROR && child == 1)
	//	px->erno_1 = errno;
	//if (code_exit == ERROR_PERROR && child == 2)
	//	px->erno_2 = errno;
	if (code_exit == ERROR_CMD_NOT_FOUND && child == 1)
	{
		ft_printf_fd(2, "je tente de fare qqch \n");
		px->error_child_1 = ft_strjoin("Error: command not found: ", str1);
	}
	if (code_exit == ERROR_CMD_NOT_FOUND && child == 2)
		px->error_child_2 = ft_strjoin("Error: command not found: ", str1);
	exit(EXIT_FAILURE);
}

int	ft_exit_parent(t_pipex *px, int code_exit, char *str1)
{
	int	error_child2;

	error_child2 = px->code_exit[1];
	if (code_exit == ERROR_PERROR)
		ft_printf_fd(2, "Error: %s: %s\n", strerror(errno), str1);
	if (code_exit == ERROR_MALLOC)
		ft_printf_fd(2, "Error: memory allocaton problem in %s\n", str1);
	if (code_exit == ERROR_ARG_NUM)
	{
		ft_printf_fd(2, "Error: number of argument. ");
		ft_printf_fd(2, "Usage: %s file1 \"cmd1\" \"cmd2\" file2\n", str1);
	}
	if (px->code_exit[0])
		ft_printf_fd(2, "%d\n", px->erno_1);
	if (px->code_exit[1])
		ft_printf_fd(2, "%d\n", px->erno_2);
	empty_garbage(px);
	close_fd(px);
	if (error_child2 != 0 || code_exit == ERROR_ARG_NUM || code_exit == ERROR_MALLOC)
		exit(EXIT_FAILURE);
	exit(0);
}

int	ft_exit(t_pipex *px, int code_exit, char *str1, int child)
{
	if (child == 1)
	{
		px->erno_1 = 13;
		ft_printf("px->erno_1 %p mon code d'erreur = %d\n", &(px->erno_1), code_exit);
	}
	ft_printf_fd(2,"%s\n", str1);
	//int er;

	//er = errno;
	/*if (child == 1)
		px->erno_1 = errno;*/
	//ft_printf_fd(2, "er %d, child = %d\n", er, child);
	//ft_printf_fd(2, "er %s\n", strerror(13));
	if (child == 0)
		ft_printf_fd(2, "%p je suis le parent et je regarde px->erno_1 %d\n", &(px->erno_1), px->erno_1);
	/*if (child == 0)
	{
		if (px->error_child_1)
			garbage_col(px, (void *)px->error_child_1);
		if (px->error_child_2)
			garbage_col(px, (void *)px->error_child_2);
		return (ft_exit_parent(px, code_exit, str1));
	}*/
	if (child == 0)
		exit (0);
		//return (ft_exit_parent(px, code_exit, str1));
	else
		exit (1);
		//return (ft_exit_child(px, code_exit, str1, child));
}
