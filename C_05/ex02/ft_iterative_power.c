/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:56:31 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 21:36:27 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	if (power < 0)
		return (0);
	result = 1;
	i = 0;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
