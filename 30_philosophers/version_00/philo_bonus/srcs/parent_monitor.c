/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:13 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 17:04:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *args)
{
	t_param	*p;
	int		i;

	i = 0;
	p = (t_param *)args;
	if (sem_wait(p->sem_death) != -1)
	{
		while (i < p->n_philo)
		{
			sem_post(p->sem_finish_eating);
			i++;
		}
	}
	return (NULL);
}

void	*monitor_finish(void *args)
{
	t_param	*p;
	int		i;

	i = 0;
	p = (t_param *)args;
	while (i < p->n_philo)
	{
		sem_wait(p->sem_finish_eating);
		i++;
	}
	sem_post(p->sem_death);
	return (NULL);
}
