/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/18 17:02:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("test_a_lire", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%d %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
	{
		printf("Closed failed\n");
		return (1);
	}
}
