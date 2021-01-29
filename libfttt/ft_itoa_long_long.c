/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:21:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/28 17:06:51 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_nb_len_long_long(unsigned long n)
{
	unsigned long	len;
	unsigned long	nb;

	len = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa_long_long(long long n)
{
	unsigned long	nb;
	unsigned long	len;
	unsigned long	i;
	char			*dest;

	nb = (unsigned long)n;
	len = ft_nb_len_long_long(n);
	i = len - 1;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		dest[0] = '-';
	}
	while (nb > 9)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb + 48;
	dest[len] = '\0';
	return (dest);
}
