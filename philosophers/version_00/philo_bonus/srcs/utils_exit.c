/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:30:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/14 12:18:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	free_char_mat(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	kill_child_process(t_param *p)
{
	int	i;
	
	i = 0;
	while (i < p->n_philo)
	{
		kill((p->tab_philo[i]).pid, SIGKILL);
		i++;
	}
}

int	ft_exit(t_param *p, int id_child, int code_exit)
{
	int	i;
	
	(void)id_child;
	i = -1;
	if (code_exit == ALL_FINISH || code_exit == PHILO_DEATH)
		kill_child_process(p);
	sem_close(p->sem_fork);
	sem_close(p->sem_death);
	sem_close(p->sem_print);
	while (++i < p->n_philo)
		sem_close((p->sem_finish_eating)[i]);
	if (p->tab_philo)
		free(p->tab_philo);
	if (p->finish_name)
		free_char_mat(p->finish_name);
	if (code_exit == EXIT_ERROR)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);	
}

void	print_activite(t_philo *philo, char *msg, char *color)
{
	struct timeval	tv;
	unsigned long	time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = get_timediff_us(tv, philo->param->t0) / 1000;
	sem_wait(philo->param->sem_print);
	printf("%s%ld	%d %s\e[0m\n", color, time_stamp, philo->id, msg);
	sem_post(philo->param->sem_print);
}
