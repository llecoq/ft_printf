/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:52:09 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 13:54:10 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_to_pointer(t_flags *flags, unsigned long long pointer)
{
	char					*hexa;
	char					*str;
	char					*temp;
	unsigned long long		len_temp;

	str = NULL;
	hexa = ft_itoa_base_long(pointer, "0123456789abcdef");
	str = ft_strdup("0x");
	if (flags->precision == 0 && pointer == 0)
	{
		free(hexa);
		hexa = ft_strdup("");
	}
	temp = ft_strjoin(str, hexa);
	free(str);
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
		free(str);
	}
	free(temp);
}
