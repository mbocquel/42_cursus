/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:58:30 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/03 18:27:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_situation_philo(t_param *param)
{
	t_philo	*philo;

	printf("/////// Global simulation Param :\n");
	printf("Number philo : %d\n", param->n_philo);
	printf("Time to die in ms : %d\n", param->t_to_die);
	printf("Time to eat in ms : %d\n", param->t_to_eat);
	printf("Time to sleep in ms : %d\n", param->t_to_sleep);
	printf("Number of times each philosopher must eat : %d\n\n", param->n_meals);
	philo = param->first_philo;
	while (philo)
	{
		printf("	------------ %d ------------\n", philo->id);
		printf("	Last meal : %ld\n", philo->t_last_meal.tv_usec);
		printf("	Number of meals taken : %d\n", philo->count_meal);
		if (philo->activity == 1)
			printf("	Activity : eating\n\n");
		if (philo->activity == 2)
			printf("	Activity : sleeping\n\n");
		if (philo->activity == 3)
			printf("	Activity : thinking\n\n");
		if (philo->activity == 0)
			printf("	Philo is dead :-(\n\n");
		philo = philo->next;
	}
}
