/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:52:09 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/29 15:35:13 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	treat_null_pointer(t_flags *flags, char *hexa, unsigned long long p)
{
	if (flags->precision == 0 && p == 0)
	{
		free(hexa);
		hexa = ft_strdup("");
	}
}

void	convert_to_pointer(t_flags *flags, unsigned long long pointer)
{
	char					*hexa;
	char					*str;
	char					*temp;
	unsigned long long		len_temp;

	str = "0x";
	temp = NULL;
	hexa = ft_itoa_base_long(pointer, "0123456789abcdef");
	treat_null_pointer(flags, hexa, pointer);
	temp = ft_strjoin(str, hexa);
	free(hexa);
	len_temp = ft_strlen(temp);
	flags->dec = 1;
	if (flags->width < 0)
		flags->width *= -1;
	if ((str = init_str(str, len_temp, flags)))
	{
		set_mem(str, flags, len_temp, ft_strlen(str));
		process_positive(str, flags, len_temp);
		str = fill_up_str(str, temp, flags, len_temp);
		ft_putstr(str, flags);
	}
	free(temp);
	if (str)
		free(str);
}
