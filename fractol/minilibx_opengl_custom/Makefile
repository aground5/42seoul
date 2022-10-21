## This Makefile is from original minilibx (opengl ver.)


## You should change ../mlx_opengl to your minilibx (opengl ver.) path.
ORG=../minilibx_opengl

NOM=$(ORG)/libmlx.a
SRC=mlx_get_screen_size.m
OBJ=$(SRC:.m=.o)
TEST_SRC=test_screen_size.c
CC=gcc
CFLAGS+=-O2 -w
RM=rm -f
#Add -w option to remove warning from compiling minilibx

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	make -C $(ORG)
	ar r $(NOM) $(OBJ)

clean:
	make clean -C $(ORG)
	$(RM) $(OBJ) ./a.out 

test: all
	$(CC) $(TEST_SRC) $(NOM) -framework OpenGL -framework AppKit
	@./a.out

re: clean all

%.o : %.m
	${CC} ${CFLAGS} -c $< -o $@ -I${ORG}