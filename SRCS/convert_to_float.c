/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:23:23 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/29 10:43:48 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	treat_whole(t_flags *flags, char *decimal, char *whole)
{
	int		whole_len;

	whole_len = ft_strlen(whole);
	if (decimal[0] > 52)
		whole[whole_len - 1] += 1;
	if (flags->sign == '-')
		flags->width--;
	if (flags->minus == 1)
	{
		if (flags->sign == '-')
		{
			ft_putchar('-', flags);
			flags->width--;
		}
		ft_putstr(whole, flags);
		while (flags->width > whole_len)
		{
			ft_putchar(' ', flags);
			flags->width--;
		}
		return ;
	}
	while (flags->width > whole_len)
	{
		ft_putchar(' ', flags);
		flags->width--;
	}
	if (flags->sign == '-')
	{
		ft_putchar('-', flags);
		flags->width--;
	}
	ft_putstr(whole, flags);
	
}

void	print_float(char *decimal, char *whole, t_flags *flags)
{
	int		decimal_len;
	int		whole_len;
	int		total_len;

	decimal_len = ft_strlen(decimal);
	if (flags->sign == '-')
		decimal_len++;
	whole_len = ft_strlen(whole);
	total_len = decimal_len + whole_len + 1;
	if (flags->minus == 0)
	{
		while (total_len < flags->width)
		{
			ft_putchar(' ', flags);
			total_len++;
		}
		if (flags->sign == '-')
		{
			ft_putchar('-', flags);
		}
		ft_putstr(whole, flags);
		ft_putchar('.', flags);
		ft_putstr(decimal, flags);
		return ;
	}
	if (flags->sign == '-')
	{
		ft_putchar('-', flags);
		flags->width--;
	}
	ft_putstr(whole, flags);
	ft_putchar('.', flags);
	ft_putstr(decimal, flags);
	while (total_len < flags->width)
	{
		ft_putchar(' ', flags);
		total_len++;
	}
}

char	*treat_decimal(t_flags *flags, char *decimal)
{
	int		len;
	char	*temp;
	int		dec_ret;

	temp = NULL;
	dec_ret = 0;
	len = ft_strlen(decimal);
	if (len == 1)
		dec_ret = decimal[0] - 48;
	if (decimal[len - 1] > 52)
		decimal[len - 2] += 1;
	temp = ft_malloc(temp, flags->precision);
	ft_memset(temp, '0', flags->precision);
	while (len <= flags->precision)
	{
		flags->start++;
		len++;
	}
	ft_memmove(temp + flags->start, decimal, flags->precision - flags->start);
	free(decimal);
	decimal = temp;
	if (dec_ret > 4)
		decimal[flags->start - 1] += 1;
	return (decimal);
}

char	*break_down_double(t_flags *flags, long double f, char *decimal)
{
	long double		whole;
	long			n;
	int				preci;

	preci = flags->precision;
	whole = (int)f;
	f = f - whole;
	n = 10;
	while (preci > 0)
	{
		n *= 10;
		preci--;
	}
	f *= n;
	if (f < 0)
		f *= -1;
	decimal = ft_itoa_long((unsigned long)f);
	return (decimal);
}	

void	convert_to_float(t_flags *flags, long double f)
{
	char	*whole;
	char	*decimal;
	long	n;

	decimal = NULL;
	n = (int)f;
	whole = ft_itoa(n);
	if (n == 0 && f < 0)
		flags->sign = '-';
	if (flags->precision < 0)
		flags->precision = 6;
	decimal = break_down_double(flags, f, decimal);
	if (flags->precision == 0)
	{
		treat_whole(flags, decimal, whole);
		free(decimal);
		free(whole);
		return ;
	}
	decimal = treat_decimal(flags, decimal);
	print_float(decimal, whole, flags);
	free(decimal);
	free(whole);
	return ;	
}
