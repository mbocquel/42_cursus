/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:50:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 16:47:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink
*/

int	start_simulation(t_param *p)
{
	int	i;

	i = -1;
	while (++i < p->n_philo)
	{
		(p->tab_philo)[i].pid = fork();
		if ((p->tab_philo)[i].pid == -1)
			return (1);
		if ((p->tab_philo)[i].pid == 0)
			routine_philo(&((p->tab_philo)[i]));
	}
	if (pthread_create(&(p->thread_death), NULL, monitor_death, (void *)p))
		return (1);
	if (pthread_create(&(p->thread_finish), NULL, monitor_finish, (void *)p))
		return (1);
	pthread_join(p->thread_death, NULL);
	pthread_join(p->thread_finish, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	memset(&param, 0, sizeof(t_param));
	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of argument\n", 32));
	if (parsing(&param, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (ft_exit(&param, 0, EXIT_ERROR));
	}
	if ((param.n_meals == -1 || param.n_meals > 0)
		&& start_simulation(&param) != 0)
		return (ft_exit(&param, 0, EXIT_ERROR));
	return (ft_exit(&param, 0, EXIT_SUCCESS));
}
