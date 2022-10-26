/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:05:40 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 16:09:16 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_queue
{
	int	*arr;
	int	size;
	int	start;
	int	end;
}		t_queue;

typedef struct s_ext_queue
{
	t_queue	queue;
	int		lpv;
	int		rpv;
	int		first;
	int		middle;
	int		end;
}			t_ext_queue;

int		*validate_arguements(int argn, char **argv);
int		push_swap_atoi(char *s);
bool	is_duplicated(int *arr, int size);
char	**parse_onearg(char *onearg, int *size);

bool	ft_atoi_strictform_overflow(int n, char *s);
int		ft_abs(int n);
void	free_split(char **split);

char	**ps_log_move(char *op);
char	**ps_optimize_move(void);

void	ps_pop_list(t_list *lst);
void	ps_push_list(t_list *lst, void *data);

void	ps_pa(t_queue *a, t_queue *b, t_ext_queue *q);
void	ps_pb(t_queue *a, t_queue *b, t_ext_queue *q);
void	ps_sa(t_queue *a);
void	ps_sb(t_queue *b);
int		ps_ra(t_queue *a, bool initialize);
int		ps_rb(t_queue *b, bool initialize);
void	ps_rra(t_queue *a);
void	ps_rrb(t_queue *b);

void	quick_sort(int *arr, int low, int high);

void	algo_init(int *a_arr, int size);
void	proceed_push_swap_ascend(t_queue *a, t_queue *b, t_ext_queue q);
void	proceed_push_swap_descend(t_queue *a, t_queue *b, t_ext_queue q);
void	get_multi_pivot(t_ext_queue *q);
void	get_single_pivot(t_ext_queue *q);

void	algo_struct_init(t_queue *a, t_queue *b, int size);
void	ps_intarrcpy(int *dst, const int *src, int n);
bool	is_sorted(bool ascending, t_ext_queue *q);

bool	ps_prologue_ascend(t_queue *a, t_ext_queue *q);
void	ps_distribute_ascend(t_queue *a, t_queue *b, t_ext_queue *q);
void	ps_restore_position_ascend(t_queue *a, t_ext_queue *q);
void	ps_first_miniqueue_ascend(t_queue *b, t_ext_queue *q,
			t_ext_queue *mq, int size);
void	ps_second_miniqueue_ascend(t_queue *b, t_ext_queue *q,
			t_ext_queue *mq);

bool	ps_prologue_descend(t_queue *b, t_ext_queue *q);
void	ps_distribute_descend(t_queue *a, t_queue *b, t_ext_queue *q);
void	ps_restore_position_descend(t_queue *a, t_queue *b, t_ext_queue *q);
void	ps_first_miniqueue_descend(t_queue *b, t_ext_queue *q,
			t_ext_queue *mq, int size);
void	ps_second_miniqueue_descend(t_queue *b, t_ext_queue *q,
			t_ext_queue *mq);

#endif
