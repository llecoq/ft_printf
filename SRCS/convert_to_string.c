/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:37:19 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/29 10:49:08 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*process_width(char *str, int len, t_flags *flags)
{
	if (flags->precision < 0 || flags->precision > len)
		flags->precision = len;
	if (flags->width < len)
	{
		if (flags->precision < len && flags->precision >= flags->width)
			len = flags->precision;
		else if (flags->precision < len && flags->precision < flags->width)
			len = flags->width;
	}
	else if (flags->width > len)
		len = flags->width;
	flags->start = len - flags->precision;
	str = ft_malloc(str, len);
	return (str);
}

void	convert_to_string(t_flags *flags, char *temp)
{
	int		len_temp;
	char	*str;

	str = NULL;
	if (temp == NULL)
		temp = "(null)";
	len_temp = ft_strlen(temp);
	if ((str = process_width(str, len_temp, flags)))
	{
		ft_memset(str, ' ', ft_strlen(str));
		if (flags->minus == 0)
			ft_memcpy(str + flags->start, temp, flags->precision);
		else if (flags->minus == 1)
			ft_memcpy(str, temp, flags->precision);
		ft_putstr(str, flags);
		free(str);
	}
}
