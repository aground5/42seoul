/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:53:52 by sgi               #+#    #+#             */
/*   Updated: 2022/01/06 17:48:11 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	i[3];

	i[0] = '0';
	while (i[0] <= '9')
	{
		i[1] = i[0] + 1;
		while (i[1] <= '9')
		{
			i[2] = i[1] + 1;
			while (i[2] <= '9')
			{
				write(1, &i[0], 1);
				write(1, &i[1], 1);
				write(1, &i[2], 1);
				if (i[0] != '7' || i[1] != '8' || i[2] != '9')
				{
					write(1, ", ", 2);
				}
				i[2]++;
			}
			i[1]++;
		}
		i[0]++;
	}
}
