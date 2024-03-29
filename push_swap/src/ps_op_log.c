/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:40 by sgi               #+#    #+#             */
/*   Updated: 2022/10/31 20:22:43 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ps_realloc(char **src, int size)
{
	char	**ret;

	ret = (char **)malloc(size * sizeof(char *));
	if (ret == NULL)
		exit(-1);
	ft_memcpy(ret, src, (size - 1) * sizeof(char *));
	if (src != NULL)
		free(src);
	return (ret);
}

char	**ps_log_move(char *op)
{
	static char	**log;
	static int	size_log;

	if (op == NULL)
	{
		log = ps_realloc(log, size_log + 1);
		log[size_log] = NULL;
		return (log);
	}
	if (log == NULL)
	{
		log = (char **)malloc(sizeof(char *));
		if (log == NULL)
			exit(-1);
		size_log++;
	}
	else
	{
		log = ps_realloc(log, size_log + 1);
		size_log++;
	}
	log[size_log - 1] = op;
	return (log);
}

static void	optimize_push_tossing(char **log, t_list *head)
{
	int		i;

	i = 1;
	while (log[i])
	{
		if ((ft_strncmp(head->next->content, "pa", 2) == 0 && \
			ft_strncmp("pb", log[i], 2) == 0) || \
		(ft_strncmp(head->next->content, "pb", 2) == 0 && \
			ft_strncmp("pa", log[i], 2) == 0))
			ps_pop_list(head);
		else
			ps_push_list(head, log[i]);
		i++;
	}
}

static char	**ps_flatten_list_to_array(t_list *head, int endIdx)
{
	char	**log;
	t_list	*tmp;

	log = (char **)ft_calloc(endIdx + 1, sizeof(char *));
	endIdx--;
	while (head->next != NULL)
	{
		tmp = head->next;
		log[endIdx] = tmp->content;
		head->next = tmp->next;
		free(tmp);
		endIdx--;
	}
	return (log);
}

char	**ps_optimize_move(void)
{
	char	**log;
	t_list	head;
	t_list	*tmp;
	int		i;

	log = ps_log_move(NULL);
	if (log[0] == NULL)
		return (log);
	head.next = (t_list *)ft_calloc(1, sizeof(t_list));
	if (head.next == NULL)
		exit(-1);
	head.next->content = log[0];
	optimize_push_tossing(log, &head);
	tmp = &head;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	free(log);
	log = ps_flatten_list_to_array(&head, i);
	return (log);
}
