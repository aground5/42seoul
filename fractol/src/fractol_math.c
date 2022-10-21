/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:40:57 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 22:16:04 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	is_point_equal(t_point *p1, t_point *p2)
{
	if (p1->x == p2->x && p1->y && p2->y)
		return (true);
	return (false);
}

bool	is_ldpoint_equal(t_ldpoint *p1, t_ldpoint *p2)
{
	if (p1->x == p2->x && p1->y && p2->y)
		return (true);
	return (false);
}

bool	is_pixel_overflow(t_resolution *res, t_point *p)
{
	if (p->x < 0 || p->y < 0 || res->width < p->x || res->height < p->y)
		return (true);
	return (false);
}

t_ldpoint	conv_pixel_coord(t_program *prog, int x, int y)
{
	t_ldpoint	coord;

	coord.x = (long double)(x - prog->coord.zero.x) / (long double)prog->coord.scale;
	coord.y = (long double)(y - prog->coord.zero.y) / (long double)prog->coord.scale;
	return (coord);
}