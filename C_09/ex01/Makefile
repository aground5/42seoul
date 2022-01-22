SRCS	= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC	= gcc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

INC	= -I./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

all:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

${NAME}:	all

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
