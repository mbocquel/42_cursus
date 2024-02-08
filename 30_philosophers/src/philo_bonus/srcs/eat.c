/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:09:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/15 11:17:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	pick_fork(t_philo *philo)
{
	if (sem_wait(philo->param->sem_fork))
		return (1);
	print_activite(philo, FORK_TAKEN, GREEN);
	if (philo->param->n_philo == 1)
		return (1);
	if (sem_wait(philo->param->sem_fork))
		return (1);
	print_activite(philo, FORK_TAKEN, GREEN);
	return (0);
}

int	release_fork(t_philo *philo)
{
	if (sem_post(philo->param->sem_fork))
		return (1);
	if (sem_post(philo->param->sem_fork))
		return (1);
	return (0);
}

int	routine_eat(t_philo *philo)
{
	print_activite(philo, EATING, YELLOW);
	if (ft_sleep(philo->param->t_to_eat, philo))
		return (1);
	gettimeofday(&(philo->t_last_meal), NULL);
	(philo->count_meal)++;
	if (philo->param->n_meals != -1
		&& philo->count_meal == philo->param->n_meals)
		sem_post(philo->param->sem_finish_eating);
	return (0);
}
