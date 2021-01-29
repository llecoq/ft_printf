/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:46:03 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/01 17:41:04 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s1);
	while (ft_is_in_set(s1[i], set) == 1)
		i++;
	while (ft_is_in_set(s1[j - 1], set) == 1)
		j--;
	if (i > j)
		return (ft_calloc(1, sizeof(char)));
	if (!(dst = (char*)malloc(sizeof(char) * j - i + 1)))
		return (NULL);
	while (i < j)
	{
		dst[k++] = s1[i++];
	}
	dst[k] = '\0';
	return (dst);
}
