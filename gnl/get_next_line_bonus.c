/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:45:15 by sgi               #+#    #+#             */
/*   Updated: 2022/08/08 11:54:28 by sgi              ###   ########.fr       */
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
	if (s == NULL)
		return (NULL);
	while (1)
	{
		s->read_bytes = s->toread_bytes;
		if (s->buf[0] == '\x00' || s->read_bytes == BUFFER_SIZE)
		{
			bytes = gnl_read(s, &head);
			if (bytes == -1)
				return (NULL);
			if (bytes == 0)
				break ;
		}
		if (process_buffer_to_line(&ret, s, &head))
			break ;
	}
	return (ret);
}

int	process_buffer_to_line(char **ret, t_status *s, t_list *head)
{
	int	code;

	code = find_newline(s);
	if (code == 0)
		*ret = ft_strealocat(s->buf, *ret, s->read_bytes, s->toread_bytes);
	else if (code == 1)
		*ret = ft_strealocat(s->buf, *ret, s->read_bytes, s->toread_bytes);
	else if (code == 2)
	{
		*ret = ft_strealocat(s->buf, *ret, s->read_bytes, s->toread_bytes);
		free_status_list(s->fd, head);
	}
	return (code);
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
	head->next = alloc_status_list(fd);
	if (head->next == NULL)
	{
		head->next = index;
		return (NULL);
	}
	head->next->next = index;
	return (head->next->s);
}

t_list	*alloc_status_list(int fd)
{
	t_list	*ret;
	int		bytes;
	char	buf[BUFFER_SIZE];

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == 0 || bytes == -1)
		return (NULL);
	if ((unsigned int)bytes < BUFFER_SIZE)
		buf[bytes] = EOF;
	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->next = NULL;
	ret->s = (t_status *)malloc(sizeof(t_status));
	if (ret->s == NULL)
		return (NULL);
	ret->s->fd = fd;
	ret->s->read_bytes = 0;
	ret->s->toread_bytes = 0;
	copy_buffer(buf, ret->s->buf);
	return (ret);
}

void	copy_buffer(char *src, char *dst)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		dst[i] = src[i];
		i++;
	}
}
