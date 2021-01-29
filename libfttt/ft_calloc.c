/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:34:10 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/01 11:38:44 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total;
	char		*dst;

	i = 0;
	total = size * count;
	if (!(dst = malloc(total)))
		return (NULL);
	ft_bzero(dst, total);
	return (dst);
}
