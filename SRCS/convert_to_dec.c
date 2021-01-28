/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:17:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/27 16:20:28 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*process_negative(char *str, t_flags *flags, int len_temp)
{
	int len;

	len = ft_strlen(str);
	if (flags->minus == 1)
		str[0] = flags->sign;
	else if (flags->minus == 0)
	{
		if (flags->precision <= -1 && flags->zero == 1)
			str[0] = flags->sign;
		else if (flags->precision != -1 || flags->zero != 1)
		{
			if (flags->precision >= len_temp)
				str[len - flags->precision - 1] = flags->sign;
			else if (flags->precision < len_temp)
				str[len - len_temp] = flags->sign;
		}
	}
	if (flags->minus == 0)
		flags->start = len - len_temp;
	else if (flags->minus == 1)
		if (flags->precision > 0 && flags->precision >= len_temp)
			flags->start = flags->precision - len_temp + 1;
	flags->start++;
	return (str);
}

void	*process_positive(char *str, t_flags *flags, int len_temp)
{
	int len;

	len = ft_strlen(str);
	if (flags->minus == 0)
		flags->start = len - len_temp;
	else if (flags->minus == 1)
	{
		if (flags->precision > 0 && flags->precision > len_temp)
			flags->start = flags->precision - len_temp;
		if (flags->plus == 1 && flags->dec >= 0 && flags->precision > len_temp)
			flags->start++;
		if (flags->space == 1 && flags->dec >= 0 && flags->precision > len_temp)
			flags->start++;
	}
	return (str);
}

void	convert_to_dec(va_list args, t_flags *flags)
{
	int		len_temp;
	char	*str;
	char	*temp;

	str = NULL;
	flags->dec = va_arg(args, int);
	if (flags->dec < 0)
		flags->sign = '-';
	if (flags->dec >= 0 && flags->space == 1)
		flags->sign = ' ';
	temp = ft_itoa((int)flags->dec);
	len_temp = ft_strlen(temp);
	if ((str = init_str(str, len_temp, flags)))
	{
		set_mem(str, flags, len_temp, ft_strlen(str));
		if (flags->dec >= 0)
			process_positive(str, flags, len_temp);
		else if (flags->dec < 0)
			process_negative(str, flags, len_temp);
		str = fill_up_str(str, temp, flags, len_temp);
		ft_putstr(str, flags);
		free(str);
	}
	if (temp)
		free(temp);
}
