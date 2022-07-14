/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:20:58 by sgi               #+#    #+#             */
/*   Updated: 2022/07/13 12:50:07 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

static void	ft_putnbr_fd_process(int n, int fd, int isminus)
{
	if (n != 0)
		ft_putnbr_fd_process(n / 10, fd, isminus);
	else
		return ;
	ft_putchar_fd((n % 10) * isminus + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_process(n, fd, -1);
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putnbr_fd_process(n, fd, 1);
}
