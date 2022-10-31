/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_array_shift.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:26:45 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 16:32:01 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

extern inline void	adjust_maxitercount(t_program *prog, int i, int j);

void	fractol_shift_left(t_program *prog)
{
	int	i;
	int	j;
	int	shamt;

	shamt = prog->resol.width / 10;
	i = 0;
	while (i < prog->resol.width - shamt)
	{
		j = 0;
		while (j < prog->resol.height)
		{
			prog->itercount[j][i] = prog->itercount[j][i + shamt];
			prog->zs[j][i] = prog->zs[j][i + shamt];
			adjust_maxitercount(prog, j, i);
			prog->itercount[j][i + shamt] = 0;
			prog->zs[j][i + shamt].x = 0;
			prog->zs[j][i + shamt].y = 0;
			j++;
		}
		i++;
	}
	prog->coord.zero.x -= shamt;
}

void	fractol_shift_right(t_program *prog)
{
	int	i;
	int	j;
	int	shamt;

	shamt = prog->resol.width / 10;
	i = prog->resol.width - 1;
	while (i >= shamt)
	{
		j = 0;
		while (j < prog->resol.height)
		{
			prog->itercount[j][i] = prog->itercount[j][i - shamt];
			prog->zs[j][i] = prog->zs[j][i - shamt];
			adjust_maxitercount(prog, j, i);
			prog->itercount[j][i - shamt] = 0;
			prog->zs[j][i - shamt].x = 0;
			prog->zs[j][i - shamt].y = 0;
			j++;
		}
		i--;
	}
	prog->coord.zero.x += shamt;
}

void	fractol_shift_down(t_program *prog)
{
	int	i;
	int	j;
	int	shamt;

	shamt = prog->resol.height / 10;
	i = 0;
	while (i < prog->resol.width)
	{
		j = prog->resol.height - 1;
		while (j >= shamt)
		{
			prog->itercount[j][i] = prog->itercount[j - shamt][i];
			prog->zs[j][i] = prog->zs[j - shamt][i];
			adjust_maxitercount(prog, j, i);
			prog->itercount[j - shamt][i] = 0;
			prog->zs[j - shamt][i].x = 0;
			prog->zs[j - shamt][i].y = 0;
			j--;
		}
		i++;
	}
	prog->coord.zero.y += shamt;
}

void	fractol_shift_up(t_program *prog)
{
	int	i;
	int	j;
	int	shamt;

	shamt = prog->resol.height / 10;
	i = 0;
	while (i < prog->resol.width)
	{
		j = 0;
		while (j < prog->resol.height - shamt)
		{
			prog->itercount[j][i] = prog->itercount[j + shamt][i];
			prog->zs[j][i] = prog->zs[j + shamt][i];
			adjust_maxitercount(prog, j, i);
			prog->itercount[j + shamt][i] = 0;
			prog->zs[j + shamt][i].x = 0;
			prog->zs[j + shamt][i].y = 0;
			j++;
		}
		i++;
	}
	prog->coord.zero.y -= shamt;
}
