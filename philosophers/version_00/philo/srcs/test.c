/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/08 10:51:22 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

/*j'ai besoin d'initialiser le t0 qui va servir pour le timestamp.*/

typedef struct s_table {
	int				n_philo;
	t_philo			tab_philo[10];
	pthread_mutex_t	tab_fork[10];
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	t_gar_col		*garb;
}					t_table;

unsigned long	get_timestamp(struct timeval t, struct timeval t0)
{
	unsigned long ts;

	ts = (t.tv_sec - t0.tv_sec) * 1000 + (t.tv_usec - t0.tv_usec) / 1000;
	return (ts);
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

int	main(void)
{
	struct timeval	t0;
	struct timeval	t;

	gettimeofday(&t0, NULL);
	
	
	
	
	
}