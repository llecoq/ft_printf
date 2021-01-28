/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:32:02 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/26 15:08:07 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

struct		s_flags
{
	int			width;
	int			minus;
	int			plus;
	int			zero;
	int			star;
	int			precision;
	int			sharp;
	int			space;
	int			count;
	int			index;
	long		dec;
	unsigned	u;
	int			start;
	char		sign;
};

typedef	struct s_flags	t_flags;

int			ft_printf(const char *input, ...);
void		convert_to_dec(va_list args, t_flags *flags);
void		convert_to_char(va_list args, t_flags *flags);
void		convert_to_string(t_flags *flags, char *temp);
void		convert_to_percent(t_flags *flags);
void		ft_putchar(char c, t_flags *flags);
void		init_flags(t_flags *flags);
void		reset_flags(t_flags *flags);
void		reset_bonus_flags(t_flags *flags);
void		ft_putstr(char const *s, t_flags *flags);
void		convert_to_unsigned_int(va_list args, t_flags *flags);
void		ft_putnbr(int n, t_flags *flags);
void		*ft_malloc(char *str, int len);
void		*init_str(char *str, int len, t_flags *flags);
void		*init_str_un(char *str, long len, t_flags *flags);
void		*set_mem(char *str, t_flags *flags, int len_temp, int len);
void		*process_positive(char *str, t_flags *flags, int len_temp);
void		*process_negative(char *str, t_flags *flags, int len_temp);
void		*fill_up_str(char *str, char *temp, t_flags *flags, int len_temp);
void		*fill_up_unsi(char *str, char *temp, t_flags *flags, int len_temp);
void		convert_to_hexa(t_flags *flags, unsigned int n);
void		convert_to_hexa_up(t_flags *flags, unsigned int n);
char		*ft_itoa_base(unsigned int value, char *base);
char		*ft_itoa_base_long(unsigned long long value, char *base);
void		convert_to_pointer(t_flags *flags, unsigned long long pointer);
void		find_type(const char *input, va_list args, t_flags *flags);

#endif
