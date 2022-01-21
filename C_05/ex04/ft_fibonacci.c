/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:19:11 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 16:38:24 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	m0;
	int	m1;
	int	m2;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	if (index == 3)
		return (2);
	m1 = ft_fibonacci(index - 1);
	if (m1 == -2)
		return (-2);
	m2 = ft_fibonacci(index - 2);
	if (m2 == -2)
		return (-2);
	m0 = m1 + m2
	if (m0 > m1)
		return m0;
	return (-2);
}
