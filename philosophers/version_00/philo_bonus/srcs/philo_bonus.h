/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:51:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/10 18:23:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# define FORK_TAKEN "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define MAGENTA "\e[35m"

typedef struct s_philo {
	int				id;
	int				pid;
	struct timeval	t_last_meal;
	int				count_meal;
	int				is_alive;
	struct s_param	*param;
}					t_philo;

typedef struct s_param {
	int				n_philo;
	t_philo			*tab_philo;
	struct timeval	t0;
	sem_t			*sem_fork;
	/*pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_n_finished;*/
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	int				death;
	int				n_finished;
}					t_param;

#endif