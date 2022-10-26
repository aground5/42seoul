/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_asecnd_detail.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:24:43 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 16:07:37 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern const int	g_single_param;

bool	ps_prologue_ascend(t_queue *a, t_ext_queue *q)
{
	if (q->queue.size <= 1 || is_sorted(true, q))
		return (true);
	if (q->queue.size == 2)
	{
		if (q->queue.arr[q->queue.start] > q->queue.arr[q->queue.start + 1])
			ps_sa(a);
		return (true);
	}
	if (q->queue.size <= g_single_param)
		get_single_pivot(q);
	else
		get_multi_pivot(q);
	return (false);
}

void	ps_distribute_ascend(t_queue *a, t_queue *b, t_ext_queue *q)
{
	int	i;

	i = q->queue.start;
	while (i <= q->queue.end && q->end < q->queue.size)
	{
		if (q->queue.arr[q->queue.start] <= q->rpv)
		{
			ps_pb(a, b, q);
			if (b->arr[b->start] > q->lpv)
				ps_rb(b, true);
		}
		else
			ps_ra(a, false);
		i++;
	}
}

void	ps_restore_position_ascend(t_queue *a, t_ext_queue *q)
{
	int	i;

	i = 0;
	if (!(a->start == q->queue.start && a->end == q->queue.end))
	{
		while (i < ps_ra(NULL, false))
		{
			ps_rra(a);
			i++;
		}
	}
	ps_ra(NULL, true);
}

void	ps_first_miniqueue_ascend(t_queue *b, t_ext_queue *q,
				t_ext_queue *mq, int size)
{
	mq->queue.arr = b->arr;
	mq->queue.size = q->first;
	mq->queue.start = b->end - size - q->first - q->middle + 1;
	mq->queue.end = mq->queue.start + mq->queue.size - 1;
}

void	ps_second_miniqueue_ascend(t_queue *b, t_ext_queue *q,
				t_ext_queue *mq)
{
	int	i;

	i = 0;
	while (i < q->middle)
	{
		ps_rrb(b);
		i++;
	}
	mq->queue.arr = b->arr;
	mq->queue.size = q->middle;
	mq->queue.end = mq->queue.start + mq->queue.size - 1;
}
