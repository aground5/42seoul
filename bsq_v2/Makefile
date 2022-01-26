# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:33:23 by sgi               #+#    #+#              #
#    Updated: 2022/01/25 11:57:10 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/open_files.c ./srcs/open_files_2.c ./srcs/ft_stdlib.c ./srcs/main.c ./srcs/bsq_algorithm.c ./srcs/bsq_algorithm_2.c ./srcs/struct_manager.c
OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

INC	= -I./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

all:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
