/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:41:56 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 20:16:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "init_board.h"
#include "dfs.h"

int	validate_input(char *input)
{
	int	count_nb;
	int	i;

	count_nb = 0;
	i = 0;
	while (input[i] != '\x00')
	{
		if (i % 2 == 0)
		{
			if (input[i] >= '0' && input[i] <= '9')
				count_nb++;
			else
				return (0);
		}
		else
			if (input[i] != ' ')
				return (0);
		i++;
	}
	if (count_nb % 4 == 0)
		return (count_nb);
	return (0);
}

int	ft_prt_board(int **board, int len)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i <= len)
	{
		j = 1;
		while (j <= len)
		{
			c = (char)board[i][j] + '0';
			write(1, &c, 1);
			if (j != len)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	**board;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = validate_input(argv[1]);
	if (size == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	board = init_board(size / 4, argv[1]);
	if (dfs_start(board, size / 4))
	{
		ft_prt_board(board, size / 4);
		return (0);
	}
	write(1, "Error\n", 6);
	return (0);
}
