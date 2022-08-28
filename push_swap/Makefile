# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 20:23:35 by sgi               #+#    #+#              #
#    Updated: 2022/08/28 21:20:41 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MSRCS = ./src/push_swap.c ./src/ps_tools.c ./src/ps_algo.c ./src/ps_algo_tools.c ./src/ps_algo_tools2.c ./src/quicksort.c ./src/ps_algo_support.c
MOBJS = ${MSRCS:.c=.o}
BSRCS = 
BOBJS = 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I./include -I${LIBFTDIR} -I${PRINTFDIR}/include
LIB = -L${LIBFTDIR} -lft -L${PRINTFDIR} -lftprintf

RM = rm -rf
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

PRINTFDIR = ./ft_printf
PRINTF = ${PRINTFDIR}/libftprintf.a

ifndef BONUS
	SRCS = ${MSRCS}
	OBJS = ${MOBJS}
else
	SRCS = ${BSRCS}
	OBJS = ${BOBJS}
endif

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