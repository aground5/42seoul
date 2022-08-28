/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:42:04 by sgi               #+#    #+#             */
/*   Updated: 2022/08/28 14:20:41 by sgi              ###   ########.fr       */
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
	int	*a;

	if (argc < 2)
		return (1);
	a = validate_arguements(argc - 1, &argv[1]);
	if (a == NULL)
	{
		write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	algo_init(a, argc - 1);
	print_op(ps_log_move(NULL));
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
