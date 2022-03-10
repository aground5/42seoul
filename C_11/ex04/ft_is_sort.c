/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:54:04 by sgi               #+#    #+#             */
/*   Updated: 2022/01/24 21:54:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	mode;

	i = 1;
	mode = 0;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
		{
			if (mode == 0)
				mode = -1;
			else if (mode == 1)
				return (0);
		}
		else if (f(tab[i - 1], tab[i]) < 0)
		{
			if (mode == 0)
				mode = 1;
			else if (mode == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
