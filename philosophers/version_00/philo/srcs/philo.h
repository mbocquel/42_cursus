/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:37 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/03 18:26:57 by mbocquel         ###   ########.fr       */
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
	struct s_philo	*next;
	struct timeval	t_last_meal;
	int				count_meal;
	int				is_alive;
	int				activity;
}					t_philo;
/*Activity :
0 = Dead
1 = Eating
2 = Sleeping
3 = Thinking
*/

typedef struct s_param {
	int				n_philo;
	struct s_philo	*first_philo;
	int				*fork;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
}					t_param;

int		parsing(t_param *param, char **argv);
t_philo	*last_philo(t_param *param);
int		ft_atoi(const char *nptr);
void	print_situation_philo(t_param *param);
int		add_philo(t_param *param, int id);
int		free_and_exit( t_param *param, int code_exit);

#endif