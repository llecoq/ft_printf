/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:57:47 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/01 08:16:27 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	while (i < n && (unsigned char)c != source[i])
	{
		dest[i] = source[i];
		i++;
	}
	if (i == n)
		return (0);
	else
	{
		dest[i] = source[i];
		i++;
	}
	return (&dest[i]);
}
