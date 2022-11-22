/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/22 18:00:35 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd_1;
	int		fd_2;
	char	*line;
	
	fd_1 = open("his_dark_materials", O_RDONLY);
	if (fd_1 == -1)
	{
		printf("Open failed\n");
		return (1);
	}
 	fd_2 = open("foundation", O_RDONLY);
	if (fd_2 == -1)
	{
		printf("Open failed\n");
		return (1);
	}
 
	line = get_next_line(fd_1);
	printf("FD %d -> %s", fd_1, line);
	free(line);

	line = get_next_line(fd_2);
	printf("FD %d -> %s", fd_2, line);
	free(line); 

	line = get_next_line(fd_1);
	printf("FD %d -> %s", fd_1, line);
	free(line);

	line = get_next_line(fd_2);
	printf("FD %d -> %s", fd_2, line);
	free(line); 

	if (close(fd_1) == -1)
	{
		printf("Closed fd_1 failed\n");
		return (1);
	}
 	if (close(fd_2) == -1)
	{
		printf("Closed fd_2 failed\n");
		return (1);
	} 
}
