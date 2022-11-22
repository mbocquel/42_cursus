/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/22 16:06:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("his_dark_materials", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
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
