/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:37 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/07 18:26:23 by mbocquel         ###   ########.fr       */
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

/*Activity :
1 = Eating
2 = Sleeping
3 = Thinking
*/

typedef struct s_philo {
	int				id;
	pthread_t		id_thread;
	struct timeval	t_last_meal;
	int				count_meal;
	int				is_alive;
	int				activity;
	struct s_param	*param;
}					t_philo;

typedef struct s_args {
	t_philo			*philo;
	struct s_param	*param;
}					t_args;

typedef struct s_gar_col
{
	void				*ptr;
	struct s_gar_col	*next;
}						t_gar_col;

typedef struct s_param {
	int				n_philo;
	t_philo			*tab_philo;
	pthread_mutex_t	*tab_fork;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	t_gar_col		*garb;
	int				error;
}					t_param;

int		parsing(t_param *param, char **argv);
t_philo	*last_philo(t_param *param);
int		ft_atoi(const char *nptr);
void	print_situation_philo(t_param *param);
t_philo	*add_philo(t_param *param, int id);
int		free_and_exit( t_param *param, int code_exit);
void	initialise_fork(t_param *param);
void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);
void	routine_think(t_philo *philo);
void	free_fork(t_param *param);
int		garbage_col(t_param *param, void *ptr);
void	empty_garbage(t_param *param);

#endif