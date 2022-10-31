/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:02:48 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 19:29:37 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWTON_FRACTAL_H
# define NEWTON_FRACTAL_H

# include "fractol.h"

inline t_ldpoint	complex_mul(t_ldpoint x, t_ldpoint y)
{
	t_ldpoint	ret;

	ret.x = x.x * y.x - x.y * y.y;
	ret.y = x.y * y.x + x.x * y.y;
	return (ret);
}

inline t_ldpoint	complex_div(t_ldpoint x, t_ldpoint y)
{
	t_ldpoint	ret;

	ret.x = (x.x * y.x + x.y * y.y) / (y.x * y.x + y.y * y.y);
	ret.y = (x.y * y.x - x.x * y.y) / (y.x * y.x + y.y * y.y);
	return (ret);
}

inline t_ldpoint	complex_sub(t_ldpoint x, t_ldpoint y)
{
	t_ldpoint	ret;

	ret.x = x.x - y.x;
	ret.y = x.y - y.y;
	return (ret);
}

inline void	newton(t_program *prog, t_point *p,
						int max_iter)
{
	t_ldpoint	z;
	t_ldpoint	function;
	t_ldpoint	derivative;

	z = conv_pixel_coord(prog, p->x, p->y);
	while (prog->itercount[p->x][p->y] < max_iter)
	{
		function = complex_mul(complex_mul(z, z), z);
		function.x -= 1;
		derivative = complex_mul(z, z);
		derivative.x *= 3;
		derivative.y *= 3;
		z = complex_sub(z, complex_div(function, derivative));
		
		prog->itercount[p->x][p->y]++;
	}
}

#endif
