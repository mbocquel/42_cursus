/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:44:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/07 16:04:50 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	routine_take_a_fork(t_philo *philo, pthread_mutex_t fork)
{
	
}
*/
void	routine_eat(t_philo *philo)
{
	struct timeval	tv;

	memset(&tv, 0, sizeof(tv));

	if (gettimeofday(&tv, NULL) == 0)
		printf("%ld %d is eating\n", tv.tv_usec, philo->id);
	philo->activity = 1;
	(philo->count_meal)++;
	philo->t_last_meal = tv;
	usleep(philo->param->t_to_eat);
}

void	routine_sleep(t_philo *philo)
{
	struct timeval	tv;

	memset(&tv, 0, sizeof(tv));
	if (gettimeofday(&tv, NULL) == 0)
		printf("%ld %d is sleeping\n", tv.tv_usec, philo->id);
	philo->activity = 2;
	usleep(philo->param->t_to_sleep);
}

void	routine_think(t_philo *philo)
{
	struct timeval	tv;
	
	memset(&tv, 0, sizeof(tv));
	if (gettimeofday(&tv, NULL) == 0)
		printf("%ld %d is thinking\n", tv.tv_usec, philo->id);
	philo->activity = 3;
}
