/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:55:21 by sgi               #+#    #+#             */
/*   Updated: 2022/01/17 18:11:21 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *string)
{
	unsigned int	len;

	len = 0;
	while (*string != '\x00')
	{
		len++;
		string++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest > size || size == 0)
		return (size + len_src);
	i = len_dest;
	dest += len_dest;
	while (i < size - 1 && *src != '\x00')
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\x00';
	return (len_dest + len_src);
}
