/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:50:16 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 11:50:19 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "do_op.h"

static int	g_errno;

void	ft_printmsg(int	result)
{
	if (g_errno == 0)
	{
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	else if (g_errno == DIVERR)
		write(1, "Stop : division by zero\n", 24);
	else if (g_errno == MODERR)
		write(1, "Stop : modulo by zero\n", 22);
	else if (g_errno == OPINVLD)
		write(1, "0\n", 2);
}

int	div(int a, int b)
{
	if (b == 0)
		g_errno = DIVERR;
	else
		return (a / b);
	return (0);
}

int	mod(int a, int b)
{
	if (b == 0)
		g_errno = MODERR;
	else
		return (a % b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	result;

	if (argc != 4)
		return (1);
	result = 0;
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (ft_strcmp(argv[2], "+") == 0)
		result = a + b;
	else if (ft_strcmp(argv[2], "-") == 0)
		result = a - b;
	else if (ft_strcmp(argv[2], "/") == 0)
		result = div(a, b);
	else if (ft_strcmp(argv[2], "*") == 0)
		result = a * b;
	else if (ft_strcmp(argv[2], "%") == 0)
		result = mod(a, b);
	else
		g_errno = OPINVLD;
	ft_printmsg(result);
	return (g_errno);
}
