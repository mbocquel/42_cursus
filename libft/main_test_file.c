/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:59:25 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/10 14:59:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int fd;

	fd = open("mon_fichier", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_fd("Open failed\n", 1);
		return (1);
	}
	ft_putstr_fd("Test", fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Closed failed\n", 1);
		return (1);
	}

	fd = open("mon_fichier2", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_fd("Open failed\n", 1);
		return (1);
	}
	ft_putchar_fd('Z', fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Closed failed\n", 1);
		return (1);
	}

	fd = open("mon_fichier3", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_fd("Open failed\n", 1);
		return (1);
	}
	ft_putendl_fd("Coucou", fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Closed failed\n", 1);
		return (1);
	}

	fd = open("mon_fichier4", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_fd("Open failed\n", 1);
		return (1);
	}
	ft_putnbr_fd(254587, fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Closed failed\n", 1);
		return (1);
	}


	return (0);
}
