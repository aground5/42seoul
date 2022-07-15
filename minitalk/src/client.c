/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:03:14 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 14:44:44 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"
#include "ft_printf.h"

int	g_receivable;

void	mark_receivable(int sig)
{
	if (sig == SIGUSR1)
	{
		g_receivable = 1;
		ft_printf("[DEBUG]: unlocked\n");
	}
}

void	send_str(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		j = 0;
		while (j < 8)
		{
			if (g_receivable == 1)
			{
				g_receivable = 0;
				ft_printf("[DEBUG]: locked\n");
				j++;
				if ((c & 0b10000000) == 0b00000000)
				{
					ft_printf("0\n");
					c = c << 1;
					kill(pid, SIGUSR1);
				}
				else if ((c & 0b10000000) == 0b10000000)
				{
					ft_printf("1\n");
					c = c << 1;
					kill(pid, SIGUSR2);
				}
			}
		}
		i++;
	}
}

void	send_terminator(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (g_receivable == 1)
		{
			kill(pid, SIGUSR1);
			g_receivable = 0;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	signal(SIGUSR1, &mark_receivable);
	signal(SIGUSR2, &exit);
	g_receivable = 1;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	send_terminator(pid);
	while (1)
	{
		continue;
	}
	return (0);
}
