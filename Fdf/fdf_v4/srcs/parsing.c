/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:15:01 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 21:22:55 by mbocquel         ###   ########.fr       */
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

static int	process_line(t_trame **begin_trame, char *line, int num_line)
{
	char			**tab_str_alt_color;
	int				col;
	t_trame			*elem;
	static t_trame	*previous = NULL;

	tab_str_alt_color = ft_split(line, " \n");
	if (!tab_str_alt_color)
		return (0);
	col = -1;
	while (tab_str_alt_color[++col])
	{
		elem = mk_trame_elem(num_line, col, tab_str_alt_color[col]);
		if (!elem)
			return (0);
		if (previous)
			previous->previous = elem;
		if (num_line > 0)
			get_tram_elem(num_line - 1, col, *begin_trame)->down = elem;
		if (col > 0)
			previous->right = elem;
		if (!trame_add_front(elem, begin_trame))
			return (0);
		previous = elem;
	}
	return (free_line_split(tab_str_alt_color));
}

t_trame	*parsing_fdf(char *fichier)
{
	int		fd;
	char	*line;
	t_trame	*begin_trame;
	int		num_line;

	fd = ft_open_fichier(fichier);
	if (fd == -1)
		return (NULL);
	num_line = 0;
	begin_trame = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(&begin_trame, line, num_line))
			break ;
		free(line);
		num_line++;
		line = get_next_line(fd);
	}
	free(line);
	if (ft_close_fichier(fd) == -1)
		return (NULL);
	return (begin_trame);
}
