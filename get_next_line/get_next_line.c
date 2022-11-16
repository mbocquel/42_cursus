/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:36:22 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/15 17:36:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	process_buffer(t_list_reserve **lst_reserve, char *buffer, int fd)
{
	int				make_line;
	t_list_reserve	*new_elem_reserve;

	make_line = 0;
	new_elem_reserve = ft_add_elem_reserve(lst_reserve, buffer, fd);
	if (new_elem_reserve->pos_n != -1)
		make_line = 1;
	return (make_line);
}

int	ft_line_size(t_list_reserve **lst_reserve, int fd)
{
	int				line_size;
	t_list_reserve	*elem_reserve;

	elem_reserve = *lst_reserve;
	line_size = 0;
	if (!elem_reserve)
		return (0);
	while (elem_reserve->next)
	{
		if (elem_reserve->fd == fd && elem_reserve->pos_n == -1)
			line_size += BUFFER_SIZE;
		else if (elem_reserve->fd == fd)
			line_size += elem_reserve->pos_n + 1;
		elem_reserve = elem_reserve->next;
	}
	return (line_size);
}

char	*ft_make_ligne(t_list_reserve **lst_reserve, int fd)
{
	char			*new_line;
	int				line_size;
	t_list_reserve	*elem;

	line_size = ft_line_size(lst_reserve, fd);
	elem = *lst_reserve;
	new_line = (char *)malloc((line_size + 1) * sizeof(char));
	if (new_line == NULL || elem == NULL)
		return (NULL);
	while (elem->next)
	{
		if (elem->fd == fd)
			ft_strcat_upto(new_line, elem->data, line_size, elem->pos_n);
		elem = elem->next;
	}
	return (new_line);
}

/*C'est le premier de la liste que je supprime donc je dois changer le premier*/
void	ft_del_elem_reserve(t_list_reserve **lst_reserve,
	t_list_reserve *elem, t_list_reserve *previous)
{
	if (previous)
		previous->next = elem->next;
	if (*lst_reserve == elem)
	{
		*lst_reserve = elem->next;
		previous = NULL;
	}
	free(elem->data);
	free(elem);
}

void	ft_clean_reserve(t_list_reserve **lst_reserve, int fd)
{
	t_list_reserve	*elem;
	t_list_reserve	*next;
	t_list_reserve	*previous;
	int				i;

	elem = *lst_reserve;
	while (elem)
	{
		next = elem->next;
		if (elem->fd == fd && elem->pos_n == -1)
			ft_del_elem_reserve(lst_reserve, elem, previous);
		else if (elem->fd == fd)
		{
			i = -1;
			while (++i < BUFFER_SIZE - elem->pos_n)
				(elem->data)[i] = (elem->data)[elem->pos_n + 1 + i];
			elem->pos_n = ft_pos_str(elem->data, '\n');
			break ;
		}
		previous = elem;
		elem = next;
	}
}

char	*get_next_line(int fd)
{
	static t_list_reserve	**begin_reserve;
	char					*buffer;
	char					*next_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if ((*begin_reserve)->pos_n > 0)
		ft_make_ligne(begin_reserve, fd);
	else
	{
		while (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			if (process_buffer(begin_reserve, buffer, fd) == 1)
			{
				next_line = ft_make_ligne(begin_reserve, fd);
				ft_clean_reserve(begin_reserve, fd);
				return (next_line);
			}
		}
	}
	return (0);
}
