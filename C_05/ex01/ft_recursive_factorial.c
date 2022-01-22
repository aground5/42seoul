/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:04 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 20:40:13 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb <= 0)
		return (0);
	result = 1;
	if (nb == 1)
		return (result);
	if (nb >= 2)
	{
		result = ft_recursive_factorial(nb - 1);
		result *= nb;
	}
	return (result);
}
