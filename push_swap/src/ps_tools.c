/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:30:43 by sgi               #+#    #+#             */
/*   Updated: 2022/10/26 15:14:23 by sgi              ###   ########.fr       */
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != 0)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
}
