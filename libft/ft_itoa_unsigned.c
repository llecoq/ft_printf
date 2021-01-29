/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:21:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/22 16:49:15 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned		ft_nb(unsigned n)
{
	unsigned	len;
	unsigned	nb;

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

char			*ft_itoa_unsigned(unsigned nb)
{
	unsigned		len;
	unsigned		i;
	char			*dest;

	len = ft_nb(nb);
	i = len - 1;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
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
