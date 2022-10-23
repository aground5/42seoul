/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:15 by sgi               #+#    #+#             */
/*   Updated: 2022/10/22 15:25:19 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	reduce_2d1d(int *arr, int size)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < size)
	{
		ret += arr[i];
		i++;
	}
	return (ret);
}

void	index_itercount(t_program *prog, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < prog->resol.height)
	{
		j = 0;
		while (j < prog->resol.width)
		{
			arr[prog->itercount[i][j]]++;
			j++;
		}
		i++;
	}
}
