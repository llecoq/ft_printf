/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:17:15 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 12:16:41 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*fill_up_str(char *str, char *temp, t_flags *flags, int len_temp)
{
	int len;

	len = ft_strlen(str);
	if (flags->precision == 0 && flags->dec == 0)
		if (ft_memset(str, ' ', len))
			return (str);
	if (flags->dec >= 0)
		ft_memcpy(str + flags->start, temp, len_temp);
	if (flags->dec < 0)
		ft_memcpy(str + flags->start, temp + 1, len_temp - 1);
	return (str);
}

void	*ft_malloc(char *str, int len)
{
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	return (str);
}

void	*fill_up_unsi(char *str, char *temp, t_flags *flags, int len_temp)
{
	int len;

	len = ft_strlen(str);
	if (flags->precision == 0 && flags->u == 0)
		if (ft_memset(str, ' ', len))
			return (str);
	ft_memcpy(str + flags->start, temp, len_temp);
	return (str);
}

void	*init_str_un(char *str, long len, t_flags *flags)
{
	if (flags->precision == 0 && flags->u == 0 && flags->width == 0)
		return (NULL);
	if (len < flags->width || flags->precision >= len)
	{
		if (flags->width != 0 || flags->precision != 0)
		{
			if (flags->width > 0)
			{
				if (flags->precision > flags->width)
					len = flags->precision;
				else if (flags->width >= flags->precision && flags->width > len)
					len = flags->width;
			}
			else if (flags->width == 0)
			{
				if (len < flags->precision)
					len = flags->precision;
			}
			if (flags->dec < 0 && flags->width <= flags->precision)
				if (flags->precision >= len)
					len++;
		}
	}
	if (flags->plus == 1 && flags->dec > 0)
		len++;
	str = ft_malloc(str, len);
	return (str);
}

void	convert_to_unsigned_int(va_list args, t_flags *flags)
{
	int		len_temp;
	char	*str;
	char	*temp;

	str = NULL;
	flags->u = va_arg(args, unsigned);
	temp = ft_itoa_unsigned(flags->u);
	len_temp = ft_strlen(temp);
	if ((str = init_str_un(str, len_temp, flags)))
	{
		set_mem(str, flags, len_temp, ft_strlen(str));
		process_positive(str, flags, len_temp);
		str = fill_up_unsi(str, temp, flags, len_temp);
		ft_putstr(str, flags);
		free(str);
	}
	free(temp);
}
