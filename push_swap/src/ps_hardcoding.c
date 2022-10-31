/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcoding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:04:35 by sgi               #+#    #+#             */
/*   Updated: 2022/10/31 19:06:21 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_three_1(t_queue *a)
{
	if (a->arr[a->start + 1] < a->arr[a->start + 2])
		return ;
	else
	{
		if (a->arr[a->start] < a->arr[a->start + 2])
		{
			ps_sa(a);
			ps_ra(a, true);
		}
		else
			ps_rra(a);
	}
}

static void	ps_three_2(t_queue *a)
{
	if (a->arr[a->start + 1] < a->arr[a->start + 2])
	{
		if (a->arr[a->start] < a->arr[a->start + 2])
			ps_sa(a);
		else
			ps_ra(a, true);
	}
	else
	{
		ps_sa(a);
		ps_rra(a);
	}
}

void	proceed_push_swap_three(t_queue *a)
{
	if (a->arr[a->start] < a->arr[a->start + 1])
		ps_three_1(a);
	else
		ps_three_2(a);
}

void	proceed_push_swap_five(t_queue *a, t_queue *b, t_ext_queue q)
{
	get_single_pivot(&q);
	ps_distribute_ascend(a, b, &q);
	ps_restore_position_ascend(a, &q);
	proceed_push_swap_three(a);
	q.queue = *b;
	ps_prologue_descend(b, &q);
	ps_pa(a, b, &q);
	ps_pa(a, b, &q);
}
