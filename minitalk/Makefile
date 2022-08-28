# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 14:51:23 by sgi               #+#    #+#              #
#    Updated: 2022/07/27 20:37:36 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

DIRMANDA = ./src
MSERVER_SRCS = ${DIRMANDA}/server.c ${DIRMANDA}/server_handler.c
MCLIENT_SRCS = ${DIRMANDA}/client.c
MSERVER_OBJS = ${MSERVER_SRCS:.c=.o}
MCLIENT_OBJS = ${MCLIENT_SRCS:.c=.o}

DIRBONUS = ./src_bonus
BSERVER_SRCS = ${DIRBONUS}/server_bonus.c ${DIRBONUS}/server_handler_bonus.c
BCLIENT_SRCS = ${DIRBONUS}/client_bonus.c
BSERVER_OBJS = ${BSERVER_SRCS:.c=.o}
BCLIENT_OBJS = ${BCLIENT_SRCS:.c=.o}

CC = cc
RM = rm -f

MAKE = make -j
MCDFLAG = -C

CFLAGS = -Wall -Werror -Wextra
MINC = -I./include -I${DIRLIBFT} -I${DIRPRINTF}/include
BINC = -I./include_bonus -I${DIRLIBFT} -I${DIRPRINTF}/include
LIB = -lft -lftprintf -L${DIRLIBFT} -L${DIRPRINTF}

LIBFT = ${DIRLIBFT}/libft.a
PRINTF = ${DIRPRINTF}/libftprintf.a

DIRLIBFT = ./libft
DIRPRINTF = ./ft_printf

ifndef BONUS
	SERVER_OBJS = ${MSERVER_OBJS}
	CLIENT_OBJS = ${MCLIENT_OBJS}
	INC = ${MINC}
else
	SERVER_OBJS = ${BSERVER_OBJS}
	CLIENT_OBJS = ${BCLIENT_OBJS}
	INC = ${BINC}
endif

${NAME} :	${SERVER} ${CLIENT}
ifndef BONUS
	${MAKE} bclean
else
	${MAKE} mclean
endif
	
all:	${NAME}

${SERVER}:	${SERVER_OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${LIB} -o $@ ${SERVER_OBJS}

${CLIENT}: 	${CLIENT_OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${LIB} -o $@ ${CLIENT_OBJS}

bonus:
	${MAKE} BONUS=1

clean:	mclean bclean
	${MAKE} ${MCDFLAG} ${DIRLIBFT} clean
	${MAKE} ${MCDFLAG} ${DIRPRINTF} clean

mclean:
	${RM} ${MSERVER_OBJS} ${MCLIENT_OBJS}

bclean:
	${RM} ${BSERVER_OBJS} ${BCLIENT_OBJS}

fclean:	clean
	${RM} ${LIBFT}
	${RM} ${PRINTF}
	${RM} ${SERVER}
	${RM} ${CLIENT}

re:	fclean all

${LIBFT} :
	${MAKE} ${MCDFLAG} ${DIRLIBFT}

${PRINTF} :
	${MAKE} ${MCDFLAG} ${DIRPRINTF}

.PHONY:	all clean fclean re bonus mclean bclean

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}