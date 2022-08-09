# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 20:23:35 by sgi               #+#    #+#              #
#    Updated: 2022/08/09 16:45:27 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MSRCS = 
MOBJS = 
BSRCS = 
BOBJS = 

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./include -I${LIBFTDIR} -I${PRINTFDIR}/include
LIB = -lft

RM = rm -r
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

PRINTFDIR = ./ft_printf
PRINTF = ${PRINTFDIR}/libftprintf.a

ifndef

${NAME} :	${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${LIB} -o $@ ${OBJS}

all :	${NAME}

bonus :
	${MAKE} BONUS=1

clean :	libftclean
	${RM} ${OBJS}
	${MAKE} ${MCDFLAG} ${LIBFTDIR} clean
	${MAKE} ${MCDFLAG} ${PRINTFDIR} clean

fclean :	clean libftfclean
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