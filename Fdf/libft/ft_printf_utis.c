/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:06:38 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/29 17:05:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putchar(int c, int *error)
{
	int	n;

	n = write(1, &c, 1);
	if (n == -1)
		*error = 1;
	return (n);
}

int	ft_printf_putstr(char *str, int *error)
{
	int	result;

	if (str == NULL)
		result = write(1, "(null)", 6);
	else
		result = write(1, str, ft_strlen(str));
	if (result == -1)
		*error = 1;
	return (result);
}

int	ft_printf_putptr(void *ptr, int *error)
{
	int	result;

	result = 0;
	if (ptr == NULL)
		result += write(1, "(nil)", 5);
	else
	{
		result += ft_printf_putstr("0x", error);
		result += ft_printf_putnbrhex_ull((unsigned long long)ptr, 'x', error);
	}
	if (result == -1)
		*error = 1;
	return (result);
}

int	ft_printf_putnbr(int n, int *error)
{
	long int	nb;
	int			result;

	result = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		result += ft_printf_putchar('-', error);
	}
	if (nb >= 10)
		result += ft_printf_putnbr(nb / 10, error);
	result += ft_printf_putchar(nb % 10 + '0', error);
	return (result);
}

int	ft_printf_put_usint(unsigned int u_nbr, int *error)
{
	int				result;

	result = 0;
	if (u_nbr >= 10)
		result += ft_printf_put_usint(u_nbr / 10, error);
	result += ft_printf_putchar(u_nbr % 10 + '0', error);
	return (result);
}
