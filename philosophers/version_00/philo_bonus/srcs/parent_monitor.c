/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:02:13 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/13 18:46:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *args)
{
	t_param	*p;

	p = (t_param *)args;
	if (sem_wait(p->sem_death) != -1)
	{
		printf("je suis le parent et j'ai vu un mort \n");
		ft_exit(p, 0, PHILO_DEATH);
	}
	return (NULL);
}

void	*monitor_finish(void *args)
{
	t_param	*p;
	int		i;

	i = 0;
	p = (t_param *)args;
	while (i < p->n_meals)
	{
		sem_wait((p->sem_finish_eating)[i]);
		i++;
	}
	printf("je suis le parent et tout le monde a mange. \n");
	ft_exit(p, 0, ALL_FINISH);
	return (NULL);
}