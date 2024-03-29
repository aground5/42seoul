/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_array_zoom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:42:31 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 16:13:30 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

extern inline void	fz_fin(t_program *prog, int **itercount, t_ldpoint **zs);

static void	init_malloc(t_program *prog, int ***itercount, t_ldpoint ***zs)
{
	int	i;

	*itercount = \
	(int **)ft_calloc(prog->resol.height, sizeof(int *));
	(*itercount)[0] = \
	(int *)ft_calloc(prog->resol.width * prog->resol.height, sizeof(int));
	(*zs) = (t_ldpoint **)ft_calloc(prog->resol.height, \
	sizeof(t_ldpoint *));
	(*zs)[0] = (t_ldpoint *)ft_calloc(prog->resol.width \
	* prog->resol.height, sizeof(t_ldpoint));
	i = 1;
	while (i < prog->resol.height)
	{
		(*itercount)[i] = (*itercount)[i - 1] + prog->resol.width;
		(*zs)[i] = (*zs)[i - 1] + prog->resol.width;
		i++;
	}
}

void	fractol_zoom_in(t_program *prog, int x, int y)
{
	int			i;
	int			j;
	int			**itercount;
	t_ldpoint	**zs;

	init_malloc(prog, &itercount, &zs);
	i = 0;
	while (i < prog->resol.height)
	{
		j = 0;
		while (((y + 2 * i) % 3 == 0) && j < prog->resol.width)
		{
			if ((x + 2 * j) % 3 == 0)
			{
				itercount[i][j] = \
				prog->itercount[(y + 2 * i) / 3][(x + 2 * j) / 3];
				zs[i][j] = prog->zs[(y + 2 * i) / 3][(x + 2 * j) / 3];
				adjust_maxitercount(prog, (y + 2 * i) / 3, (x + 2 * j) / 3);
			}
			j++;
		}
		i++;
	}
	fz_fin(prog, itercount, zs);
}

void	fractol_zoom_out(t_program *prog, int x, int y)
{
	int			i;
	int			j;
	int			**itercount;
	t_ldpoint	**zs;

	init_malloc(prog, &itercount, &zs);
	i = 0;
	while (i < prog->resol.height)
	{
		j = 0;
		while (((y + i) % 2 == 0) && j < prog->resol.width)
		{
			if ((x + j) % 2 == 0)
			{
				itercount[(y + i) / 2][(x + j) / 2] = prog->itercount[i][j];
				zs[(y + i) / 2][(x + j) / 2] = prog->zs[i][j];
				adjust_maxitercount(prog, i, j);
			}
			j++;
		}
		i++;
	}
	fz_fin(prog, itercount, zs);
}
