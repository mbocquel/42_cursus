/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:51:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 18:55:24 by mbocquel         ###   ########.fr       */
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
# include <pthread.h>
# define FORK_TAKEN "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define MAGENTA "\e[35m"
# define EXIT_ERROR 1

typedef struct s_philo {
	int				id;
	int				pid;
	struct timeval	t_last_meal;
	int				count_meal;
	int				is_alive;
	pthread_t		thread_monitor;
	struct s_param	*param;
}					t_philo;

typedef struct s_param {
	struct timeval	t0;
	int				n_philo;
	t_philo			*tab_philo;
	sem_t			*sem_fork;
	sem_t			*sem_finish_eating;
	sem_t			*sem_death;
	sem_t			*sem_print;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	pthread_t		thread_death;
	pthread_t		thread_finish;
}					t_param;

/*	eat.c	*/
int				pick_fork(t_philo *philo);
int				release_fork(t_philo *philo);
int				routine_eat(t_philo *philo);

/*	ft_itoa.c	*/
int				ft_power(int nb, int power);
char			*ft_itoa(int n);

/*	ft_strjoin.c	*/
int				ft_len(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);

/*	main.c	*/
void			*monitor_death(void *args);
void			*monitor_finish(void *args);
void			routine_philo(t_philo *philo);
int				start_simulation(t_param *p);

/*	parsing.c	*/
int				init_param(t_param *p, char **argv);
int				get_sem_finish_name(t_param *p);
int				init_semaphore(t_param *p);
int				parsing(t_param *p, char **argv);

/*	sleep_and_death.c	*/
unsigned long	get_timediff_us(struct timeval t, struct timeval t0);
int				check_dead(t_philo *philo);
int				ft_sleep(unsigned long sleep_time, t_philo *philo);
int				routine_sleep(t_philo *philo);

/*	utils_exit.c	*/
int				ft_isspace(int c);
int				ft_atoi_ui_error(const char *nptr, int *val);
int				ft_exit(t_param *p, int n_philo, int code_exit);
void			print_activite(t_philo *philo, char *msg, char *color);
void			kill_child_process(t_param *p);
void			routine_philo(t_philo *philo);

#endif