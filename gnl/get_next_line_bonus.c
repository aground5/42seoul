/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:45:15 by sgi               #+#    #+#             */
/*   Updated: 2022/08/01 21:16:01 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	head;
	t_status		*s;
	char			*ret;
	int				bytes;

	ret = NULL;
	s = status_by_fd(fd, &head);
	while (1)
	{
		s->read_bytes = s->toread_bytes;
		if (s->buf[0] == '\x00' || s->read_bytes == BUFFER_SIZE)
		{
			bytes = gnl_read(fd, s);
			if (bytes == -1)
				return (NULL);
			if (bytes == 0)
				break ;
		}
		if (find_newline(s) == 0)
			ret = ft_strealocat(s->buf, ret, s->read_bytes, s->toread_bytes);
		else
		{
			ret = ft_strealocat(s->buf, ret, s->read_bytes, s->toread_bytes);
			break ;
		}
	}
	return (ret);
}

t_status	*status_by_fd(int fd, t_list *head)
{
	t_list	*index;

	index = head->next;
	while (index != NULL)
	{
		if (index->s->fd == fd)
			return (index->s);
		index = index->next;
	}
	index = head->next;
	head->next = (t_list *)malloc(sizeof(t_list));
	if (head->next == NULL)
		return (NULL);
	head->next->s = (t_status *)malloc(sizeof(t_status));
	if (head->next->s == NULL)
		return (NULL);
	head->next->s->fd = fd;
	head->next->next = index;
	return (head->next->s);
}
