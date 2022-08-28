/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:49:16 by sgi               #+#    #+#             */
/*   Updated: 2022/08/21 17:48:37 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_queue *a)
{
	int	tmp;
	int	i;

	tmp = a->arr[a->start];
	i = a->start + 1;
	while (i < a->start + a->size)
	{
		a->arr[i - 1] = a->arr[i];
		i++;
	}
	a->arr[a->start + a->size - 1] = tmp;
	ps_log_move("ra");
}

void	ps_rb(t_queue *b)
{
	int	tmp;
	int	i;

	tmp = b->arr[b->start];
	i = b->start + 1;
	while (i < b->start + b->size)
	{
		b->arr[i - 1] = b->arr[i];
		i++;
	}
	b->arr[b->start + b->size - 1] = tmp;
	ps_log_move("rb");
}

void	ps_rra(t_queue *a)
{
	int	tmp;
	int	i;

	tmp = a->arr[a->start + a->size - 1];
	i = a->start + a->size - 1;
	while (i > a->start)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[a->start] = tmp;
	ps_log_move("rra");
}

void	ps_rrb(t_queue *b)
{
	int	tmp;
	int	i;

	tmp = b->arr[b->start + b->size - 1];
	i = b->start + b->size - 1;
	while (i > b->start)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[b->start] = tmp;
	ps_log_move("rrb");
}
