/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:50:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 13:48:48 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink
*/

/*Revoir la facon dont je gere la verification de ma sortie. utiliser plutot un sem en mode mutex.
=> permet de proteger le nombre de philo qui a fini de mange, comme sur la partie obligatoire.
Permet d'eviter les Thread. 
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
	if (pthread_detach(p->thread_death) || pthread_detach(p->thread_finish))
		return (1);
	i = -1;
	while (++i < p->n_philo)
		waitpid((p->tab_philo)[i].pid, NULL, 0);
	return (0);
}
/*
int	check_if_stop(t_param *param)
{
	int	result;
	result = 0;
	
	pthread_mutex_lock(&(param->mutex_death));
	if (param->death)
		result = 1;
	pthread_mutex_unlock(&(param->mutex_death));
	pthread_mutex_lock(&(param->mutex_n_finished));
	if (param->n_finished == param->n_philo)
		result = 1;
	pthread_mutex_unlock(&(param->mutex_n_finished));
	return (result);
}
*/
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
