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

int	validate_option(t_argument *arg)
{
	int	offset;

	if (arg->argv[1][1] == 'c')
	{
		arg->option = OP_C;
		if (arg->argv[1][2] == '\x00')
		{
			if (arg->argc < 3)
				return (REQARG);
			offset = ft_atoi_positive(arg->argv[2]);
			if (offset == -1)
				return (ILGALOFSET);
		}
		else
		{
			offset = ft_atoi_positive(&arg->argv[1][2]);
			if (offset == -1)
				return (ILGALOFSET);
		}
	}
	else
		return (INVALIDOP);
	return (NORMEX);
}

int	main(int argc, char **argv)
{
	extern int	errno;
	int			err;
	int			i;
	t_argument	arg;

	arg.argc = argc;
	arg.argv = argv;	
	if (argc == 1)
		err = start_tail(DEFAULT, 0, NULL);
	i = 0;
	else if (argv[1][0] == '-')
	{
		err = validate_option(&arg);
	}
	else
	{
		err = start_tail(DEFAULT, argc - 1, &argv[1]);
	}
	
}
