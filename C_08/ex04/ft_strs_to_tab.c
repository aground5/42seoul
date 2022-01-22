/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:24:49 by sgi               #+#    #+#             */
/*   Updated: 2022/01/22 10:39:18 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *s, int len)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[len] = '\x00';
	return (ret);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_handle_error(t_stock_str *stock, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(stock[i].copy);
		i++;
	}
	free(stock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		ret[i].size = len;
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i], len);
		if (ret[i].copy == NULL)
		{
			ft_handle_error(ret, i);
			return (NULL);
		}
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
