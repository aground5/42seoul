/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:00:27 by sgi               #+#    #+#             */
/*   Updated: 2022/04/16 22:00:27 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
