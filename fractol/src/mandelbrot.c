/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:34:10 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 21:05:25 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_ldpoint	mandelbrot(t_ldpoint *pnt, t_ldpoint *c)
{
	t_ldpoint	ret;

	ret.x = pnt->x * pnt->x - pnt->y * pnt->y + c->x;
	ret.y = 2 * pnt->x * pnt->y + c->y;
	return (ret);
}

int	calc_mandelbrot(t_program *prog, int px, int py, int prev_iter, int max_iter)
{
	t_ldpoint	c;
	t_ldpoint	z_square;
	int			iter;

	c = conv_pixel_coord(prog, px, py);
	z_square.x = prog->zs[py][px].x * prog->zs[py][px].x;
	z_square.y = prog->zs[py][px].y * prog->zs[py][px].y;

	iter = prev_iter;
	while (z_square.x + z_square.y <= 4 && iter < max_iter)
	{
		prog->zs[py][px].y = 2 * prog->zs[py][px].x * prog->zs[py][px].y + c.y;
		prog->zs[py][px].x = z_square.x - z_square.y + c.x;
		z_square.x = prog->zs[py][px].x * prog->zs[py][px].x;
		z_square.y = prog->zs[py][px].y * prog->zs[py][px].y;
		iter++;
	}
	return (iter);
}