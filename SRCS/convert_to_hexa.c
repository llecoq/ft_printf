/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:13:35 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/27 17:39:18 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_flags(t_flags *flags)
{
	flags->dec = 1;
	if (flags->zero == 1)
		flags->sign = '0';
	if (flags->width < 0)
		flags->width *= -1;
}

void	print_sharp_left(char *temp, int len_temp, t_flags *flags)
{
	int		i;

	i = 0;
	ft_putstr("0x", flags);
	while (flags->precision > len_temp)
	{
		ft_putchar('0', flags);
		flags->precision--;
		i++;
	}
	ft_putstr(temp, flags);
	if (flags->precision >= len_temp)
		while (i + 3 < flags->width)
		{
			ft_putchar(' ', flags);
			i++;
		}
}

void	treat_sharp(char *temp, int len, t_flags *flags)
{
	if (flags->minus == 1)
		print_sharp_left(temp, len, flags);
	if (flags->minus == 0)
	{
		while (flags->width - 2 > len && flags->width - 2 > flags->precision)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		ft_putstr("0x", flags);
		while (flags->precision - len > 0)
		{
			ft_putchar('0', flags);
			flags->precision--;
		}
		ft_putstr(temp, flags);
	}
	free(temp);
}

void	convert_to_hexa(t_flags *flags, unsigned int n)
{
	char					*temp;
	char					*str;
	unsigned int			len_temp;

	str = NULL;
	temp = ft_itoa_base(n, "0123456789abcdef");
	len_temp = ft_strlen(temp);
	if (flags->sharp == 1 && n != 0)
	{
		treat_sharp(temp, len_temp, flags);
		return ;
	}
	set_flags(flags);
	if (n == 0 && flags->precision == 0 && flags->width == 0)
		return ;
	if ((str = init_str(str, len_temp, flags)))
	{
		set_mem(str, flags, len_temp, ft_strlen(str));
		process_positive(str, flags, len_temp);
		if (!(n == 0 && flags->precision == 0))
			str = fill_up_str(str, temp, flags, len_temp);
		ft_putstr(str, flags);
		free(str);
	}
	free(temp);
}
