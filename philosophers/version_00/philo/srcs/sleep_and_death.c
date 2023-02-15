/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:32:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/15 11:28:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_timediff_us(struct timeval t, struct timeval t0)
{
	unsigned long	ts;

	ts = (t.tv_sec - t0.tv_sec) * 1000000 + (t.tv_usec - t0.tv_usec);
	return (ts);
}

int	check_dead(t_philo *philo)
{
	unsigned long	time_passed;
	unsigned long	time_stamp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time_passed = get_timediff_us(tv, philo->t_last_meal);
	time_stamp = get_timediff_us(tv, philo->param->t0) / 1000;
	if (time_passed > (unsigned long)philo->param->t_to_die * 1000)
	{
		philo->is_alive = 0;
		pthread_mutex_lock(&(philo->param->mutex_death));
		if (philo->param->death == 1)
		{
			pthread_mutex_unlock(&(philo->param->mutex_death));
			return (1);
		}
		printf("\e[31m%ld	%d died\e[0m\n", time_stamp, philo->id);
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
	unsigned long	time_diff;

	gettimeofday(&t0, NULL);
	tv = t0;
	time_diff = get_timediff_us(tv, t0);
	while (time_diff <= sleep_time * 1000)
	{
		if (check_dead(philo))
			return (1);
		usleep(50);
		gettimeofday(&tv, NULL);
		time_diff = get_timediff_us(tv, t0);
	}
	return (0);
}

int	routine_sleep(t_philo *philo)
{
	int	time_min_think;

	time_min_think = (philo->param->t_to_die
			- philo->param->t_to_sleep
			- 2 * philo->param->t_to_eat) / 2;
	print_activite(philo, SLEEPING, CYAN);
	if (ft_sleep(philo->param->t_to_sleep, philo))
		return (1);
	print_activite(philo, THINKING, MAGENTA);
	if (time_min_think > 0 && ft_sleep(time_min_think, philo))
		return (1);
	return (0);
}
