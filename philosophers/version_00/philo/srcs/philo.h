/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:37 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/08 16:22:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
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
	pthread_mutex_t	mutex_end;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	int				death;
	int				n_finished;
}					t_param;

int	free_and_exit(t_param *param, int code_exit);
int	parsing(t_param *p, char **argv);
int	initiate_mutex(t_param *p);
int	init_param(t_param *p, char **argv);
int	ft_atoi_ui_error(const char *nptr, int *val);
int	ft_isspace(int c);

#endif