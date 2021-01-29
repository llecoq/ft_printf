# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:20:12 by llecoq            #+#    #+#              #
#    Updated: 2021/01/28 13:21:58 by llecoq           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS		= ft_printf.c srcs/convert_to_dec.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/convert_to_unsigned.c srcs/convert_to_char.c srcs/init_flags.c srcs/convert_to_string.c srcs/convert_to_hexa.c srcs/ft_itoa_base.c srcs/convert_to_pointer.c srcs/ft_itoa_base_long.c srcs/find_type.c srcs/convert_to_percent.c srcs/convert_to_hexa_up.c srcs/init_mem_str.c srcs/convert_to_float.c 

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIBFT 			= libft

CC				= gcc
CFLAGS 			=# -Wall -Wextra -Werror #
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
