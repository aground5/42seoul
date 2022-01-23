SRCS	= 
OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

CC	= gcc
CFLAGS	= -Werror -Wextra -Wall

RM	= rm -f

INC	= -I./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

${NAME}:	${OBJS}
	${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
