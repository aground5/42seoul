/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:12 by sgi               #+#    #+#             */
/*   Updated: 2022/01/10 14:39:47 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	char				*ret;

	i = 0;
	ret = dest;
	while (i < n)
	{
		if (*src != '\x00')
		{
			*dest = *src;
			src++;
		}
		else
			*dest = '\x00';
		dest++;
		i++;
	}
	return (ret);
}
