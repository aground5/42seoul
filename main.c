#include "get_next_line_bonus.h"
#include "fcntl.h"

void print_line(int fd);

int	main(void)
{
	int fd[10];

	for (int i = 0; i < 10; i++)
	{
		fd[i] = open("./test.txt", O_RDWR);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", fd[i]);
	}
	printf("\n");
	// for (int j = 0; j < 5; j++)
	// {
	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		printf("%s", get_next_line(fd[i]));
	// 		printf("%s", get_next_line(fd[i]));
	// 		printf("%s", get_next_line(fd[i]));
	// 		printf("%s", get_next_line(fd[i]));
	// 	}
	// }

	print_line(fd[1]);
	print_line(fd[2]);
	print_line(fd[3]);
	print_line(fd[4]);
	print_line(fd[1]);
	print_line(fd[1]);
	print_line(fd[5]);
	print_line(fd[6]);
	print_line(fd[2]);
	print_line(fd[3]);
	print_line(fd[4]);
	print_line(fd[2]);
	print_line(fd[3]);
	print_line(fd[4]);
	print_line(fd[5]);
	print_line(fd[6]);
	print_line(fd[5]);
	print_line(fd[6]);

	for (int i = 0; i < 10; i++)
	{
		close(fd[i]);
	}
	system("leaks a.out");
	return (0);
}

void print_line(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}