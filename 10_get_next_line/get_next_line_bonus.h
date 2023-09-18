/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:23:59 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/24 18:05:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list_sto
{
	char					*content;
	struct s_list_sto		*next;
}					t_list_sto;
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_lstadd_back(t_list_sto **lst, void *content);
char		*get_next_line(int fd);
int			read_and_add_to_storage(t_list_sto **storage, char *buffer, int fd);
void		print_lst(t_list_sto *storage);
char		*ft_strdup(const char *s);
int			line_to_make(t_list_sto *storage);
char		*make_next_line(t_list_sto **storage, int *error);
int			read_store(t_list_sto **storage, char *buffer, int fd, int *error);
size_t		ft_line_len(t_list_sto *storage);
void		clean_storage(t_list_sto **storage);
void		clear_all_memory(t_list_sto **storage);
size_t		ft_strlen(const char *str);

#endif