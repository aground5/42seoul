/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:30:43 by sgi               #+#    #+#             */
/*   Updated: 2022/08/28 13:38:43 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_atoi_strictform_overflow(int n, char *s)
{
	int	i;
	int	len;
	int	num_part;

	len = ft_strlen(s);
	i = len - 1;
	num_part = 0;
	if (n < 0)
	{
		num_part = 1;
		if (s[0] != '-')
			return (true);
	}
	while (i >= num_part)
	{
		if (ft_abs(n % 10) != s[i] - '0')
			return (true);
		n /= 10;
		i--;
	}
	return (false);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	**ps_realloc(char **src, int size)
{
	char	**ret;
	
	ret = (char **)malloc(size * sizeof(char *));
	if (ret == NULL)
		exit(-1);
	ft_memcpy(ret, src, (size - 1) * sizeof(char *));
	free(src);
	return (ret);
}

char	**ps_log_move(char *op)
{
	static char	**log;
	static int	size_log;

	if (op == NULL)
	{
		log = ps_realloc(log, size_log + 1);
		log[size_log] = NULL;
		return (log);
	}
	if (log == NULL)
	{
		log = (char **)malloc(sizeof(char *));
		if (log == NULL)
			exit(-1);
		size_log++;
	}
	else
	{
		log = ps_realloc(log, size_log + 1);
		size_log++;
	}
	log[size_log - 1] = op;
	return (log);
}
