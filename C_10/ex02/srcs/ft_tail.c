/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:46:36 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 20:46:37 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "ft_tail.h"

int	open_file(char* fileName)
{
	int	fd;

	fd = open(fileName, O_RDONLY);
	if (fd < 0)
	{
		
	}
}

int	start_tail(int option, int files, char **fileNames)
{
	int	i;
	int	err;

	err = 0;
	if (files == 0)
	{

	}
	else
	{
		i = 0;
		while (i < files)
		{
			err += open_file(fileNames[i]);
		}
	}
}
