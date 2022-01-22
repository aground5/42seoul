/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:34:20 by sgi               #+#    #+#             */
/*   Updated: 2022/01/09 16:55:24 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*ret;

	ret = dest;
	while (*dest != '\x00')
		dest++;
	i = 0;
	while (i < nb && *src != '\x00')
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\x00';
	return (ret);
}
