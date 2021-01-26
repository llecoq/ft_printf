/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:39:45 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/23 10:29:50 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_un(char const *s, t_flags *flags)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_un(s[i], flags);
		i++;
	}
}
