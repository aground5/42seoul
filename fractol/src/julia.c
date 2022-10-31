/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:34:36 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 17:01:10 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "julia.h"

extern inline void	julia(t_program *prog, t_point *p,
						int max_iter);

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
