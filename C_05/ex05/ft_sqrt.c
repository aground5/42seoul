/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:48:27 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 16:44:25 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;
	int	overflow;

	root = nb;
	overflow = root * root;
	while(overflow < root)
	{
		root /= 2;
		overflow = root * root;
	}
	while(root * root > nb)
	{
		root /= 2;
	}
	return root;
}

#include <stdio.h>
int main(void)
{
	printf("%d", ft_sqrt(1000000000));

}
