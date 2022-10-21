/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:34:10 by sgi               #+#    #+#             */
/*   Updated: 2022/10/21 21:33:19 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline static void	mandelbrot(t_program *prog, t_point *p,
								int max_iter)
{
	t_ldpoint	c;
	t_ldpoint	z_square;

	c = conv_pixel_coord(prog, p->x, p->y);
	z_square.x = prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].x;
	z_square.y = prog->zs[p->y][p->x].y * prog->zs[p->y][p->x].y;
	while (z_square.x + z_square.y <= 4 \
	&& prog->itercount[p->y][p->x] < max_iter)
	{
		prog->zs[p->y][p->x].y \
		= 2 * prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].y + c.y;
		prog->zs[p->y][p->x].x = z_square.x - z_square.y + c.x;
		z_square.x = prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].x;
		z_square.y = prog->zs[p->y][p->x].y * prog->zs[p->y][p->x].y;
		prog->itercount[p->y][p->x]++;
	}
}

void	calc_mandelbrot(t_program *prog, int prev_iter, int max_iter)
{
	t_point	p;

	p.y = 0;
	while (p.y < prog->resol.height)
	{
		p.x = 0;
		while (p.x < prog->resol.width)
		{
			if (prog->itercount[p.y][p.x] == prev_iter || \
				prog->itercount[p.y][p.x] == 0)
				mandelbrot(prog, &p, max_iter);
			p.x++;
		}
		p.y++;
	}
}
