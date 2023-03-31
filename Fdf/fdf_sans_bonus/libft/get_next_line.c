/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:22:18 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 17:20:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_list_sto	*storage[1024] = {NULL};
	char				*buffer;
	char				*next_line;
	int					char_read;
	int					error;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	char_read = BUFFER_SIZE;
	error = 0;
	while (line_to_make_gnl(storage[fd]) == 0 && char_read > 0 && error == 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			error = 1;
		char_read = read_store_gnl(&(storage[fd]), buffer, fd, &error);
		free(buffer);
	}
	next_line = make_next_line(&(storage[fd]), &error);
	clean_storage_gnl(&(storage[fd]));
	if ((char_read == 0 && storage[fd] != NULL) || error != 0)
		clear_all_memory_gnl(&(storage[fd]));
	if (error != 0)
		return (NULL);
	return (next_line);
}

int	read_store_gnl(t_list_sto **storage, char *buffer, int fd, int *error)
{
	int		char_read;
	char	*content;
	int		i;

	i = 0;
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read > 0)
	{
		buffer[char_read] = '\0';
		content = (char *)malloc((char_read + 1) * sizeof(char));
		if (content == NULL)
			*error = 1;
		else
		{
			i = -1;
			while (buffer[++i])
				content[i] = buffer[i];
			content[i] = '\0';
			ft_lstadd_back_gnl(storage, content);
		}
	}
	if (char_read == -1)
		*error = 1;
	return (char_read);
}

int	line_to_make_gnl(t_list_sto *storage)
{
	t_list_sto	*elem;
	int			i;

	elem = storage;
	i = 0;
	while (elem)
	{
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	while (elem && (elem->content)[i])
	{
		if ((elem->content)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*make_next_line(t_list_sto **storage, int *error)
{
	int			j;
	int			i;
	t_list_sto	*elem;
	char		*next_line;

	if (*storage == NULL || ft_line_len(*storage) == 0)
		return (NULL);
	next_line = (char *)ft_calloc(ft_line_len(*storage) + 1, sizeof(char));
	if (next_line == NULL)
	{
		*error = 1;
		return (NULL);
	}
	j = -1;
	elem = *storage;
	while (elem)
	{
		i = -1;
		while ((elem->content)[++i] && (elem->content)[i] != '\n')
			next_line[++j] = (elem->content)[i];
		if ((elem->content)[i] && (elem->content)[i] == '\n')
			next_line[++j] = '\n';
		elem = elem->next;
	}
	return (next_line);
}

void	clean_storage_gnl(t_list_sto **storage)
{
	t_list_sto	*elem;
	t_list_sto	*next;
	int			i;
	int			j;

	if (*storage == NULL)
		return ;
	elem = *storage;
	while (elem->next)
	{
		next = elem->next;
		free(elem->content);
		free(elem);
		elem = next;
	}
	i = 0;
	while ((elem->content)[i] && (elem->content)[i] != '\n')
		i++;
	j = -1;
	while (++j < (int)ft_strlen(elem->content) - 1 - i
		&& (elem->content)[i + 1 + j])
		(elem->content)[j] = (elem->content)[i + 1 + j];
	(elem->content)[j] = '\0';
	*storage = elem;
}
