/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 18:16:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

void	*start_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
	{
		print_activite(philo, THINKING, MAGENTA);
		if (ft_sleep(philo->param->t_to_eat, philo))
			return (NULL);
	}
	while (check_if_stop(philo->param) == 0)
	{
		if (pick_fork(philo) && ft_sleep(philo->param->t_to_die * 2, philo))
			return (NULL);
		if (routine_eat(philo) && release_fork(philo))
			return (NULL);
		release_fork(philo);
		if (check_if_stop(philo->param))
			return (NULL);
		if (routine_sleep(philo))
			return (NULL);
	}
	return (NULL);
}

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

int	start_simulation(t_param *param)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < param->n_philo)
	{
		philo = &(param->tab_philo[i]);
		if (pthread_create(&(philo->id_thread), NULL,
				start_routine, (void *)philo))
			return (1);
		i++;
	}
	i = 0;
	while (i < param->n_philo)
	{
		pthread_join(param->tab_philo[i].id_thread, NULL);
		i++;
	}
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
		return (free_and_exit(&param, 1));
	}
	if ((param.n_meals == -1 || param.n_meals > 0)
		&& start_simulation(&param) != 0)
		return (free_and_exit(&param, 1));
	return (free_and_exit(&param, 0));
}
