/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:28:26 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/29 14:56:54 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		process_percent(const char *input, va_list args, t_flags *flags)
{
	flags->index++;
	reset_flags(flags);
	while (find_flags(input[flags->index], flags, args))
		flags->index++;
	if (find_flags(input[flags->index], flags, args) == 0)
	{
		if (flags->minus == 1 && flags->zero == 1)
			flags->zero = 0;
		find_type(input, args, flags);
	}
	flags->index++;
	return (flags->index);
}

int		process_input(const char *input, va_list args, t_flags *flags)
{
	while (input[flags->index] && input[flags->index] != '%')
	{
		ft_putchar(input[flags->index], flags);
		flags->index++;
	}
	if (input[flags->index] == '\0')
		return (flags->index);
	if (input[flags->index] == '%')
		flags->index = process_percent(input, args, flags);
	return (flags->index);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;

	init_flags(&flags);
	va_start(args, input);
	while (input[flags.index] != '\0')
		flags.index = process_input(input, args, &flags);
	va_end(args);
	return (flags.count);
}
