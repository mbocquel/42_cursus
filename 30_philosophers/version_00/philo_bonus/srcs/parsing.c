/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:28:33 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 15:50:39 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_param(t_param *p, char **argv)
{
	int	error_count;

	error_count = 0;
	error_count += ft_atoi_ui_error(argv[1], &(p->n_philo));
	if (p->n_philo == 0)
		error_count++;
	error_count += ft_atoi_ui_error(argv[2], &(p->t_to_die));
	error_count += ft_atoi_ui_error(argv[3], &(p->t_to_eat));
	error_count += ft_atoi_ui_error(argv[4], &(p->t_to_sleep));
	p->n_meals = -1;
	if (argv[5])
		error_count += ft_atoi_ui_error(argv[5], &(p->n_meals));
	p->tab_philo = NULL;
	if (gettimeofday(&(p->t0), NULL) != 0)
		error_count++;
	return (error_count);
}

int	init_semaphore(t_param *p)
{
	sem_unlink("/fork");
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/finish_eating");
	p->sem_fork = sem_open("/fork", O_CREAT, S_IRWXG, p->n_philo);
	p->sem_death = sem_open("/death", O_CREAT, S_IRWXG, 0);
	p->sem_print = sem_open("/print", O_CREAT, S_IRWXG, 1);
	p->sem_finish_eating = sem_open("/finish_eating", O_CREAT, S_IRWXG, 0);
	return (0);
}

int	parsing(t_param *p, char **argv)
{
	int	i;

	if (init_param(p, argv))
		return (1);
	if (init_semaphore(p))
		return (1);
	p->tab_philo = malloc(p->n_philo * sizeof(t_philo));
	if (p->tab_philo == NULL)
		return (1);
	memset (p->tab_philo, 0, p->n_philo * sizeof (t_philo));
	i = 0;
	while (i < p->n_philo)
	{
		(p->tab_philo)[i].id = i + 1;
		(p->tab_philo)[i].t_last_meal = p->t0;
		(p->tab_philo)[i].is_alive = 1;
		(p->tab_philo)[i].param = p;
		i++;
	}
	return (0);
}
