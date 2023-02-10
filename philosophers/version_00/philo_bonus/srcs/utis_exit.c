/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:30:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/10 18:07:05 by mbocquel         ###   ########.fr       */
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

int	free_and_exit(t_param *p, int code_exit)
{
	sem_close(p->sem_fork);
	if (p->tab_philo)
		free(p->tab_philo);
	/*Faire en sorte de kill les child process s'il y en a ...*/
	//exit(code_exit);
	return (code_exit);
}
