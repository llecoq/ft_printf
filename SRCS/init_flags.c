/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:39:10 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 14:18:59 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->precision = -1;
	flags->count = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->index = 0;
	flags->start = 0;
	flags->dec = 0;
	flags->u = 0;
	flags->sign = '+';
}
/*
void	reset_bonus_flags(t_flags *flags)
{
	flags->sharp = 0;
	flags->space = 0;
}*/

void	reset_flags(t_flags *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->dec = 0;
	flags->u = 0;
	flags->start = 0;
	flags->precision = -1;
}
