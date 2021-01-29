/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:21 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/28 12:56:30 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		process_zero_width(char c, t_flags *flags)
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

void		process_star(t_flags *flags, va_list args)
{
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
}

int			find_flags(char c, t_flags *flags, va_list args)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%' || c == 'n' || c == 'f')
		return (0);
	else if (c == '-')
		flags->minus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->sharp = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '.')
		flags->precision = 0;
	else if (c == '*')
		process_star(flags, args);
	else if (ft_isdigit(c))
		process_zero_width(c, flags);
	return (1);
}

void		convert_to_n(t_flags *flags, int *p)
{
	*p = flags->count;
}

void		find_type(const char *input, va_list args, t_flags *flags)
{
	if (input[flags->index] == 'c')
		convert_to_char(args, flags);
	if (input[flags->index] == 's')
		convert_to_string(flags, va_arg(args, char *));
	if (input[flags->index] == 'p')
		convert_to_pointer(flags, va_arg(args, unsigned long long));
	if (input[flags->index] == 'd')
		convert_to_dec(args, flags);
	if (input[flags->index] == 'i')
		convert_to_dec(args, flags);
	if (input[flags->index] == 'u')
		convert_to_unsigned_int(args, flags);
	if (input[flags->index] == 'x')
		convert_to_hexa(flags, va_arg(args, unsigned int));
	if (input[flags->index] == 'X')
		convert_to_hexa_up(flags, va_arg(args, unsigned int));
	if (input[flags->index] == '%')
		convert_to_percent(flags);
	if (input[flags->index] == 'n')
		convert_to_n(flags, va_arg(args, int *));
	if (input[flags->index] == 'f')
		convert_to_float(flags, (long double)va_arg(args, double));
}
