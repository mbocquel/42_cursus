/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:53:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/16 12:45:39 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_last_left(t_node **root, t_node *node)
{
	t_node	*elem;

	elem = *root;
	if (elem == NULL)
		*root = node;
	else
	{
		while (elem->left)
			elem = elem->left;
		elem->left = node;
	}
}

char	**add_cmd_arg(t_param *prm, char **cmd, char *arg)
{
	char	**new_cmd;
	int		nb_arg;
	int		i;

	i = -1;
	nb_arg = get_nb_str(cmd);
	new_cmd = (char **)ft_malloc_gc(prm, prm->source.id,
			(nb_arg + 2) * sizeof(char *));
	if (new_cmd == NULL)
		return (NULL);
	new_cmd[nb_arg] = ft_strdup_gc(prm, prm->source.id, arg);
	if (new_cmd[nb_arg] == NULL)
		return (NULL);
	new_cmd[nb_arg + 1] = NULL;
	while (++i < nb_arg)
		new_cmd[i] = cmd[i];
	return (new_cmd);
}

int	pos_end_dol_sub(char *str)
{
	int	i;

	i = 0;
	if (str && str[0] && str[0] == '?')
		return (1);
	while (str && str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (i);
		i++;
	}
	return (-1);
}

char	*substitute_word(t_param *prm, char	*word)
{
	char	*new;
	int		len;
	char	*to_process;

	new = NULL;
	if (word == NULL || pos_str(word, '$') == -1)
		return (word);
	new = ft_strjoin_gc(prm, prm->source.id, new,
			ft_substr_gc(prm, word, 0, pos_str(word, '$')));
	if (pos_str(word, '$') + 1 == (int)ft_strlen(word))
		new = ft_strjoin_gc(prm, prm->source.id, new, "$");
	else
	{
		len = ft_strlen(word) - pos_str(word, '$') - 1;
		if (pos_end_dol_sub(word + pos_str(word, '$') + 1) != -1)
			len = pos_end_dol_sub(word + pos_str(word, '$') + 1);
		new = ft_strjoin_gc(prm, prm->source.id, new, get_env_var(prm,
					ft_substr_gc(prm, word, pos_str(word, '$') + 1, len)));
		to_process = ft_substr_gc(prm, word, pos_str(word, '$')
				+ 1 + len, ft_strlen(word));
		if (ft_strlen(to_process))
			new = ft_strjoin_gc(prm, prm->source.id, new,
					substitute_word(prm, to_process));
	}
	return (new);
}

char	*get_space(t_param *prm)
{
	size_t	pos_start;
	size_t	cur;
	char	*space;

	pos_start = prm->source.cur;
	cur = prm->source.cur;
	while (cur < prm->source.line_size && ft_isspace(prm->source.line[cur]))
		cur++;
	space = ft_substr_gc(prm, prm->source.line, pos_start, cur - pos_start);
	return (space);
}
