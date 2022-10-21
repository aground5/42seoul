# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 07:33:16 by sgi               #+#    #+#              #
#    Updated: 2022/10/21 20:27:02 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MSRCS = ./src/fractol.c \
		./src/hardware_hook.c \
		./src/mandelbrot.c \
		./src/fractol_tools.c \
		./src/fractol_math.c \
		./src/fractol_draw.c \
		./src/fractol_draw_tools.c \
		./src/julia.c \
		./src/fractol_array_shift.c
MOBJS = ${MSRCS:.c=.o}
BSRCS = 
BOBJS = ${BSRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
INC = -I./include -I${LIBFTDIR} -I${MLXDIR} -I${MLXCSTMDIR}
LIB = -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx

RM = rm -rf
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

MLXCSTMDIR = ./minilibx_opengl_custom
MLXDIR = ./minilibx_opengl
MLX = ${MLXDIR}/libmlx.a

ifndef BONUS
	SRCS = ${MSRCS}
	OBJS = ${MOBJS}
else
	SRCS = ${BSRCS}
	OBJS = ${BOBJS}
endif

${NAME} :	${LIBFT} ${MLX} ${OBJS}
	${CC} ${OBJS} ${LIB} -framework OpenGL -framework AppKit -o $@

all :	${NAME}

bonus :
	${MAKE} BONUS=1

clean :
	${RM} ${OBJS}
	${MAKE} ${MCDFLAG} ${LIBFTDIR} clean
	${MAKE} ${MCDFLAG} ${MLXCSTMDIR} clean

fclean :	clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re :	fclean all

${LIBFT} :
	${MAKE} ${MCDFLAG} ${LIBFTDIR}

${MLX} :
	${MAKE} ${MCDFLAG} ${MLXCSTMDIR}

.PHONY : all bonus clean fclean re

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}