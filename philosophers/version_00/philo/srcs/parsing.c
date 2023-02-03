/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:19:56 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*last_philo(t_param *param)
{
	t_philo	*philo;

	if (param->first_philo == NULL || param->first_philo->next == NULL)
		return (param->first_philo);
	philo = param->first_philo;
	while (philo)
	{
		if (philo->next == NULL)
			return (philo);
		else
			philo = philo->next;
	}
	return (philo);
}

int	add_philo(t_param *param, int id)
{
	t_philo			*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (new == NULL)
		return (1);
	memset((void *)new, 0, sizeof(new));
	new->id = id;
	new->activity = 3;
	if (param->first_philo == NULL)
		param->first_philo = new;
	else
	{
		new->next = param->first_philo;
		param->first_philo = new;
	}
	return (0);
}

int	parsing(t_param *param, char **argv)
{
	int	i;

	param->n_philo = ft_atoi(argv[1]);
	param->t_to_die = ft_atoi(argv[2]);
	param->t_to_eat = ft_atoi(argv[3]);
	param->t_to_sleep = ft_atoi(argv[4]);
	param->n_meals = -1;
	param->first_philo = NULL;
	if (argv[5])
		param->n_meals = ft_atoi(argv[5]);
	if (param->n_philo == 0)
		return (1);
	param->fork = malloc(param->n_philo * sizeof(int));
	if (param->fork == NULL)
		return (1);
	memset((void *)(param->fork), 1, param->n_philo);
	i = param->n_philo;
	while (i > 0)
	{
		if (add_philo(param, i) != 0)
			return (1);
		i--;
	}
	return (0);
}
