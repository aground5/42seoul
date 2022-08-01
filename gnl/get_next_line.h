/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:24:47 by sgi               #+#    #+#             */
/*   Updated: 2022/08/01 20:34:14 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_status
{
	char	buf[BUFFER_SIZE];
	int		read_bytes;
	int		toread_bytes;
}			t_status;

int		find_newline(t_status *s);
int		ft_strlen(char *s);
char	*ft_strealocat(char *src, char *dst, int start, int end);
int		gnl_read(int fd, t_status *s);
char	*get_next_line(int fd);

#endif
