/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:40 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 16:08:18 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const int	g_single_param = 6;

void	algo_init(int *a_arr, int size)
{
	t_queue		a;
	t_queue		b;
	t_ext_queue	mini_queue;

	b.arr = (int *)malloc(size * sizeof(int));
	if (b.arr == NULL)
	{
		free(a_arr);
		exit(-1);
	}
	a.arr = a_arr;
	algo_struct_init(&a, &b, size);
	mini_queue.queue = a;
	proceed_push_swap_ascend(&a, &b, mini_queue);
	free(a.arr);
	free(b.arr);
}

void	proceed_push_swap_ascend(t_queue *a, t_queue *b, t_ext_queue q)
{
	int			i;
	int			size;
	t_ext_queue	mq1;
	t_ext_queue	mq2;

	if (ps_prologue_ascend(a, &q))
		return ;
	size = b->size;
	ps_distribute_ascend(a, b, &q);
	ps_restore_position_ascend(a, &q);
	proceed_push_swap_ascend(a, b, q);
	ps_first_miniqueue_ascend(b, &q, &mq1, size);
	proceed_push_swap_descend(a, b, mq1);
	mq2.queue.start = mq1.queue.start;
	ps_second_miniqueue_ascend(b, &q, &mq2);
	proceed_push_swap_descend(a, b, mq2);
	i = 0;
	while (i < mq2.queue.size + mq1.queue.size)
	{
		ps_pa(a, b, NULL);
		i++;
	}
}

void	proceed_push_swap_descend(t_queue *a, t_queue *b, t_ext_queue q)
{
	int			i;
	int			size;
	t_ext_queue	mq1;
	t_ext_queue	mq2;

	if (ps_prologue_descend(b, &q))
		return ;
	size = a->size;
	ps_distribute_descend(a, b, &q);
	ps_restore_position_descend(a, b, &q);
	proceed_push_swap_descend(a, b, q);
	ps_first_miniqueue_descend(a, &q, &mq1, size);
	proceed_push_swap_ascend(a, b, mq1);
	mq2.queue.start = mq1.queue.start;
	ps_second_miniqueue_descend(a, &q, &mq2);
	proceed_push_swap_ascend(a, b, mq2);
	i = 0;
	while (i < mq2.queue.size + mq1.queue.size)
	{
		ps_pb(a, b, NULL);
		i++;
	}
}

void	get_multi_pivot(t_ext_queue *q)
{
	int	*sorted;

	if (q->queue.start >= q->queue.end)
		exit(-2);
	sorted = (int *)malloc(q->queue.size * sizeof(int));
	if (sorted == NULL)
		exit(-1);
	ps_intarrcpy(sorted, &(q->queue.arr[q->queue.start]), q->queue.size);
	quick_sort(sorted, 0, q->queue.size - 1);
	q->lpv = sorted[(q->queue.size - 2) / 3];
	q->rpv = sorted[q->queue.size - (q->queue.size / 3 + 1)];
	q->first = (q->queue.size - 2) / 3 + 1;
	q->middle = q->queue.size - \
		(q->queue.size / 3 + 1) - (q->queue.size - 2) / 3;
	q->end = q->queue.size - q->first - q->middle;
	free(sorted);
}

void	get_single_pivot(t_ext_queue *q)
{
	int	*sorted;

	if (q->queue.start >= q->queue.end)
		exit(-2);
	sorted = (int *)malloc(q->queue.size * sizeof(int));
	if (sorted == NULL)
		exit(-1);
	ps_intarrcpy(sorted, &(q->queue.arr[q->queue.start]), q->queue.size);
	quick_sort(sorted, 0, q->queue.size - 1);
	q->lpv = sorted[q->queue.size / 2 - 1];
	q->rpv = q->lpv;
	q->first = q->queue.size / 2;
	q->middle = 0;
	q->end = q->queue.size - q->first;
	free(sorted);
}
