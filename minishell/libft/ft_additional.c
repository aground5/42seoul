/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:01:45 by sgi               #+#    #+#             */
/*   Updated: 2022/04/16 22:01:45 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len_s <= start)
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == NULL)
			return (NULL);
		*ret = 0;
		return (ret);
	}
	else if (len > len_s - start)
		ret = (char *)malloc((len_s - start + 1) * sizeof(char));
	else
		ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len_s1);
	ft_memcpy(ret + len_s1, s2, len_s2 + 1);
	return (ret);
}
