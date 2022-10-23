/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:34:36 by sgi               #+#    #+#             */
/*   Updated: 2022/10/22 16:28:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline static void	julia(t_program *prog, t_point *p,
							int max_iter)
{
	t_ldpoint	c;
	t_ldpoint	z_square;

	c.x = 0.285;
	c.y = 0.01;
	if (prog->zs[p->y][p->x].x == 0 && \
	prog->zs[p->y][p->x].y == 0)
		prog->zs[p->y][p->x] = conv_pixel_coord(prog, p->x, p->y);
	z_square.x = prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].x;
	z_square.y = prog->zs[p->y][p->x].y * prog->zs[p->y][p->x].y;
	while (z_square.x + z_square.y <= 4)
	{
		if (prog->itercount[p->y][p->x] >= max_iter)
		{
			prog->terminate = false;
			break ;
		}
		prog->zs[p->y][p->x].y \
		= 2 * prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].y + c.y;
		prog->zs[p->y][p->x].x = z_square.x - z_square.y + c.x;
		z_square.x = prog->zs[p->y][p->x].x * prog->zs[p->y][p->x].x;
		z_square.y = prog->zs[p->y][p->x].y * prog->zs[p->y][p->x].y;
		prog->itercount[p->y][p->x]++;
	}
}

void	calc_julia(t_program *prog, int max_iter)
{
	t_point	p;

	p.y = 0;
	while (p.y < prog->resol.height)
	{
		p.x = 0;
		while (p.x < prog->resol.width)
		{
			julia(prog, &p, max_iter);
			p.x++;
		}
		p.y++;
	}
}
