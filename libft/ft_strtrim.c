/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:40:12 by sgi               #+#    #+#             */
/*   Updated: 2022/04/16 17:14:33 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_charinset(const char c, char const *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char    *ft_emptystring()
{
    char    *ret;

    ret = (char *)malloc(sizeof(char));
    if (ret == NULL)
        return (NULL);
    *ret = 0;
    return (ret);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *ret;
    size_t  i;
    size_t  start;
    size_t  len_s1;

    len_s1 = ft_strlen(s1);
    i = 0;
    while (i < len_s1)
    {
        if (ft_charinset(s1[i], set) == 0)
            break ;
        i++;
    }
    if (i == len_s1)
        return (ft_emptystring());
    start = i;
    i = len_s1 - 1;
    while (i >= start)
    {
		if (ft_charinset(s1[i], set) == 0)
            break ;
        i--;
    }
	ret = (char *)malloc((i - start + 2) * sizeof(char));
    if (ret == NULL)
        return (NULL);
    ft_strlcpy(ret, s1 + start, i - start + 2);
    return (ret);
}
