# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 12:33:37 by sgi               #+#    #+#              #
#    Updated: 2022/01/25 12:33:38 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/do-op.c ./srcs/ft_atoi.c ./srcs/ft_putnbr.c ./srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC	= gcc
CFLAGS	= -Werror -Wextra -Wall

RM	= rm -f

INC	= -I./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all
