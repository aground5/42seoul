/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:43:52 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 19:39:49 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pop_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next->next;
	free(lst->next);
	lst->next = tmp;
}

void	ps_push_list(t_list *lst, void *data)
{
	t_list	*tmp;

	tmp = lst->next;
	lst->next = (t_list *)ft_calloc(1, sizeof(t_list));
	if (lst->next == NULL)
		exit(-1);
	lst->next->next = tmp;
	lst->next->content = data;
}
