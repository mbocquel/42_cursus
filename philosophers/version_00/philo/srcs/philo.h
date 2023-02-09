/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:37 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/09 17:28:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define FORK_TAKEN 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define FORK_RELEASE 6
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo {
	int				id;
	pthread_t		id_thread;
	struct timeval	t_last_meal;
	int				count_meal;
	int				is_alive;
	struct s_param	*param;
}					t_philo;

typedef struct s_param {
	int				n_philo;
	t_philo			*tab_philo;
	struct timeval	t0;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_n_finished;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	int				death;
	int				n_finished;
}					t_param;

/*	main.c	*/
void			*start_routine(void *args);
int				check_if_stop(t_param *param);
int				start_simulation(t_param *param);

/*	eat.c	*/
void			pick_fork(t_philo *philo);
int				release_fork(t_philo *philo);
void			pick_right_fork(t_philo *philo);
void			release_right_fork(t_philo *philo);
int				routine_eat(t_philo *philo);

/*	parsing.c	*/
int				init_param(t_param *p, char **argv);
int				initiate_mutex(t_param *p);
int				parsing(t_param *p, char **argv);

/*	sleep_and_death.c	*/
unsigned long	get_timediff(struct timeval t, struct timeval t0);
int				check_dead(t_philo *philo);
int				ft_sleep(unsigned long sleep_time, t_philo *philo);
int				routine_sleep(t_philo *philo);

/*	utils_exit.c	*/
int				ft_isspace(int c);
int				ft_atoi_ui_error(const char *nptr, int *val);
int				free_and_exit(t_param *p, int code_exit);
void			print_activite(t_philo *philo, int activite);

#endif