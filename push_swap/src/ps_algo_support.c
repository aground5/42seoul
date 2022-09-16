/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_support.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:18:03 by sgi               #+#    #+#             */
/*   Updated: 2022/09/17 03:07:17 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_struct_init(t_queue *a, t_queue *b, int size)
{
	a->start = 0;
	a->end = size - 1;
	a->size = size;
	b->start = size;
	b->end = size - 1;
	b->size = 0;
}

void	ps_intarrcpy(int *dst, const int *src, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

bool	is_sorted(bool ascending, t_queue *q)
{
	int	i;

	i = q->start;
	if (ascending)
	{
		while (i <= q->end - 1)
		{
			if (q->arr[i] > q->arr[i + 1])
				return (false);
			i++;
		}
	}
	else
	{
		while (i <= q->end - 1)
		{
			if (q->arr[i] < q->arr[i + 1])
				return (false);
			i++;
		}
	}
	return (true);
}