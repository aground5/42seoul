/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:01:46 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 23:01:47 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"

void	free_list(t_list **list)
{
	t_list	*curList;

	while ((*list)->next != NULL)
	{
		curList = *list;
		*list = (*list)->next;
		free(curList->square);
		free(curList);
	}
	free((*list)->square);
	free(*list);
	free(list);
}

t_square	*make_square(int row, int col)
{
	t_square	*ret;

	ret = (t_square *)malloc(sizeof(t_square));
	if (ret == NULL)
		return (NULL);
	ret->row = row;
	ret->col = col;
	ret->dia = 0;
	ret->row_collide = 0;
	ret->col_collide = 0;
	return (ret);
}

int	append_list(t_square *square, t_list **list)
{
	t_list	*newList;

	newList = (t_list *)malloc(sizeof(t_list));
	if (newList == NULL)
	{
		free_list(list);
		return (MALOFL);
	}
	newList->square = square;
	newList->next = *list;
	*list = newList;
	return (NORMEX);
}

t_square	*find_max_square(t_list **list)
{
	t_square	*ret;
	t_list		*curList;

	ret = NULL;
	curList = *list;
	while (curList != NULL)
	{
		if (ret == NULL)
			ret = curList->square;
		else if (ret->dia <= curList->square->dia)
			ret = curList->square;
		curList = curList->next;
	}
	return (ret);
}
