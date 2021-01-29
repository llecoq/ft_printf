/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:11:34 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/02 13:20:16 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	newlen;

	i = 0;
	newlen = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		newlen = 0;
	else if (ft_strlen(s) < len)
		newlen = ft_strlen(s);
	if (!(dst = malloc(sizeof(char) * newlen + 1)))
		return (NULL);
	while (i < newlen)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
