/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:15:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/31 12:24:40 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_fdf_extention(char *str)
{
	if (ft_strlen(str) < 4)
		return (0);
	if (str[ft_strlen(str) - 4] != '.')
		return (0);
	if (str[ft_strlen(str) - 3] != 'f')
		return (0);
	if (str[ft_strlen(str) - 2] != 'd')
		return (0);
	if (str[ft_strlen(str) - 1] != 'f')
		return (0);
	return (1);
}

int	ft_open_fichier(char *fichier)
{
	int	fd;

	if (ft_check_fdf_extention(fichier) == 0)
	{
		ft_printf("Error : The file extetion is not valid\n");
		return (-1);
	}
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error : Open failed\n");
	}
	return (fd);
}

int	ft_close_fichier(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		ft_printf("Error : Closed failed\n");
	}
	return (result);
}

static int	process_line(t_trame **begin_trame, char **tab, int num_l, int *e)
{
	int				col;
	t_trame			*elem;
	static t_trame	*elem_created_before = NULL;

	if (!tab)
		*e = 0;
	if (!tab[0])
		return (free_line_split(tab, 0));
	col = -1;
	while (tab[++col] && *e == 0)
	{
		elem = mk_trame_elem(num_l, col, tab[col]);
		if (!elem)
			return (free_line_split(tab, 0));
		if (elem_created_before)
			elem_created_before->previous = elem;
		if (num_l > 0)
			get_tram_elem(num_l - 1, col, *begin_trame)->down = elem;
		if (col > 0)
			elem_created_before->right = elem;
		trame_add_front(elem, begin_trame);
		elem_created_before = elem;
	}
	return (free_line_split(tab, 1));
}

t_trame	*parsing_fdf(char *fichier)
{
	int		fd;
	char	*line;
	t_trame	*trame;
	int		nline;
	int		e;

	e = 0;
	fd = ft_open_fichier(fichier);
	if (fd == -1)
		return (NULL);
	nline = 0;
	trame = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!e && !process_line(&trame, ft_split(line, " \n"), nline, &e))
			e = 1;
		free(line);
		nline++;
		line = get_next_line(fd);
	}
	free(line);
	if (ft_close_fichier(fd) == -1 || e)
		return (NULL);
	return (trame);
}
