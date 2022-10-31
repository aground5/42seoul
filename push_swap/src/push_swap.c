/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:42:04 by sgi               #+#    #+#             */
/*   Updated: 2022/10/31 18:03:16 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char **log)
{
	int	i;

	i = 0;
	while (log[i] != NULL)
	{
		ft_printf("%s\n", log[i]);
		i++;
	}
	free(log);
}

int	main(int argc, char **argv)
{
	int		*a;
	char	**num_arg;
	int		size;

	if (argc < 2)
		return (1);
	size = argc - 1;
	num_arg = &argv[1];
	if (argc == 2)
		num_arg = parse_onearg(argv[1], &size);
	a = validate_arguements(size, num_arg);
	if (a == NULL)
	{
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	algo_init(a, size);
	print_op(ps_optimize_move());
	if (argc == 2)
		free_split(num_arg);
	return (0);
}

int	*validate_arguements(int argn, char **argv)
{
	int	i;
	int	*ret;

	ret = (int *)malloc(sizeof(int) * argn);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < argn)
	{
		ret[i] = ft_atoi(argv[i]);
		if (ft_atoi_strictform_overflow(ret[i], argv[i]))
		{
			free(ret);
			return (NULL);
		}
		i++;
	}
	if (is_duplicated(ret, argn))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

bool	is_duplicated(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

char	**parse_onearg(char *onearg, int *size)
{
	char	**split;

	split = ft_split(onearg, ' ');
	*size = 0;
	while (split[*size] != 0)
	{
		(*size)++;
	}
	return (split);
}
