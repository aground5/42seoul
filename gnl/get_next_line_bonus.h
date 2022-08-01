/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:46:18 by sgi               #+#    #+#             */
/*   Updated: 2022/08/01 21:15:32 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_status
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		read_bytes;
	int		toread_bytes;
}			t_status;

typedef struct s_list
{
	t_status		*s;
	struct s_list	*next;
}					t_list;

t_status	*status_by_fd(int fd, t_list *head);
int			find_newline(t_status *s);
int			ft_strlen(char *s);
char		*ft_strealocat(char *src, char *dst, int start, int end);
int			gnl_read(int fd, t_status *s);
char		*get_next_line(int fd);

#endif
