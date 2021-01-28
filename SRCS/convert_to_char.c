/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 09:02:04 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 15:11:44 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_to_char(va_list args, t_flags *flags)
{
	char			*str;
	unsigned char	c;

	str = NULL;
	c = (unsigned char)va_arg(args, int);
	flags->precision = 1;
	if (flags->minus == 1)
		ft_putchar(c, flags);
	while (flags->width > 1)
	{
		ft_putchar(' ', flags);
		flags->width--;
	}
	if (flags->minus == 0)
		ft_putchar(c, flags);
}
