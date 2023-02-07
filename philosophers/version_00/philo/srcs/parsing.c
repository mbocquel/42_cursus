/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:19:56 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/07 18:18:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int i, t_param *param)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	memset(&tv, 0, sizeof(tv));
	philo->id = i;
	philo->activity = 3;
	philo->is_alive = 1;
	philo->param = param;
	philo->t_last_meal = tv;
}

void	initialise_fork(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n_philo)
	{
		pthread_mutex_init(param->tab_fork + i, NULL);
		i++;
	}
}

void	init_param(t_param *p, char **argv)
{
	p->n_philo = ft_atoi(argv[1]);
	p->t_to_die = ft_atoi(argv[2]);
	p->t_to_eat = ft_atoi(argv[3]);
	p->t_to_sleep = ft_atoi(argv[4]);
	p->n_meals = -1;
	p->tab_philo = NULL;
	p->garb = NULL;
	p->tab_fork = NULL;
	if (argv[5])
		p->n_meals = ft_atoi(argv[5]);
}

int	parsing(t_param *p, char **argv)
{
	int	i;

	init_param(p, argv);
	if (p->n_philo == 0)
		return (1);
	p->tab_fork = malloc(p->n_philo * sizeof(pthread_mutex_t));
	if (p->tab_fork == NULL || garbage_col(p, (void *)(p->tab_fork)))
		return (1);
	p->tab_philo = malloc(p->n_philo * sizeof(t_philo));
	if (p->tab_philo == NULL || garbage_col(p, (void *)(p->tab_philo)))
		return (1);
	memset(p->tab_philo, 0, p->n_philo * sizeof(t_philo));
	initialise_fork(p);
	i = 0;
	while (i < p->n_philo)
	{
		init_philo(p->tab_philo + i, i, p);
		i++;
	}
	return (0);
}
