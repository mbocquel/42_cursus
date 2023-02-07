/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:41:42 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/01 17:18:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_len(char *str)
{
	int	i; 
	
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int		len_1;
	int		len_2;
	int		i;
	char	*join;

	len_1 = ft_len(s1);
	len_2 = ft_len(s2);
	i = 0;
	join = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	join[len_1 + len_2] = '\0';
	while (i < len_1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len_1 + len_2)
	{
		join[i] = s2[i - len_1];
		i++;
	}
	return (join);
}

char *ft_substr(char *str, unsigned int start, unsigned int len_sub)
{
	unsigned int		len_max;
	char	*sub;
	unsigned int		i;

	len_max = len_sub;
	if (start >= (unsigned int)ft_len(str))
		len_max = 0;
	else if ((unsigned int)ft_len(str) - start < len_sub)
		len_max = ft_len(str) - start;
	sub = (char *)malloc((len_max + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[len_max] = '\0';
	i = 0;
	while (i < len_max)
	{
		sub[i] = str[start + i];
		i++;
	}
	return (sub);
}

int get_pos_n(char *str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *make_line(char *storage)
{
	int		pos_n;
	char	*line; 
	
	if (storage == NULL)
		return (NULL);
	pos_n = get_pos_n(storage);
	if (pos_n == -1)
		line = ft_substr(storage, 0, ft_len(storage));
	else
		line = ft_substr(storage, 0, pos_n + 1);
	return (line);
}

char *clean_storage(char *storage)
{
	int		pos_n;
	char	*new_storage;

	new_storage = NULL;
	pos_n = get_pos_n(storage);
	if (pos_n > -1 && pos_n != ft_len(storage) - 1)
		new_storage = ft_substr(storage, pos_n + 1, ft_len(storage));
	free(storage);
	return (new_storage);
}

int	read_and_store(int fd, char **storage)
{
	int	 char_read;
	char *buffer;
	char  *new_storage;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		if (*storage != NULL)
			free(*storage);
		return (-1);
	}
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read <= 0)
	{
		free(buffer);
		return (char_read);
	}
	buffer[char_read] = '\0'; 
	new_storage = ft_strjoin(*storage, buffer);
	if (*storage != NULL)
			free(*storage);
	free(buffer);
	*storage = new_storage;
	return (char_read);
}

char *get_next_line(int fd)
{
	static char *storage = NULL;
	int			char_read;
	char		*line;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	char_read = BUFFER_SIZE;
	while (char_read > 0 && get_pos_n(storage) == -1)
	{
		char_read = read_and_store(fd, &storage);
	}
	if (storage)
	{
		line = make_line(storage);
		storage = clean_storage(storage);
	}
	if (char_read == 0)
		free(storage);
	return (line);
}
/*
int	main(void)
{
	int fd;
	char *line;

	line = NULL;
	fd = open("his_dark_materials", O_RDONLY);
	if (fd != -1)
	{
		line = get_next_line(fd);
		
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	}
	free(line);
	return (0);
}*/