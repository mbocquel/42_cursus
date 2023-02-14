/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:07:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 18:59:19 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death_child(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		check_dead(philo);
		usleep(50);
	}
}

void	routine_philo(t_philo *philo)
{
	if (pthread_create(&(philo->thread_monitor), NULL,
			monitor_death_child, (void *)philo))
		ft_exit(philo->param, philo->id, EXIT_ERROR);
	if (philo->id % 2 != 0)
	{
		print_activite(philo, THINKING, MAGENTA);
		if (ft_sleep(philo->param->t_to_eat, philo))
			ft_exit(philo->param, philo->id, EXIT_ERROR);
	}
	while (1)
	{
		if (pick_fork(philo) && ft_sleep(philo->param->t_to_die * 2, philo))
			ft_exit(philo->param, philo->id, EXIT_ERROR);
		if (routine_eat(philo) && release_fork(philo))
			ft_exit(philo->param, philo->id, EXIT_ERROR);
		release_fork(philo);
		if (routine_sleep(philo))
			ft_exit(philo->param, philo->id, EXIT_ERROR);
	}
}
