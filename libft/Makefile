SRCS = ft_additional.c  ft_ctype.c  ft_ctype2.c  ft_itoa.c  ft_putchar_fd.c  ft_split.c  ft_stdlib.c  ft_string.c  ft_string2.c  ft_string3.c  ft_striteri.c  ft_strmapi.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

INC = -I./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all