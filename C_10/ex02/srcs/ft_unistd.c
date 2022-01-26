int	write_file(int fd)
{
	char	c;
	int		bytes;

	bytes = 0;
	while (read(fd, &c, 1) != 0)
	{
		bytes++;
		write(1, &c, 1);
	}
	return (bytes);
}

int	open_file(char *pdname, char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		handle_error(pdname, filename, strerror(errno));
		return (1);
	}
	else
	{
		write_file(fd);
		close(fd);
	}
	return (0);
}
