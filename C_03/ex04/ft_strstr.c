/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:58:34 by sgi               #+#    #+#             */
/*   Updated: 2022/01/09 18:52:51 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*haystack;
	char	*needle;

	if (*to_find == '\x00')
		return (str);
	while (*str != '\x00')
	{
		if (*to_find == *str)
		{
			haystack = str;
			needle = to_find;
			while (*needle != '\x00')
			{
				if (*needle != *haystack)
					break ;
				needle++;
				haystack++;
			}
			if (*needle == '\x00')
				return (str);
		}
		str++;
	}
	return (0);
}
