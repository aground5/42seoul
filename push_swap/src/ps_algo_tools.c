/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:40:09 by sgi               #+#    #+#             */
/*   Updated: 2022/09/17 13:04:55 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_queue *a, t_queue *b, t_ext_queue *q)
{
	a->start -= 1;
	a->size += 1;
	a->arr[a->start] = b->arr[b->start];
	b->start += 1;
	b->size -= 1;
	if (q != NULL)
	{
		q->queue.start += 1;
		q->queue.size -= 1;
	}
	ps_log_move("pa");
}

void	ps_pb(t_queue *a, t_queue *b, t_ext_queue *q)
{
	b->start -= 1;
	b->size += 1;
	b->arr[b->start] = a->arr[a->start];
	a->start += 1;
	a->size -= 1;
	if (q != NULL)
	{
		q->queue.start += 1;
		q->queue.size -= 1;
	}
	ps_log_move("pb");
}

void	ps_sa(t_queue *a)
{
	int	tmp;

	tmp = a->arr[a->start];
	a->arr[a->start] = a->arr[a->start + 1];
	a->arr[a->start + 1] = tmp;
	ps_log_move("sa");
}

void	ps_sb(t_queue *b)
{
	int	tmp;

	tmp = b->arr[b->start];
	b->arr[b->start] = b->arr[b->start + 1];
	b->arr[b->start + 1] = tmp;
	ps_log_move("sb");
}
