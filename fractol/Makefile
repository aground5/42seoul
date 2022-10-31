# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 07:33:16 by sgi               #+#    #+#              #
#    Updated: 2022/10/31 21:12:40 by sgi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = ./src/fractol.c \
		./src/hardware_hook.c \
		./src/mandelbrot.c \
		./src/fractol_tools.c \
		./src/fractol_math.c \
		./src/fractol_draw.c \
		./src/fractol_draw_tools.c \
		./src/julia.c \
		./src/fractol_array_shift.c \
		./src/fractol_array_zoom.c
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
INC = -I./include -I${LIBFTDIR} -I${MLXDIR}
LIB = -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx

RM = rm -rf
MAKE = make -j
MCDFLAG = -C

LIBFTDIR = ./libft
LIBFT = ${LIBFTDIR}/libft.a

MLXDIR = ./minilibx_opengl
MLX = ${MLXDIR}/libmlx.a

${NAME} :	${LIBFT} ${MLX} ${OBJS}
	${CC} ${OBJS} ${LIB} -framework OpenGL -framework AppKit -o $@

all :	${NAME}

clean :
	${RM} ${OBJS}
	${MAKE} ${MCDFLAG} ${LIBFTDIR} clean
	${MAKE} ${MCDFLAG} ${MLXDIR} clean

fclean :	clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re :	fclean all

${LIBFT} :
	${MAKE} ${MCDFLAG} ${LIBFTDIR}

${MLX} :
	${MAKE} ${MCDFLAG} ${MLXDIR}

.PHONY : all bonus clean fclean re

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ ${INC}