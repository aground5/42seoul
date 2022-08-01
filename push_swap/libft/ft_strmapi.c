/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:21:13 by sgi               #+#    #+#             */
/*   Updated: 2022/04/16 21:21:13 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\x00';
	return (ret);
}
