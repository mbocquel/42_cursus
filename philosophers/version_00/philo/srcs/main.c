/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/08 18:15:20 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Fonctions autorisees :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

int	init_param(t_param *p, char **argv)
{
	int	error_count;

	error_count = 0;
	error_count += ft_atoi_ui_error(argv[1], &(p->n_philo));
	if (p->n_philo == 0)
		error_count++;
	error_count += ft_atoi_ui_error(argv[2], &(p->t_to_die));
	error_count += ft_atoi_ui_error(argv[3], &(p->t_to_eat));
	error_count += ft_atoi_ui_error(argv[4], &(p->t_to_sleep));
	error_count += ft_atoi_ui_error(argv[1], &(p->n_philo));
	p->n_meals = -1;
	if (argv[5])
		error_count += ft_atoi_ui_error(argv[5], &(p->n_meals));
	p->tab_philo = NULL;
	p->death = 0;
	p->n_finished = 0;
	if (gettimeofday(&(p->t0), NULL) != 0)
		error_count++;
	return (error_count);
}

int	initiate_mutex(t_param *p)
{
	int	i;
	int	error_count;

	i = 0;
	error_count = 0;
	error_count += pthread_mutex_init(&(p->mutex_end), NULL);
	while (i < p->n_philo)
	{
		error_count += pthread_mutex_init(&(p->mutex_fork[i]), NULL);
		i++;
	}
	return (error_count);
}

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi_ui_error(const char *nptr, int *val)
{
	long	result;
	int		i;
	long	sng;

	i = 0;
	sng = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sng = -1;
		if (!nptr[i + 1] || !(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
			return (1);
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9' && result <= 2147483648)
		result = result * 10 + nptr[i++] - '0';
	if (sng * result < 0 || sng * result > 2147483647 || nptr[i])
		return (1);
	*val = (int)(sng * result);
	return (0);
}

int	parsing(t_param *p, char **argv)
{
	int	i;

	if (init_param(p, argv))
		return (1);
	p->mutex_fork = malloc(p->n_philo * sizeof(pthread_mutex_t));
	if (p->mutex_fork == NULL)
		return (1);
	if (initiate_mutex(p))
		return (1);
	p->tab_philo = malloc(p->n_philo * sizeof(t_philo));
	if (p->tab_philo == NULL)
		return (1);
	i = 0;
	while (i < p->n_philo)
	{
		(p->tab_philo)[i].id = i + 1;
		(p->tab_philo)[i].id_thread = 0;
		(p->tab_philo)[i].t_last_meal = p->t0;
		(p->tab_philo)[i].count_meal = 0;
		(p->tab_philo)[i].is_alive = 1;
		(p->tab_philo)[i].param = p;
		i++;
	}
	return (0);
}

int	free_and_exit(t_param *p, int code_exit)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&p->mutex_end);
	if (p->mutex_fork)
	{
		while (i < p->n_philo)
		{
			pthread_mutex_destroy(&(p->mutex_fork[i]));
			i++;
		}
		free(p->mutex_fork);
	}
	if (p->tab_philo)
		free(p->tab_philo);
	return (code_exit);
}

unsigned long	get_timediff(struct timeval t, struct timeval t0)
{
	unsigned long	ts;

	ts = (t.tv_sec - t0.tv_sec) * 1000 + (t.tv_usec - t0.tv_usec) / 1000;
	return (ts);
}

int	check_dead(t_philo *philo)
{
	int				dead;
	unsigned long	time_passed;
	struct timeval	tv;

	tv = gettimeofday(&tv, NULL);
	time_passed = get_timediff(tv, philo->t_last_meal);
	if (time_passed > philo->param->t_to_die)
	{
		philo->is_alive = 0;
		pthread_mutex_lock(&(philo->param->mutex_end));
		philo->param->death = 1;
		pthread_mutex_unlock(&(philo->param->mutex_end));
		return (1);
	}
	return (0);
}

int	ft_sleep(unsigned long sleep_time, t_philo *philo)
{
	unsigned long	time_waited;

	time_waited = 0;
	while (time_waited < sleep_time)
	{
		if (check_dead(philo))
			return (1);
		usleep(50);
		time_waited += 50;
	}
	return (0);
}

void	pick_left_fork(t_philo *philo)
{
	int	n;

	n = philo->param->n_philo;
	if (philo->id == 1)
		pthread_mutex_lock(&(philo->param->mutex_fork[n]));
	else
		pthread_mutex_lock(&(philo->param->mutex_fork[philo->id - 1]));
}

void	release_left_fork(t_philo *philo)
{
	int	n;

	n = philo->param->n_philo;
	if (philo->id == 1)
		pthread_mutex_unlock(&(philo->param->mutex_fork[n]));
	else
		pthread_mutex_unlock(&(philo->param->mutex_fork[philo->id - 1]));
}

void	pick_right_fork(t_philo *philo)
{
	int	n;

	n = philo->param->n_philo;
	if (philo->id == n)
		pthread_mutex_lock(&(philo->param->mutex_fork[0]));
	else
		pthread_mutex_lock(&(philo->param->mutex_fork[philo->id]));
}

void	release_right_fork(t_philo *philo)
{
	int	n;

	n = philo->param->n_philo;
	if (philo->id == n)
		pthread_mutex_unlock(&(philo->param->mutex_fork[0]));
	else
		pthread_mutex_unlock(&(philo->param->mutex_fork[philo->id]));
}

int	routine_eat(t_philo *philo)
{
	unsigned long	ts;
	struct timeval	tv;

	tv = gettimeofday(&tv, NULL);
	ts = get_timediff(tv, philo->param->t0);
	printf("%ld %d is eating\n", ts, philo->id);
	if (ft_sleep(philo->param->t_to_eat, philo))
		return (1);
	return (0);
}

int	routine_sleep(t_philo *philo)
{
	unsigned long	ts;
	struct timeval	tv;

	tv = gettimeofday(&tv, NULL);
	ts = get_timediff(tv, philo->param->t0);
	printf("%ld %d is sleeping\n", ts, philo->id);
	if (ft_sleep(philo->param->t_to_sleep, philo))
		return (1);
	return (0);
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
	/*if (start_simulation(&param) != 0)
		return (free_and_exit(&param, 1));*/
	return (free_and_exit(&param, 0));
}
