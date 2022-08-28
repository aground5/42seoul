/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:25:40 by sgi               #+#    #+#             */
/*   Updated: 2022/08/28 14:42:53 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	log_queue(t_queue *a, t_queue *b, t_queue *q)
{
	ft_printf("[a]\n");
	print_queue(a);
	ft_printf("[b]\n");
	print_queue(b);
	ft_printf("[q]\n");
	print_queue(q);
	ft_printf("--------------------\n");
}

void	algo_init(int *a_arr, int size)
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
	log_queue(&a, &b, &mini_queue);
	algo_atob(&a, &b, &mini_queue);
	log_queue(&a, &b, &mini_queue);
	free(a.arr);
	free(b.arr);
}

void	algo_atob(t_queue *a, t_queue *b, t_queue *q)
{
	int		mid;
	int		i;
	t_queue	mini_queue;
	
	mini_queue.arr = b->arr;
	mini_queue.end = b->start - 1;
	if (q->size == 2 && q->arr[q->start] > q->arr[q->start + 1])	//q->end - q->start + 1 == q->size ?
		ps_sa(q);
	if (q->size <= 2)
		return ;
	mid = get_median(q->arr, q->start, q->end);
	i = q->start;
	while (i <= q->end)
	{
		if (q->arr[q->start] <= mid)
			ps_pb(a, b, q);
		else
			ps_ra(q);
		i++;
	}
	mini_queue.start = b->start;
	mini_queue.size = mini_queue.end - mini_queue.start + 1;
	log_queue(a, b, q);
	algo_atob(a, b, q);
	log_queue(a, b, &mini_queue);
	algo_btoa(a, b, &mini_queue);
}

void	algo_btoa(t_queue *a, t_queue *b, t_queue *q)
{
	int		mid;
	int		i;
	t_queue	mini_queue;
	
	mini_queue.arr = a->arr;
	mini_queue.end = a->start - 1;
	if (q->size <= 2)
	{
		if (q->size == 2 && q->arr[q->start] < q->arr[q->start + 1])	//q->end - q->start + 1 == q->size ?
			ps_sb(q);
		i = 0;
		while (i < q->size)
		{
			ps_pa(a, b, q);
			i++;
		}
		return ;
	}
	mid = get_median(q->arr, q->start, q->end);
	i = q->start;
	while (i <= q->end)
	{
		if (q->arr[q->start] > mid)
			ps_pa(a, b, q);
		else
			ps_rb(q);
		i++;
	}
	mini_queue.start = a->start;
	mini_queue.size = mini_queue.end - mini_queue.start + 1;
	log_queue(a, b, q);
	algo_btoa(a, b, q);
	log_queue(a, b, &mini_queue);
	algo_atob(a, b, &mini_queue);
}

int	get_median(int *array, int start, int end)
{
	int	*sorted;
	int	len_sorted;
	int	ret;

	len_sorted = end - start + 1;
	sorted = (int *)malloc(len_sorted);
	if (sorted == NULL)
		exit(-1);
	ft_memcpy(sorted, &array[start], (len_sorted) * sizeof(int));
	quick_sort(sorted, 0, len_sorted);
	ret = sorted[len_sorted / 2];
	free(sorted);
	return (ret);
}

void	algo_struct_init(t_queue *a, t_queue *b, int size)
{
	a->start = 0;
	a->end = size - 1;
	a->size = size;
	b->start = size;
	b->end = size - 1;
	b->size = 0;
}
