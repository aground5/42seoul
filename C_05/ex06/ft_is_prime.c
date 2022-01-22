/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:30:17 by sgi               #+#    #+#             */
/*   Updated: 2022/01/20 10:43:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_approx_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb < 2)
		return (0);
	i = 2;
	sqrt = ft_approx_sqrt(nb);
	while (i < sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_approx_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt < 46341)
	{
		if (sqrt * sqrt > nb)
			return (sqrt);
		sqrt++;
	}
	return (sqrt);
}
