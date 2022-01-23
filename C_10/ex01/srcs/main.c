/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:38 by sgi               #+#    #+#             */
/*   Updated: 2022/01/23 12:45:57 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include "ft_cat.h"

void	handle_error(char *filename, char *err_msg)
{
	write(1, "cat: ", 5);
	//filename = basename(filename);	TODO: is this right?
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	write(1, err_msg, ft_strlen(err_msg));
	write(1, "\n", 1);
}

void	write_file(int fd)
{
	char	c;

	while (read(fd, &c, 1) != 0)
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	char		c;
	int			i;
	int			fd;
	extern int	errno;

	(void)argv;
	if (argc == 1)
	{
		while (read(0, &c, 1) != 0)
		{
			write(1, &c, 1);
			write_file(0);
		}
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if (fd < 0)
			handle_error(argv[i], strerror(errno));
		else
			write_file(fd);
		i++;
	}
}
