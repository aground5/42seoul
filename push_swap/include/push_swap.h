/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:05:40 by sgi               #+#    #+#             */
/*   Updated: 2022/08/28 13:23:41 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct	s_queue
{
	int			*arr;
	int			size;
	int			start;
	int			end;
}				t_queue;

int		*validate_arguements(int argn, char **argv);
int		push_swap_atoi(char *s);
bool	is_duplicated(int *arr, int size);

bool	ft_atoi_strictform_overflow(int n, char *s);
int 	ft_abs(int n);
char	**ps_log_move(char *op);

void	ps_pa(t_queue *a, t_queue *b, t_queue *q);
void	ps_pb(t_queue *a, t_queue *b, t_queue *q);
void	ps_sa(t_queue *a);
void	ps_sb(t_queue *b);
void	ps_ra(t_queue *a);
void	ps_rb(t_queue *b);
void	ps_rra(t_queue *a);
void	ps_rrb(t_queue *b);

void	quick_sort(int *arr, int low, int high);

void	algo_init(int *a_arr, int size);
void	algo_atob(t_queue *a, t_queue *b, t_queue *q);
void	algo_btoa(t_queue *a, t_queue *b, t_queue *q);
int		get_median(int *array, int start, int end);
void	algo_struct_init(t_queue *a, t_queue *b, int size);

#endif
