/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:24 by sgi               #+#    #+#             */
/*   Updated: 2022/09/21 16:52:39 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf.h"
#include "libft.h"

char	*g_str;

static void	display_pid(void)
{
	ft_printf("%d\n", getpid());
}

static void	init(void)
{
	g_str = (char *)malloc(1);
	if (g_str == NULL)
		exit(1);
}

int	main(void)
{
	struct sigaction	act;

	init();
	act.sa_sigaction = &transmit;
	act.sa_flags = SA_SIGINFO;
	display_pid();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		continue ;
	}
	return (0);
}
