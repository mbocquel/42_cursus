/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/03 18:24:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

int	free_and_exit( t_param *param, int code_exit)
{
	t_philo	*philo;
	t_philo	*temp;

	philo = param->first_philo;
	while (philo)
	{
		temp = philo;
		philo = philo->next;
		free(temp);
	}
	if (param->fork != NULL)
		free(param->fork);
	return (code_exit);
}

/* Je dois creer un thread par philospher. 	
	Dans chaque thread, j'initialise la date du last 
	meal au moment de leur naissance.
		gettimeofday(&(new->t_last_meal), NULL);
	Je lance leur routine a chacun et je m'arrette des que
	l'un des philosophe est mort. */

int	start_simulation(t_param *param)
{
	print_situation_philo(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of argument\n", 32));
	if (parsing(&param, argv) != 0)
		return (write(2, "Error\n", 5));
	memset(&param, 0, sizeof(t_param));
	if (parsing(&param, argv) != 0)
		return (free_and_exit(&param, 1));
	if (start_simulation(&param) != 0)
		return (free_and_exit(&param, 1));
	return (free_and_exit(&param, 0));
}
