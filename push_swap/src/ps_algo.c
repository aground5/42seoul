/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:40 by sgi               #+#    #+#             */
/*   Updated: 2022/09/24 17:24:22 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_single_param = 6;

void	print_queue(t_queue *queue)
{
	for (int i = queue->start; i <= queue->end; i++)
	{
		ft_printf("%d\n", queue->arr[i]);
	}
	ft_printf("size: %d\n", queue->size);
	ft_printf("start: %d\n", queue->start);
	ft_printf("end: %d\n", queue->end);
}
void	log_queue(t_queue *a, t_queue *b, t_ext_queue *q)
{
	return ;
	ft_printf("[a]\n");
	print_queue(a);
	ft_printf("[b]\n");
	print_queue(b);
	ft_printf("[q]\n");
	print_queue(&(q->queue));
	ft_printf("lpv: %d\n", q->lpv);
	ft_printf("rpv: %d\n", q->rpv);
	ft_printf("first: %d\n", q->first);
	ft_printf("middle: %d\n", q->middle);
	ft_printf("end: %d\n", q->end);
	ft_printf("--------------------\n");
}

void	algo_init(int *a_arr, int size)
{
	t_queue a;
	t_queue	b;
	t_ext_queue mini_queue;

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
	log_queue(&a, &b, &mini_queue);
	free(a.arr);
	free(b.arr);
}

void	proceed_push_swap_ascend(t_queue *a, t_queue *b, t_ext_queue q)
{
	int			i;
	int			size;
	t_ext_queue	mq1;
	t_ext_queue	mq2;

	log_queue(a, b, &q);
	if (q.queue.size <= 1 || is_sorted(true, &q))
		return ;
	if (q.queue.size == 2)
	{
		if (q.queue.arr[q.queue.start] > q.queue.arr[q.queue.start + 1])
		{
			ps_sa(a);
			log_queue(a, b, &q);
		}
		return ;
	}
	if (q.queue.size == 3)
	{
		if (q.queue.arr[q.queue.start] < q.queue.arr[q.queue.start + 1])
		{
			if (q.queue.arr[q.queue.start + 1] < q.queue.arr[q.queue.start + 2])
				return ;
			else
			{
				if (q.queue.arr[q.queue.start] < q.queue.arr[q.queue.start + 2])
				{
					ps_ra(a, true);
					ps_sa(a);
					ps_rra(a);
				}
				else
				{
					ps_ra(a, true);
					ps_sa(a);
					ps_rra(a);
					ps_sa(a);
				}
			}
		}
		else
		{
			if (q.queue.arr[q.queue.start + 1] < q.queue.arr[q.queue.start + 2])
			{
				if (q.queue.arr[q.queue.start] < q.queue.arr[q.queue.start + 2])
					ps_sa(a);
				else
				{
					ps_sa(a);
					ps_ra(a, true);
					ps_sa(a);
					ps_rra(a);
				}
			}
			else
			{
				ps_sa(a);
				ps_ra(a, true);
				ps_sa(a);
				ps_rra(a);
				ps_sa(a);
			}
		}
		return ;
	}
	size = b->size;
	if (q.queue.size <= g_single_param)
		get_single_pivot(&q);
	else
		get_pivot(&q);
	i = q.queue.start;
	while (i <= q.queue.end && q.end < q.queue.size)
	{
		if (q.queue.arr[q.queue.start] <= q.rpv)
		{
			ps_pb(a, b, &q);
			if (b->arr[b->start] > q.lpv)
				ps_rb(b, true);
		}
		else
			ps_ra(a, false);
		i++;
	}
	i = 0;
	if (!(a->start == q.queue.start && a->end == q.queue.end))
	{
		while (i < ps_ra(NULL, false))
		{
			ps_rra(a);
			i++;
		}
	}
	ps_ra(NULL, true);
	proceed_push_swap_ascend(a, b, q);
	log_queue(a, b, &q);
	mq1.queue.arr = b->arr;
	mq1.queue.size = q.first;
	mq1.queue.start = b->end - size - q.first - q.middle + 1;
	mq1.queue.end = mq1.queue.start + mq1.queue.size - 1;
	proceed_push_swap_descend(a, b, mq1);
	i = 0;
	while (i < q.middle)
	{
		ps_rrb(b);
		i++;
	}
	mq2.queue.arr = b->arr;
	mq2.queue.size = q.middle;
	mq2.queue.start = mq1.queue.start;
	mq2.queue.end = mq2.queue.start + mq2.queue.size - 1;
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
	t_ext_queue mq2;

	log_queue(a, b, &q);
	if (q.queue.size <= 1 || is_sorted(false, &q))
		return ;
	if (q.queue.size == 2)
	{
		if (q.queue.arr[q.queue.start] < q.queue.arr[q.queue.start + 1])
		{
			ps_sb(b);
			log_queue(a, b, &q);
		}
		return ;
	}
	size = a->size;
	if (q.queue.size <= g_single_param)
		get_single_pivot(&q);
	else
		get_pivot(&q);
	i = q.queue.start;
	while (i <= q.queue.end && q.first < q.queue.size)
	{
		if (q.queue.arr[q.queue.start] > q.lpv)
		{
			ps_pa(a, b, &q);
			if (a->arr[a->start] <= q.rpv)
				ps_ra(a, true);
		}
		else
			ps_rb(b, false);
		i++;
	}
	i = 0;
	if (!(a->start == q.queue.start && a->end == q.queue.end))
	{
		while (i < ps_rb(NULL, false))
		{
			ps_rrb(b);
			i++;
		}
	}
	ps_rb(NULL, true);
	proceed_push_swap_descend(a, b, q);
	mq1.queue.arr = a->arr;
	mq1.queue.size = q.end;
	mq1.queue.start = a->end - size - q.end - q.middle + 1;
	mq1.queue.end = mq1.queue.start + mq1.queue.size - 1;
	proceed_push_swap_ascend(a, b, mq1);
	i = 0;
	while (i < q.middle)
	{
		ps_rra(a);
		i++;
	}
	mq2.queue.arr = a->arr;
	mq2.queue.size = q.middle;
	mq2.queue.start = mq1.queue.start;
	mq2.queue.end = mq2.queue.start + mq2.queue.size - 1;
	proceed_push_swap_ascend(a, b, mq2);
	i = 0;
	while (i < mq2.queue.size + mq1.queue.size)
	{
		ps_pb(a, b, NULL);
		i++;
	}
}

void	get_pivot(t_ext_queue *q)
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
	q->middle = q->queue.size - (q->queue.size / 3 + 1) - (q->queue.size - 2) / 3;
	q->end = q->queue.size - q->first - q->middle;
	free(sorted);
	// ft_printf("len: %d   |    mid: %d\n", len_sorted, ret);
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


