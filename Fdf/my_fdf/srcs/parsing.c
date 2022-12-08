/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:15:01 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:16:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_open_fichier(char *fichier)
{
	int	fd;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Open failed\n");
	}
	return (fd);
}

int	ft_close_fichier(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		ft_printf("Closed failed\n");
	}
	return (result);
}

static int	lstadd_newline(t_map **begin_map, int num_line,
	int *line_int, int nb_col)
{
	t_map	*new;
	t_map	*elem;

	new = malloc(sizeof(t_map));
	if (!new)
		return (0);
	new->next = NULL;
	new->n_line = num_line;
	new->line_int = line_int;
	new->nb_col = nb_col;
	if (*begin_map == NULL)
	{
		*begin_map = new;
		return (1);
	}
	elem = *begin_map;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return (1);
}

static int	process_line(t_map **begin_map, char *line, int num_line)
{
	char	**line_tab_char;
	int		i;
	int		*line_int;
	int		nb_col;

	line_tab_char = ft_split(line, " \n");
	i = 0;
	while (line_tab_char[i])
		i++;
	nb_col = i;
	line_int = (int *)ft_calloc(nb_col, sizeof(int));
	if (line_int == NULL)
		return (0);
	i = -1;
	while (line_tab_char[++i])
		line_int[i] = ft_atoi(line_tab_char[i]);
	free_tab_char(line_tab_char);
	if (lstadd_newline(begin_map, num_line, line_int, nb_col))
		return (1);
	return (0);
}

t_map	*parsing_fdf(char *fichier)
{
	int		fd;
	char	*line;
	t_map	*begin_map;
	int		num_line;

	fd = ft_open_fichier(fichier);
	if (fd == -1)
		return (NULL);
	num_line = 0;
	begin_map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(&begin_map, line, num_line))
			break ;
		free(line);
		num_line++;
		line = get_next_line(fd);
	}
	free(line);
	if (ft_close_fichier(fd) == -1)
		return (NULL);
	return (begin_map);
}
