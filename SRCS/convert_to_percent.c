/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:19:20 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 13:32:42 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_to_percent(t_flags *flags)
{
	char	*str;
	char	*temp;

	str = NULL;
	temp = "%";
	if (flags->precision != 1)
		flags->precision = 1;
	if ((str = init_str(str, 1, flags)))
	{
		set_mem(str, flags, 1, ft_strlen(str));
		str = fill_up_str(str, temp, flags, 1);
		ft_putstr(str, flags);
		free(str);
	}
}
