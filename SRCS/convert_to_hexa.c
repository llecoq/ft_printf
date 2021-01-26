/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:13:35 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/25 17:34:22 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_to_hexa_up(t_flags *flags, unsigned int n)
{
	char					*temp;
	char					*str;
	unsigned int			len_temp;

	str = NULL;
	temp = ft_itoa_base(n, "0123456789ABCDEF");
	len_temp = ft_strlen(temp);
	flags->dec = 1;
	if (flags->zero == 1)
		flags->sign = '0';
	if (flags->width < 0)
		flags->width *= -1;
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

void	convert_to_hexa(t_flags *flags, unsigned int n)
{
	char					*temp;
	char					*str;
	unsigned int			len_temp;
	int						len;

	str = NULL;
	temp = ft_itoa_base(n, "0123456789abcdef");
	len_temp = ft_strlen(temp);
	flags->dec = 1;
	if (flags->zero == 1)
		flags->sign = '0';
	if (flags->width < 0)
		flags->width *= -1;
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
