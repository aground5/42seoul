/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:34:10 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 17:01:19 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandelbrot.h"

extern inline void	mandelbrot(t_program *prog, t_point *p,
						int max_iter);

void	calc_mandelbrot(t_program *prog, int max_iter)
{
	t_point	p;

	p.y = 0;
	while (p.y < prog->resol.height)
	{
		p.x = 0;
		while (p.x < prog->resol.width)
		{
			mandelbrot(prog, &p, max_iter);
			p.x++;
		}
		p.y++;
	}
}
