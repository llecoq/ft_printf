/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:28:26 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 14:12:49 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	process_zero_width(char c, t_flags *flags)
{
	if (flags->precision == -1)
	{
		if (c == '0' && (flags->width > 0 || flags->zero == 1))
			flags->width = flags->width * 10 + c - 48;
		else if (c == '0' && flags->width == 0)
			flags->zero = 1;
		if (c > '0' && c <= '9')
			flags->width = flags->width * 10 + c - 48;
	}
	if (flags->precision >= 0)
		flags->precision = flags->precision * 10 + c - 48;
}

int		find_flags(char c, t_flags *flags, va_list args)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (0);
	else if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '.')
		flags->precision = 0;
	else if (c == '*')
		if (flags->precision == 0)
			flags->precision = va_arg(args, int);
		else
		{
			flags->width = va_arg(args, int);
			if (flags->width < 0)
			{
				flags->minus = 1;
				flags->width *= -1;
			}
		}
	else if (ft_isdigit(c))
		process_zero_width(c, flags);
	return (1);
}

int		process_percent(const char *input, va_list args, t_flags *flags)
{
	flags->index++;
	reset_flags(flags);
//	reset_bonus_flags(flags);
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
//	reset_bonus_flags(&flags);
	va_start(args, input);
	while (input[flags.index] != '\0')
		flags.index = process_input(input, args, &flags);
	va_end(args);
	return (flags.count);
}
