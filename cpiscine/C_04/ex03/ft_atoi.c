/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:35:13 by sgi               #+#    #+#             */
/*   Updated: 2022/01/18 12:35:28 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int				isMinus;
	unsigned int	uResult;
	int				result;

	isMinus = 0;
	uResult = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isMinus ^= 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		uResult *= 10;
		uResult += *(str++) - '0';
	}
	if (isMinus == 1)
		result = uResult * (-1);
	else
		result = uResult;
	return (result);
}
