/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:07:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/13 18:50:43 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	open_sem(t_philo *philo)
{
	int		i;
	t_param	*p;

	p = philo->param;
	i = 0;
	p->sem_fork = sem_open("/fork", O_RDWR);
	if (p->sem_fork == SEM_FAILED && printf("1\n"))
		return (1);
	(p->sem_finish_eating)[philo->id - 1] = sem_open(
			(p->finish_name)[philo->id - 1], O_RDWR);
	if ((p->sem_finish_eating)[philo->id - 1] == SEM_FAILED && printf("1\n"))
		return (1);
	p->sem_death = sem_open("/death", O_RDWR);
	if (p->sem_death == SEM_FAILED && printf("1\n"))
		return (1);
	return (0);
}

void	routine_philo(t_philo *philo)
{
	if (open_sem(philo))
		ft_exit(philo->param, philo->id, 8);
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
