/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:58:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/18 15:24:50 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result_pf;
	int		i;
	int		error;

	result_pf = 0;
	i = -1;
	error = 0;
	va_start(args, str);
	while (str[++i] && error == 0)
	{
		if (str[i] != '%' && error == 0)
			result_pf += ft_printf_putchar(str[i], &error);
		else if (error == 0)
			result_pf += ft_printf_process(&args, &i, str, &error);
	}
	va_end(args);
	if (error == 0)
		return (result_pf);
	else
		return (-1);
}

int	ft_printf_process(va_list *args, int *i, const char *str, int *error)
{
	(*i)++;
	if (str[*i] == 'c' && *error == 0)
		return (ft_printf_putchar(va_arg(*args, int), error));
	else if (str[*i] == 's' && *error == 0)
		return (ft_printf_putstr(va_arg(*args, char *), error));
	else if (str[*i] == 'p' && *error == 0)
		return (ft_printf_putptr(va_arg(*args, void *), error));
	else if ((str[*i] == 'd' || str[*i] == 'i') && *error == 0)
		return (ft_printf_putnbr(va_arg(*args, int), error));
	else if (str[*i] == 'u' && *error == 0)
		return (ft_printf_put_usint(va_arg(*args, unsigned int), error));
	else if ((str[*i] == 'x' || str[*i] == 'X') && *error == 0)
		return (ft_printf_putnbrhex(va_arg(*args, unsigned int),
				str[*i], error));
	else if (str[*i] == '%' && *error == 0)
		return (ft_printf_putchar('%', error));
	else
	{
		*error = 1;
		return (-1);
	}
}

int	ft_printf_putnbrhex(unsigned int nb_hex, char x, int *error)
{
	char			*base;
	int				result;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	result = 0;
	if (nb_hex < 16)
		result += ft_printf_putchar(base[nb_hex % 16], error);
	else
	{
		result += ft_printf_putnbrhex(nb_hex / 16, x, error);
		result += ft_printf_putchar(base[nb_hex % 16], error);
	}
	return (result);
}

int	ft_printf_putnbrhex_ull(unsigned long long nb_hex, char x, int *error)
{
	char			*base;
	int				result;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	result = 0;
	if (nb_hex < 16)
		result += ft_printf_putchar(base[nb_hex % 16], error);
	else
	{
		result += ft_printf_putnbrhex_ull(nb_hex / 16, x, error);
		result += ft_printf_putchar(base[nb_hex % 16], error);
	}
	return (result);
}
