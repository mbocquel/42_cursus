/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/12 15:06:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_nb_action(char **inst)
{
	int	i;

	if (inst == NULL)
		return (0);
	i = 0;
	while (inst[i])
	{
		i++;
	}
	return (i);
}

void	record_action(t_ps *ps, const char *action)
{
	char	**new_inst;
	int		nb_inst;
	int		i;

	i = -1;
	nb_inst = get_nb_action(ps->inst);
	new_inst = (char **)malloc((nb_inst + 2) * sizeof(char *));
	if (new_inst == NULL)
		ft_exit(ps, ERROR_ACTION);
	new_inst[nb_inst] = ft_strdup(action);
	if (new_inst[nb_inst] == NULL)
	{
		free(new_inst);
		ft_exit(ps, ERROR_ACTION);
	}
	new_inst[nb_inst + 1] = NULL;
	while (++i < nb_inst)
		new_inst[i] = (ps->inst)[i];
	if (ps->inst)
		free(ps->inst);
	ps->inst = new_inst;
}

void	add_action(t_ps *ps, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		action_swap(&(ps->pile_a));
	else if (ft_strncmp(str, "sb", 2) == 0)
		action_swap(&(ps->pile_b));
	else if (ft_strncmp(str, "ra", 2) == 0)
		action_rotate(&(ps->pile_a));
	else if (ft_strncmp(str, "rb", 2) == 0)
		action_rotate(&(ps->pile_b));
	else if (ft_strncmp(str, "rra", 3) == 0)
		action_r_rotate(&(ps->pile_a));
	else if (ft_strncmp(str, "rrb", 3) == 0)
		action_r_rotate(&(ps->pile_b));
	else if (ft_strncmp(str, "pa", 2) == 0)
		action_push(&(ps->pile_b), &(ps->pile_a));
	else if (ft_strncmp(str, "pb", 2) == 0)
		action_push(&(ps->pile_a), &(ps->pile_b));
	else if (ft_strncmp(str, "ss", 2) == 0)
		action_double_swap(ps);
	else if (ft_strncmp(str, "rr", 2) == 0 && ft_strncmp(str, "rrr", 3) != 0)
		action_double_rotate(ps);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		action_double_r_rotate(ps);
	record_action(ps, str);
}
