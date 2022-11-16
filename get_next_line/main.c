/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/16 16:59:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;

	fd = open("test_a_lire", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}
	printf("fd est %d\n", fd);
	//printf("%s\n", get_next_line(fd));

	//static t_list_reserve	**begin_reserve;
	char					*buffer;
	//char					*next_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (1);
	buffer[BUFFER_SIZE] = '\0';
	read(fd, buffer, BUFFER_SIZE);
	printf("Buffersize %d - %s",BUFFER_SIZE, buffer);
	/*if ((*begin_reserve)->pos_n > 0)
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
	*/
	if (close(fd) == -1)
	{
		printf("Closed failed\n");
		return (1);
	}

	return (0);
}
