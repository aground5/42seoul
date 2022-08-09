/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:46:44 by sgi               #+#    #+#             */
/*   Updated: 2022/08/08 11:29:40 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(t_status *s)
{
	int	i;

	i = s->read_bytes;
	while (i < BUFFER_SIZE)
	{
		if (s->buf[i] == '\n')
		{
			s->toread_bytes = i + 1;
			return (1);
		}
		else if (s->buf[i] == EOF)
		{
			s->toread_bytes = i;
			return (2);
		}
		i++;
	}
	s->toread_bytes = i;
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strealocat(char *src, char *dst, int start, int end)
{
	char	*ret;
	int		lendst;
	int		i;

	if (start == end)
		return (NULL);
	lendst = ft_strlen(dst);
	ret = (char *)malloc(sizeof(char) * (end - start + 1 + lendst));
	i = 0;
	while (i < lendst)
	{
		ret[i] = dst[i];
		i++;
	}
	i = start;
	while (i < end)
	{
		ret[i + lendst - start] = src[i];
		i++;
	}
	ret[i + lendst - start] = '\x00';
	if (dst != NULL)
		free(dst);
	return (ret);
}

int	gnl_read(t_status *s, t_list *head)
{
	int	bytes;

	bytes = read(s->fd, s->buf, BUFFER_SIZE);
	s->read_bytes = 0;
	if (bytes == -1 || bytes == 0)
		free_status_list(s->fd, head);
	else if ((unsigned int)bytes < BUFFER_SIZE)
		s->buf[bytes] = EOF;
	return (bytes);
}

void	free_status_list(int fd, t_list *head)
{
	t_list	*prev;
	t_list	*index;

	prev = head;
	index = head->next;
	while (index != NULL)
	{
		if (index->s->fd == fd)
			break ;
		prev = index;
		index = index->next;
	}
	prev->next = index->next;
	free(index->s);
	free(index);
}
