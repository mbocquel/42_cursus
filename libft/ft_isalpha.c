/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:43:16 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/07 17:06:48 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 65 && uc <= 90)
		return (1024);
	else if (uc >= 97 && uc <= 122)
		return (1024);
	else
		return (0);
}
