/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/21 19:25:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	//int		i;

	fd = open("gnlTester/files/nl", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}
	printf("GNL 1 :");
	line = get_next_line(fd);
	printf("%s", line);
	free (line);

	printf("GNL 2 :");
	line = get_next_line(fd);
	printf("%s", line);
	free (line);

/*
	printf("GNL 3 :");
	line = get_next_line(fd);
	printf("%s", line);
	 i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line); */
	if (close(fd) == -1)
	{
		printf("Closed failed\n");
		return (1);
	}
}
