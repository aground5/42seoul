/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:37:04 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 15:38:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include "fractol.h"

inline void	julia(t_program *prog, t_point *p,
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

#endif