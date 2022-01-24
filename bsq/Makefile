SRCS	= ./srcs/ft_ctype.c ./srcs/open_files.c ./srcs/ft_stdlib.c ./srcs/main.c
OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC	= gcc
CFLAGS	= -Wall -Wextra -Wall

RM	= rm -f

INC	= -I./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

all:	${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
