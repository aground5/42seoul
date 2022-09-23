/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:09:10 by sgi               #+#    #+#             */
/*   Updated: 2022/09/23 22:37:44 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf.h"

extern char	*g_str;

static void	add_unset(int idx)
{
	g_str[idx] = g_str[idx] << 1;
	g_str[idx] = g_str[idx] & 0b11111110;
}

static void	add_set(int idx)
{
	g_str[idx] = g_str[idx] << 1;
	g_str[idx] = g_str[idx] | 0b00000001;
}

static void	*ft_realloc(char *src, int src_len, int ret_len)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(ret_len);
	if (ret == NULL)
		exit(1);
	while (i < src_len && i < ret_len)
	{
		((char *)ret)[i] = src[i];
		i++;
	}
	free(src);
	return (ret);
}

static void	finit(unsigned int *idx, pid_t *si_pid)
{
	*idx = 0;
	ft_printf("%s\n", g_str);
	kill(*si_pid, SIGUSR2);
	*si_pid = 0;
	free(g_str);
	g_str = (char *)malloc(1);
	if (g_str == NULL)
		exit(1);
}

void	transmit(int sig, siginfo_t *info, void *uap)
{
	static unsigned int	bit;
	static unsigned int	idx;
	static pid_t		si_pid;

	if (si_pid == 0 || (info->si_pid != 0 && info->si_pid != si_pid))
		si_pid = info->si_pid;
	(void)uap;
	if (sig == SIGUSR1)
		add_unset(idx);
	else if (sig == SIGUSR2)
		add_set(idx);
	bit++;
	if (bit >= 8)
	{
		bit = 0;
		idx++;
		if (g_str[idx - 1] == '\x00')
		{
			finit(&idx, &si_pid);
			return ;
		}
		g_str = (char *)ft_realloc(g_str, idx, idx + 1);
	}
	kill(si_pid, SIGUSR1);
}
