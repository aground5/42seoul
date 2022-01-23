#include <fcntl.h>
#include <unistd.h>

void	write_file(int fd)
{
	char	c;

	c = 0;
	while (read(fd, &c, 1) != 0)
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	write_file(fd);
	return (0);
}