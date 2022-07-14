# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 13:46:52 by sgi               #+#    #+#              #
#    Updated: 2022/07/13 14:21:27 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_util.c ft_printf_string.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

INC = -I./

${NAME}:	${OBJS}
	ar rc $@ ${OBJS}
	ranlib $@

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@