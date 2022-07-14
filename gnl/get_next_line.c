/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:19:09 by sgi               #+#    #+#             */
/*   Updated: 2022/07/08 15:59:54 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_status	s;
	char			*ret;
	int				bytes;

	ret = NULL;
	while (1)
	{
		s.read_bytes = s.toread_bytes;
		if (s.buf[0] == '\x00' || s.read_bytes == BUFFER_SIZE)
		{
			bytes = gnl_read(fd, &s);
			if (bytes == -1)
				return (NULL);
			if (bytes == 0)
				break ;
		}
		if (find_newline(&s) == 0)
			ret = ft_strealocat(s.buf, ret, s.read_bytes, s.toread_bytes);
		else
		{
			ret = ft_strealocat(s.buf, ret, s.read_bytes, s.toread_bytes);
			break ;
		}
	}
	return (ret);
}
