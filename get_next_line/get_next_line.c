/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:22:18 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/18 17:08:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_sto	*storage = NULL;
	char				*buffer;
	char				*next_line;
	int					char_read;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	char_read = BUFFER_SIZE;
	while (line_to_make(storage) == 0 && char_read == BUFFER_SIZE)
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (buffer == NULL)
			return (NULL);
		char_read = read_and_add_to_storage(&storage, buffer, fd);
		free (buffer);
		if (char_read == 0)
			return (NULL);
	}
	next_line = make_next_line(&storage);
	clean_storage(&storage);
	if(char_read < BUFFER_SIZE)
	{
		free(storage->content);
		free(storage);
	}
	return (next_line);
}

int	read_and_add_to_storage(t_list_sto **storage, char *buffer, int fd)
{
	int	char_read;

	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read > 0)
		ft_lstadd_back(storage, ft_lstnew(ft_strdup(buffer)));
	return (char_read);
}

int	line_to_make(t_list_sto *storage)
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

char	*make_next_line(t_list_sto **storage)
{
	int			j;
	int			i;
	t_list_sto	*elem;
	char		*next_line;

	next_line = (char *)ft_calloc(ft_line_len(*storage) + 2, sizeof(char));
	if (next_line == NULL)
		return (NULL);
	j = -1;
	elem = *storage;
	while (elem)
	{
		i = -1;
		while ((elem->content)[++i] && (elem->content)[i] != '\n')
			next_line[++j] = (elem->content)[i];
		elem = elem->next;
	}
	next_line[++j] = '\n';
	return (next_line);
}

void	clean_storage(t_list_sto **storage)
{
	t_list_sto	*elem;
	t_list_sto	*next;
	int			i;
	int			j;

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
	while (++j < BUFFER_SIZE - i - 1)
		(elem->content)[j] = (elem->content)[i + 1 + j];
	while (j < BUFFER_SIZE)
		(elem->content)[j++] = '\0';
	*storage = elem;
}

