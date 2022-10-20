/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:34:10 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 16:01:57 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_ldpoint	mandelbrot(t_program *prog, t_ldpoint *pnt, t_ldpoint *c)
{
	t_ldpoint ret;

	ret.x = pnt->x * pnt->x - pnt->y * pnt->y + c->x;
	ret.y = 2 * pnt->x * pnt->y + c->y;
	return (ret);
}

int	calc_mandelbrot(t_program *prog, int px, int py, int max_iter)
{
	t_ldpoint c;
	t_ldpoint z;
	t_ldpoint z_square;
	int iter;

	c = conv_pixel_coord(prog, px, py);
	z.x = 0;
	z.y = 0;
	z_square = z;
	iter = 0;
	while (z_square.x + z_square.y <= 4 && iter < max_iter)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = z_square.x - z_square.y + c.x;
		z_square.x = z.x * z.x;
		z_square.y = z.y * z.y;
		iter++;
	}
	return (iter);
}