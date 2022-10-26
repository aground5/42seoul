# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 20:23:35 by sgi               #+#    #+#              #
#    Updated: 2022/10/26 19:39:24 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ./src/push_swap.c ./src/ps_tools.c ./src/ps_algo.c ./src/ps_algo_tools.c ./src/ps_algo_tools2.c ./src/quicksort.c ./src/ps_algo_support.c ./src/ps_op_log.c ./src/ps_linked_list.c ./src/ps_algo_asecnd_detail.c ./src/ps_algo_desecnd_detail.c
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INC = -I./include -I${LIBFTDIR} -I${PRINTFDIR}/include
LIB = -L${LIBFTDIR} -lft -L${PRINTFDIR} -lftprintf

RM = rm -rf
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

PRINTFDIR = ./ft_printf
PRINTF = ${PRINTFDIR}/libftprintf.a

${NAME} :	${LIBFT} ${PRINTF} ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS} ${LIB}

all :	${NAME}

bonus :
	${MAKE} BONUS=1

clean :
	${RM} ${OBJS}
	${MAKE} ${MCDFLAG} ${LIBFTDIR} clean
	${MAKE} ${MCDFLAG} ${PRINTFDIR} clean

fclean :	clean
	${RM} ${LIBFT}
	${RM} ${PRINTF}
	${RM} ${NAME}

re :	fclean all

${LIBFT} :
	${MAKE} ${MCDFLAG} ${LIBFTDIR}

${PRINTF} :
	${MAKE} ${MCDFLAG} ${PRINTFDIR}

.PHONY : all bonus clean fclean re

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}