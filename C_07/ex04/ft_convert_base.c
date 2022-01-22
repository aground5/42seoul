/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:47:52 by sgi               #+#    #+#             */
/*   Updated: 2022/01/22 14:19:46 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

char	*mov_str_to_real_value(char *str, int *isMinus);
int		ft_atoi_base(char *str, char *base, int baseLen, \
		unsigned char *baseHash);
int		convert_base(int n, unsigned char *converted, int baseLen, int minus);
char	*writenbr_base(char *base, unsigned char *converted, \
	   	int convLen, bool isMinus);
char	*ft_getnbr_base(int nbr, char *base, int baseLen);

void	init_array(unsigned char *str, int size, unsigned char initChar)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = initChar;
		i++;
	}
}

int	validate_base(unsigned char *base, unsigned char *hash)
{
	int		len;

	init_array(hash, 0x100, 0);
	len = 0;
	while (base[len] != '\x00')
	{
		if (base[len] == '-' || base[len] == '+'
			|| (base[len] >= 9 && base[len] <= 13) || base[len] == 32)
			return (0);
		if (hash[(int)base[len]] == 0 && (len == 0 || base[0] != base[len]))
			hash[(int)base[len]] = len;
		else
			return (0);
		len++;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				baseTen;
	int				baseFromLen;
	int				baseToLen;
	unsigned char	baseFromHash[0x100];
	unsigned char	baseToHash[0x100];

	baseFromLen = validate_base((unsigned char *)base_from, baseFromHash);
	baseToLen = validate_base((unsigned char *)base_to, baseToHash);
	if (baseFromLen <= 1 || baseToLen <= 1)
		return (NULL);
	baseTen = ft_atoi_base(nbr, base_from, baseFromLen, baseFromHash);
	return (ft_getnbr_base(baseTen, base_to, baseToLen));
}
