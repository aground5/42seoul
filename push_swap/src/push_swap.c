/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:42:04 by sgi               #+#    #+#             */
/*   Updated: 2022/08/09 17:07:39 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	
	if (argc < 2)
		return (1);
	a = validate_arguements(argc - 1, &argv[1]);
}

int	*validate_arguements(int argn, char **argv)
{
	int	i;
	int	*ret;

	ret = (int *)malloc(sizeof(int) * argn);
	while (i < argn)
	{
		
		i++;
	}
}

int	push_swap_atoi(char *s)
{
	int	ret;
	
	
	ret = ft_atoi(argv[i]);
	
	returm(ret);
}