/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:07:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 16:19:52 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		print_activite(philo, THINKING, MAGENTA);
		if (ft_sleep(10, philo))
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
