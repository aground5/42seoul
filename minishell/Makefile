# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 11:59:11 by sgi               #+#    #+#              #
#    Updated: 2022/07/28 17:28:05 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

MSRCS = ./src/minishell.c ./src/ms_echo.c
MOBJS = ${MSRCS:.c=.o}
BSRCS = 
BOBJS = ${BSRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./include -I${LIBFTDIR}
LIB = -L${LIBFTDIR} -lft -lreadline

RM = rm -r
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

ifndef BONUS
	SRCS = ${MSRCS}
	OBJS = ${MOBJS}
else
	SRCS = ${BSRCS}
	OBJS = ${BOBJS}
endif

${NAME} :	${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${LIB} -o $@ ${OBJS}

all :	${NAME}

bonus :
	${MAKE} BONUS=1

clean :
	${RM} ${OBJS}
	${MAKE} ${MCDFLAG} ${LIBFTDIR} clean

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

%o : %c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}