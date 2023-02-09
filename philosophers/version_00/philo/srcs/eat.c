/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:30:42 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/09 17:27:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_philo *philo)
{
	int	n_fork;

	n_fork = philo->id - 2;
	if (philo->id == 1)
		n_fork = philo->param->n_philo - 1;
	pthread_mutex_lock(&(philo->param->mutex_fork[n_fork]));
	print_activite(philo, FORK_TAKEN);
	pick_right_fork(philo);
}

int	release_fork(t_philo *philo)
{
	int	n_fork;

	n_fork = philo->id - 2;
	if (philo->id == 1)
		n_fork = philo->param->n_philo - 1;
	pthread_mutex_unlock(&(philo->param->mutex_fork[n_fork]));
	release_right_fork(philo);
	return (1);
}

void	pick_right_fork(t_philo *philo)
{
	int	n_fork;

	n_fork = philo->id - 1;
	pthread_mutex_lock(&(philo->param->mutex_fork[n_fork]));
	print_activite(philo, FORK_TAKEN);
}

void	release_right_fork(t_philo *philo)
{
	int	n_fork;

	n_fork = philo->id - 1;
	pthread_mutex_unlock(&(philo->param->mutex_fork[n_fork]));
}

int	routine_eat(t_philo *philo)
{
	print_activite(philo, EATING);
	if (ft_sleep(philo->param->t_to_eat, philo))
		return (1);
	(philo->count_meal)++;
	if (philo->param->n_meals != -1
		&& philo->count_meal == philo->param->n_meals)
	{
		pthread_mutex_lock(&(philo->param->mutex_n_finished));
		(philo->param->n_finished)++;
		pthread_mutex_unlock(&(philo->param->mutex_n_finished));
	}
	gettimeofday(&(philo->t_last_meal), NULL);
	return (0);
}
