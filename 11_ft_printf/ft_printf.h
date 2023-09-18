/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:08:20 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/28 11:10:55 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_printf_process(va_list *args, int *i, const char *str, int *error);
int	ft_printf_putchar(int c, int *error);
int	ft_printf_putstr(char *str, int *error);
int	ft_printf_putptr(void *ptr, int *error);
int	ft_printf_putnbr(int n, int *error);
int	ft_printf_put_usint(unsigned int u_nbr, int *error);
int	ft_printf_putnbrhex(unsigned int nb_hex, char x, int *error);
int	ft_printf_putnbrhex_ull(unsigned long long nb_hex, char x, int *error);

#endif
