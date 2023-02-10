/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:27:09 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/10 14:00:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	free_and_exit(t_param *p, int code_exit)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&p->mutex_death);
	pthread_mutex_destroy(&p->mutex_n_finished);
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

void	print_activite(t_philo *philo, char *msg, char *color)
{
	int				print;
	struct timeval	tv;
	unsigned long	time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = get_timediff_us(tv, philo->param->t0) / 1000;
	print = 1;
	pthread_mutex_lock(&(philo->param->mutex_death));
	pthread_mutex_lock(&(philo->param->mutex_n_finished));
	if (philo->param->death == 1
		|| philo->param->n_finished == philo->param->n_philo)
		print = 0;
	if (print)
		printf("%s%ld	%d	%s\e[0m\n", color, time_stamp, philo->id, msg);
	pthread_mutex_unlock(&(philo->param->mutex_n_finished));
	pthread_mutex_unlock(&(philo->param->mutex_death));
}
