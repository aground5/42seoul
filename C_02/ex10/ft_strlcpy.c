/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:12:48 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 21:10:23 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str != '\x00')
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i + 1 < size && *src != '\x00')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\x00';
	return (len);
}
