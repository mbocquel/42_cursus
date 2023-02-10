/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:50:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/10 18:16:05 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink
*/

/*Ce que je dois faire : 
Fork pour faire autant de processus que de philosophe.
initialiser le semaphore des fourchettes avec la valeur nb de philo.
chaque philosophe se lance dans sa routine. 
chaque philosophe regarde quand il a fini de mange. ou quand il est mort et return. 
==> nan il faut continuer de manger meme si on a fini
le parent regarde les retours de tous ces enfants.
Si un des enfants retour parce quil est mort, le parent kill les autres. 
*/


/*Comment indiquer qu'ils sont mort ???
indicateur nb_philo en train de tourner.
a chaque debut de tour, ils prennent 
*/

int	start_simulation(t_param *param)
{
	
}

int	main(int argc, char **argv)
{
	t_param	param;

	memset(&param, 0, sizeof(t_param));
	if (argc < 5 || argc > 6)
		return (write(2, "Error: Wrong number of argument\n", 32));
	if (parsing(&param, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (free_and_exit(&param, 1));
	}
	if ((param.n_meals == -1 || param.n_meals > 0)
		&& start_simulation(&param) != 0)
		return (free_and_exit(&param, 1));
	return (free_and_exit(&param, 0));
}
