/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:19:09 by sgi               #+#    #+#             */
/*   Updated: 2022/05/29 11:56:39 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	char		*ret;
	int			bytes;

	
	bytes = read(fd, buf, BUFFER_SIZE);
}

