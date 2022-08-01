/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:03:14 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 18:20:23 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include "libft.h"

int	g_receivable;

static void	mark_receivable(int sig)
{
	if (sig == SIGUSR1)
	{
		g_receivable = 1;
	}
}

static void	send_str(int pid, char *str)
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
				j++;
				if ((c & 0b10000000) == 0b00000000)
				{
					c = c << 1;
					kill(pid, SIGUSR1);
				}
				else if ((c & 0b10000000) == 0b10000000)
				{
					c = c << 1;
					kill(pid, SIGUSR2);
				}
			}
		}
		i++;
	}
}

static void	send_terminator(int pid)
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

static void custom_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;

	signal(SIGUSR1, &mark_receivable);
	signal(SIGUSR2, &custom_exit);
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
