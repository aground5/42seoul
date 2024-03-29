/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:40:57 by sgi               #+#    #+#             */
/*   Updated: 2022/10/21 19:37:05 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_ldpoint	conv_pixel_coord(t_program *prog, int x, int y)
{
	t_ldpoint	coord;

	coord.x = (long double)(x - prog->coord.zero.x) \
	/ (long double)prog->coord.scale;
	coord.y = (long double)(y - prog->coord.zero.y) \
	/ (long double)prog->coord.scale;
	return (coord);
}
