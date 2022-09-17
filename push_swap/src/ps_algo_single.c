/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:40 by sgi               #+#    #+#             */
/*   Updated: 2022/09/17 13:36:55 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_print_queue(t_queue *queue)
{
	for (int i = queue->start; i <= queue->end; i++)
	{
		ft_printf("%d\n", queue->arr[i]);
	}
	ft_printf("size: %d\n", queue->size);
	ft_printf("start: %d\n", queue->start);
	ft_printf("end: %d\n", queue->end);
}
void	single_log_queue(t_queue *a, t_queue *b, t_queue *q)
{
	return ;
	ft_printf("[a]\n");
	print_queue(a);
	ft_printf("[b]\n");
	print_queue(b);
	ft_printf("[q]\n");
	print_queue(q);
	ft_printf("--------------------\n");
}

void	single_algo_init(int *a_arr, int size)
{
	t_queue a;
	t_queue	b;
	t_queue mini_queue;

	b.arr = (int *)malloc(size * sizeof(int));
	if (b.arr == NULL)
	{
		free(a_arr);
		exit(-1);
	}
	a.arr = a_arr;
	algo_struct_init(&a, &b, size);
	mini_queue = a;
	proceed_push_swap_ascend(&a, &b, &mini_queue);
	log_queue(&a, &b, &mini_queue);
	free(a.arr);
	free(b.arr);
}

void	single_proceed_push_swap_ascend(t_queue *a, t_queue *b, t_queue *q)
{
	int		mid;
	int		i;
	int		j;
	int		size;
	t_queue	mini_queue;

	log_queue(a, b, q);
	if (q->size <= 1 || is_sorted(true, q))
		return ;
	if (q->size == 2)
	{
		if (q->arr[q->start] > q->arr[q->start + 1])
		{
			ps_sa(q);
			log_queue(a, b, q);
		}
		return ;
	}
	mini_queue.arr = b->arr;
	mini_queue.end = b->start - 1;
	size = q->size;
	mid = get_median(q->arr, q->start, q->end);
	i = q->start;
	j = 0;
	while (i <= q->end && (size + 1) / 2 < q->size)
	{
		if (q->arr[q->start] < mid)
			ps_pb(a, b, q);
		else
		{
			ps_ra(a);
			j++;
		}
		i++;
	}
	i = 0;
	if (!(a->start == q->start && a->end == q->end))
	{
		while (i < j)
		{
			ps_rra(a);
			i++;
		}
	}
	log_queue(a, b, q);
	mini_queue.start = b->start;
	mini_queue.size = mini_queue.end - mini_queue.start + 1;
	proceed_push_swap_ascend(a, b, q);
	proceed_push_swap_descend(a, b, &mini_queue);
	mid = mini_queue.size;
	i = 0;
	while (i < mid)
	{
		ps_pa(a, b, &mini_queue);
		q->start--;
		q->size++;
		i++;
	}
	log_queue(a, b, q);
}

void	single_proceed_push_swap_descend(t_queue *a, t_queue *b, t_queue *q)
{
	int		mid;
	int		i;
	int		j;
	int		size;
	t_queue	mini_queue;

	log_queue(a, b, q);
	if (q->size <= 1 || is_sorted(false, q))
		return ;
	if (q->size == 2)
	{
		if (q->arr[q->start] < q->arr[q->start + 1])
		{
			ps_sb(q);
			log_queue(a, b, q);
		}
		return ;
	}
	mini_queue.arr = a->arr;
	mini_queue.end = a->start - 1;
	size = q->size;
	mid = get_median(q->arr, q->start, q->end);
	i = q->start;
	j = 0;
	while (i <= q->end && (size + 1) / 2 < q->size)
	{
		if (q->arr[q->start] > mid)
			ps_pa(a, b, q);
		else
		{
			ps_rb(b);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		ps_rrb(b);
		i++;
	}
	log_queue(a, b, q);
	mini_queue.start = a->start;
	mini_queue.size = mini_queue.end - mini_queue.start + 1;
	proceed_push_swap_descend(a, b, q);
	proceed_push_swap_ascend(a, b, &mini_queue);
	mid = mini_queue.size;
	i = 0;
	while (i < mid)
	{
		ps_pb(a, b, &mini_queue);
		q->start--;
		q->size++;
		i++;
	}
	log_queue(a, b, q);
}

int	single_get_median(int *array, int start, int end)
{
	int	*sorted;
	int	len_sorted;
	int	ret;

	if (start >= end)
		exit(-2);
	len_sorted = end - start + 1;
	sorted = (int *)malloc(len_sorted * sizeof(int));
	if (sorted == NULL)
		exit(-1);
	ps_intarrcpy(sorted, &array[start], len_sorted);
	quick_sort(sorted, 0, len_sorted - 1);
	ret = sorted[len_sorted / 2];
	free(sorted);
	// ft_printf("len: %d   |    mid: %d\n", len_sorted, ret);
	return (ret);
}