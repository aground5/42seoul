# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 13:46:52 by sgi               #+#    #+#              #
#    Updated: 2022/07/14 21:14:28 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./src/ft_printf.c ./src/ft_printf_util.c ./src/ft_printf_string.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

INC = -I./include

${NAME}:	${OBJS}
	ar rc $@ $^
	ranlib $@

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INC}