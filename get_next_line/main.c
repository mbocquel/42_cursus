/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 16:43:45 by mbocquel         ###   ########.fr       */
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
	int fd;
	char *line;

	fd = open("test_a_lire", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("next line : %s\n",line);

	if (close(fd) == -1)
	{
		printf("Closed failed\n");
		return (1);
	}
	// buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (buffer == NULL)
	// 	return (1);
	// buffer[BUFFER_SIZE] = '\0';
	// read(fd, buffer, BUFFER_SIZE);
	
	// begin_reserve = malloc(sizeof(t_list_reserve *));
	// *begin_reserve = ft_add_elem_reserve(begin_reserve, buffer, fd);
	
	
	/*
	elem_reserve = malloc(sizeof(t_list_reserve));
	if (elem_reserve == NULL)
		return (1);
	elem_reserve->next = NULL;
	elem_reserve->data = ft_strdup(buffer);
	elem_reserve->fd = fd;
	elem_reserve->pos_n = ft_pos_str(buffer, '\n');

	*begin_reserve = elem_reserve;
	// */
	// printf("Premiere lecture :\n");
	// ft_add_elem_reserve(begin_reserve, buffer, fd);

	// voir_elem_chaine(*begin_reserve);

	// printf("Seconde lecture :\n");


	// read(fd, buffer, BUFFER_SIZE);

	// ft_add_elem_reserve(begin_reserve, buffer, fd);


	// voir_elem_chaine(*begin_reserve);



	// if (close(fd) == -1)
	// {
	// 	printf("Closed failed\n");
	// 	return (1);
	// }

	// return (0);
}
