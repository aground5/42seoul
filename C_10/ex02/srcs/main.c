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

#include "ft_tail.h"

void	handle_error(char *pgname, char *filename, char *err_msg)
{
	pgname = basename(pgname);
	write(1, pgname, ft_strlen(pgname));
	write(1, ": ", 2);
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	write(1, err_msg, ft_strlen(err_msg));
	write(1, "\n", 1);
}

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

int	valid_option(int argc, char **argv)
{
	if (argv[1][1] == 'c')
	{
		if (argv[1][2] == '\x00')
		{
			if (argc < 3)
				return (REQARG);
		}
		else
		{
			if
		}
		
	}
	else
		return (INVALIDOP);
}

int	main(int argc, char **argv)
{
	extern int	errno;
	int			err;
	int			fileStartIndex;

	err = NORMEX;
	if (argc == 1)
	{

	}
	else if (argv[1][0] == '-')
	{
		err = valid_option(argc, argv);
	}
	else
	{
		/* code */
	}
	
}
