/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:25:48 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/13 17:57:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *args)
{
	t_param *p;

	p = (t_param *)args;
	sleep(5);
	sem_post(p->sem_death);
	return (NULL);
}

void	fonction_child(t_param *p)
{
	p->sem_death = sem_open("sem", O_RDWR);
	sleep(5);
	sem_post(p->sem_death);
}

int	test(t_param *p)
{
	int pid;
	
//	pthread_create(&(p->thread_finish), NULL, monitor, (void *)p);
	p->sem_death = sem_open("sem", O_CREAT, 0644, 0); 
	pid = fork();
	if (pid == 0)
	{
		fonction_child(p);
	}
	if (pid != 0)
	{
		printf("Avant %p\n", p->sem_death);
		sem_wait(p->sem_death);
		printf("Apres %p\n", p->sem_death);
		sem_close(p->sem_death);
	}	
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	memset(&param, 0, sizeof(t_param));
	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of argument\n", 32));
	parsing(&param, argv);
	
	test(&param);
	
	//	return (1);
	
	return (0);
}
