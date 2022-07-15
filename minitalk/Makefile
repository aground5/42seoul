# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 14:51:23 by sgi               #+#    #+#              #
#    Updated: 2022/07/15 15:04:36 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS = ./src/server.c ./src/server_handler.c
CLIENT_SRCS = ./src/client.c

SERVER_OBJS = ${SERVER_SRCS:.c=.o}
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}

NAME = minitalk
SERVER = server
CLIENT = client

CC = cc
RM = rm -f

MAKE = make -j
MCDFLAG = -C

CFLAGS = -Wall -Werror -Wextra -g
INC = -I./include -I${DIRLIBFT} -I${DIRPRINTF}/include
LIB = -lft -lftprintf -L${DIRLIBFT} -L${DIRPRINTF}

LIBFT = ${DIRLIBFT}/libft.a
PRINTF = ${DIRPRINTF}/libftprintf.a

DIRLIBFT = ./libft
DIRPRINTF = ./ft_printf

${NAME} :	${SERVER} ${CLIENT}

test : ${LIBFT} ${PRINTF} ./src/test.o
	${CC} ${CFLAGS} ${LIB} -o $@ ./src/test.o
	
all:	${NAME}

${SERVER}:	${SERVER_OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${LIB} -o $@ ${SERVER_OBJS}

${CLIENT}: 	${CLIENT_OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${LIB} -o $@ ${CLIENT_OBJS}

clean:
	${MAKE} ${MCDFLAG} ${DIRLIBFT} clean
	${MAKE} ${MCDFLAG} ${DIRPRINTF} clean
	${RM} ${SERVER_OBJS}
	${RM} ${CLIENT_OBJS}

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

.PHONY:	all clean fclean re

%o : %c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}