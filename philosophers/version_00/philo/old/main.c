/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/07 18:38:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

/*J'a des leak et je dois faire en sorte de finir plus vite. */

/*Dans mon parsing regarder que l'on me donne bien des int*/


void	free_fork(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n_philo)
	{
		pthread_mutex_destroy(param->tab_fork + i);
		i++;
	}
}

int	free_and_exit(t_param *param, int code_exit)
{
	print_situation_philo(param);
	free_fork(param);
	empty_garbage(param);
	return (code_exit);
}

/* Je dois creer un thread par philospher. 	
	Dans chaque thread, j'initialise la date du last 
	meal au moment de leur naissance.
		gettimeofday(&(new->t_last_meal), NULL);
	Je lance leur routine a chacun et je m'arrette des que
	l'un des philosophe est mort. */

void	*start_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (philo->is_alive == 1)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}
	return (NULL);
}

int	monitoring_simulation(t_param *param)
{
	struct timeval	tv;
	t_philo			*philo;
	int				end;
	int				i;

	end = 0;
	while (end == 0)
	{
		if (param->n_meals != -1)
			end = 1;
		i = 0;
		while (i < param->n_philo)
		{
			philo = &(param->tab_philo[i]);
			gettimeofday(&tv, NULL);
			if (tv.tv_usec - philo->t_last_meal.tv_usec > param->t_to_die)
			{
				philo->is_alive = 0;
				printf("%ld %d died\n", tv.tv_usec, philo->id);
				return (1);
			}
			if (param->n_meals != -1 && philo->count_meal < param->n_meals)
				end = 0;
			i++;
		}
	}
	return (0);
}

int	start_simulation(t_param *param)
{
	int	i;
	t_philo *philo;

	i = 0;
	while (i < param->n_philo)
	{
		philo = &(param->tab_philo[i]);
		if (pthread_create(&(philo->id_thread), NULL,
				&start_routine, (void *)philo) != 0)
			free_and_exit(param, 1);
		i++;
	}
	if (monitoring_simulation(param))
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of argument\n", 32));
	if (parsing(&param, argv) != 0)
		return (write(2, "Error\n", 5));
	memset(&param, 0, sizeof(t_param));
	if (parsing(&param, argv) != 0)
		return (free_and_exit(&param, 1));
	if (start_simulation(&param) != 0)
		return (free_and_exit(&param, 1));
	return (free_and_exit(&param, 0));
}
