/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:32:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/09 16:47:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_timediff(struct timeval t, struct timeval t0)
{
	unsigned long	ts;

	ts = (t.tv_sec - t0.tv_sec) * 1000 + (t.tv_usec - t0.tv_usec) / 1000;
	return (ts);
}

int	check_dead(t_philo *philo)
{
	unsigned long	time_passed;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time_passed = get_timediff(tv, philo->t_last_meal);
	if (time_passed > (unsigned long)philo->param->t_to_die)
	{
		philo->is_alive = 0;
		pthread_mutex_lock(&(philo->param->mutex_death));
		if (philo->param->death == 1)
		{
			pthread_mutex_unlock(&(philo->param->mutex_death));
			return (1);
		}
		printf("%ld %d died\n", get_timediff(tv, philo->param->t0), philo->id);
		philo->param->death = 1;
		pthread_mutex_unlock(&(philo->param->mutex_death));
		return (1);
	}
	return (0);
}

int	ft_sleep(unsigned long sleep_time, t_philo *philo)
{
	struct timeval	t0;
	struct timeval	tv;

	gettimeofday(&t0, NULL);
	tv = t0;
	while (get_timediff(tv, t0) < sleep_time)
	{
		if (check_dead(philo))
			return (1);
		usleep(100);
		gettimeofday(&tv, NULL);
	}
	return (0);
}

int	routine_sleep(t_philo *philo)
{
	print_activite(philo, SLEEPING);
	if (ft_sleep(philo->param->t_to_sleep, philo))
		return (1);
	return (0);
}
