# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 10:49:46 by llecoq            #+#    #+#              #
#    Updated: 2021/01/26 13:55:26 by llecoq           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c srcs/convert_to_dec.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/convert_to_unsigned.c srcs/convert_to_char.c srcs/init_flags.c srcs/convert_to_string.c srcs/convert_to_hexa.c srcs/ft_itoa_base.c srcs/convert_to_pointer.c srcs/ft_itoa_base_long.c srcs/find_type.c srcs/convert_to_percent.c

SURPL_O = ft_printf.o srcs/convert_to_dec.o srcs/ft_putchar.o srcs/ft_putstr.o srcs/convert_to_unsigned.o srcs/convert_to_char.o srcs/init_flags.o srcs/convert_to_string.o srcs/convert_to_hexa.o srcs/ft_itoa_base.o srcs/convert_to_pointer.o srcs/ft_itoa_base_long.o srcs/find_type.o srcs/convert_to_percent.o

CC = gcc

FLAGS = # -c  -Wall -Wextra -Werror #
INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
