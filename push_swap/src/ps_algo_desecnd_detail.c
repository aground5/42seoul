/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_desecnd_detail.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:24:43 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 16:07:43 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern const int	g_single_param;

bool	ps_prologue_descend(t_queue *b, t_ext_queue *q)
{
	if (q->queue.size <= 1 || is_sorted(false, q))
		return (true);
	if (q->queue.size == 2)
	{
		if (q->queue.arr[q->queue.start] < q->queue.arr[q->queue.start + 1])
			ps_sb(b);
		return (true);
	}
	if (q->queue.size <= g_single_param)
		get_single_pivot(q);
	else
		get_multi_pivot(q);
	return (false);
}

void	ps_distribute_descend(t_queue *a, t_queue *b, t_ext_queue *q)
{
	int	i;

	i = q->queue.start;
	while (i <= q->queue.end && q->first < q->queue.size)
	{
		if (q->queue.arr[q->queue.start] > q->lpv)
		{
			ps_pa(a, b, q);
			if (a->arr[a->start] <= q->rpv)
				ps_ra(a, true);
		}
		else
			ps_rb(b, false);
		i++;
	}
}

void	ps_restore_position_descend(t_queue *a, t_queue *b, t_ext_queue *q)
{
	int	i;

	i = 0;
	if (!(a->start == q->queue.start && a->end == q->queue.end))
	{
		while (i < ps_rb(NULL, false))
		{
			ps_rrb(b);
			i++;
		}
	}
	ps_rb(NULL, true);
}

void	ps_first_miniqueue_descend(t_queue *a, t_ext_queue *q,
				t_ext_queue *mq, int size)
{
	mq->queue.arr = a->arr;
	mq->queue.size = q->end;
	mq->queue.start = a->end - size - q->end - q->middle + 1;
	mq->queue.end = mq->queue.start + mq->queue.size - 1;
}

void	ps_second_miniqueue_descend(t_queue *a, t_ext_queue *q,
				t_ext_queue *mq)
{
	int	i;

	i = 0;
	while (i < q->middle)
	{
		ps_rra(a);
		i++;
	}
	mq->queue.arr = a->arr;
	mq->queue.size = q->middle;
	mq->queue.end = mq->queue.start + mq->queue.size - 1;
}
