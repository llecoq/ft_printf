/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:53:31 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/28 09:13:05 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_malloc(char *str, int len)
{
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	return (str);
}

void	set_mem_plus_space(char *str, t_flags *flags, int len_temp, int len)
{
	if (flags->minus == 1 || (len == len_temp - flags->precision))
	{
		str[0] = flags->sign;
		if (flags->dec >= 0)
			flags->start++;
	}
	else if (flags->minus == 0 && flags->precision > 0)
	{
		if (flags->precision >= len_temp)
			str[len - flags->precision - 1] = flags->sign;
	}
	else if (flags->minus == 0 && flags->precision < len_temp)
		str[len - len_temp - 1] = flags->sign;
}

void	*set_mem(char *str, t_flags *flags, int len_temp, int len)
{
	if (flags->zero == 1 && flags->precision < 0)
		ft_memset(str, '0', len);
	else if (flags->zero != 1 || flags->precision != -1)
	{
		ft_memset(str, ' ', len);
		if (flags->minus == 0 && flags->precision >= len_temp)
			ft_memset(str + len - flags->precision, '0', flags->precision);
		else if (flags->minus == 1 && flags->precision > 0)
			ft_memset(str, '0', flags->precision);
	}
	if (flags->plus == 1 || flags->space == 1)
		set_mem_plus_space(str, flags, len_temp, len);
	return (str);
}

int		process_width_dec(int len, t_flags *flags)
{
	if (len < flags->width || flags->precision >= len)
	{
		if (flags->width != 0 || flags->precision != 0)
		{
			if (flags->width > 0)
			{
				if (flags->precision > flags->width)
					len = flags->precision;
				else if (flags->width >= flags->precision)
					len = flags->width;
			}
			else if (flags->width == 0)
			{
				if (len < flags->precision)
					len = flags->precision;
			}
			if (flags->dec < 0 && flags->width <= flags->precision)
			{
				if (flags->precision >= len)
					len++;
			}
		}
	}
	return (len);
}

void	*init_str(char *str, int len, t_flags *flags)
{
	if (flags->plus != 1 && flags->space != 1)
		if (flags->precision == 0 && flags->dec == 0 && flags->width == 0)
			return (NULL);
	if (flags->plus == 1 || flags->space == 1)
		if (flags->precision == 0 && flags->dec == 0 && flags->width == 0)
			if ((str = ft_malloc(str, len)))
				return (str);
	len = process_width_dec(len, flags);
	if (len < flags->width || len == flags->precision || len == 1)
		if ((flags->plus || flags->space) && flags->dec >= 0)
			len++;
	str = ft_malloc(str, len);
	return (str);
}
