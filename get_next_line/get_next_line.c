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

static int	process_buffer(t_list_reserve **lst_reserve, char *buffer)
{
	int	make_line;

	make_line = 0;
	return (make_line);
}

static int ft_line_size(t_list_reserve **lst_reserve)
{
	int	line_size;

	return (line_size);
}

static	char	*ft_make_ligne(t_list_reserve **lst_reserve)
{
	char	*new_line;

	return (new_line);
}

static void	ft_clean_reserve(t_list_reserve **lst_reserve)
{

}

char	*get_next_line(int fd)
{
	static t_list_reserve **begin_reserve;
	char	*buffer;
	char	*next_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if ((*begin_reserve)->pos_n > 0)
		ft_make_ligne(begin_reserve);
	else
	{
		while (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			if (process_buffer(*begin_reserve, buffer) == 1)
			{
				next_line = ft_make_ligne(*begin_reserve);
				ft_clean_reserve(*begin_reserve);
				return (next_line);
			}
		}
	}
}
