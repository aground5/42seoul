#include "get_next_line_bonus.h"
#include "fcntl.h"

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
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[0]));
	for (int i = 0; i < 10; i++)
	{
		close(fd[i]);
	}
	system("leaks a.out");
	return (0);
}