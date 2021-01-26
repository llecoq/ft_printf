/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:21 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 13:25:54 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
}
