/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:56:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/21 21:14:47 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_calc(t_program *prog, int prev_iter, int max_iter)
{
	if (prog->fractal == 1)
		calc_mandelbrot(prog, prev_iter, max_iter);
	else if (prog->fractal == 2)
		calc_julia(prog, prev_iter, max_iter);
}

long double	*fractol_coloring(t_program *prog, int max_iter)
{
	int			i;
	int			total;
	int			*num_iter_pixel;
	long double	*color_lut;

	num_iter_pixel = (int *)ft_calloc(max_iter + 1, sizeof(int));
	color_lut = (long double *)ft_calloc(max_iter + 1, sizeof(long double));
	index_itercount(prog, num_iter_pixel);
	total = reduce_2d1d(num_iter_pixel, max_iter);
	color_lut[0] = (long double)num_iter_pixel[0] / (long double)total;
	i = 1;
	while (i <= max_iter)
	{
		color_lut[i] = color_lut[i - 1] + \
		(long double)num_iter_pixel[i] / (long double)total;
		i++;
	}
	free(num_iter_pixel);
	return (color_lut);
}

void	fractol_draw(t_program *prog, int prev_iter, int max_iter)
{
	long double	*color_lut;
	bool		is_black;

	printf("-----[render start: %d, %d]-----\n", prev_iter, max_iter);
	fractol_calc(prog, prev_iter, max_iter);
	printf("fractol_calc\n");
	color_lut = fractol_coloring(prog, max_iter);
	printf("fractol_coloring\n");
	is_black = draw_canvas(prog, color_lut);
	printf("draw_canvas\n");
	free(color_lut);
	if (!is_black)
		mlx_put_image_to_window(prog->mlx, prog->win, prog->canvas.image, 0, 0);
	else
		mlx_string_put(prog->mlx, prog->win, \
		prog->resol.height / 2, prog->resol.width / 2, 0xFFFFFF, \
		"Calculating...");
}

int	fractol_upscale_draw(t_program *prog)
{
	const int	max_iter_arr[11] = \
	{0, 5, 10, 30, 50, 100, 150, 200, 300, 400, 500};
	static int	tic;

	if (tic > 5)
	{
		if (prog->canvas.level < 11)
		{
			fractol_draw(prog, max_iter_arr[prog->canvas.level - 1], \
			max_iter_arr[prog->canvas.level]);
			prog->canvas.level++;
		}
		else
		{
			fractol_draw(prog, (prog->canvas.level - 6) * 100, \
			(prog->canvas.level - 5) * 100);
			prog->canvas.level++;
		}
		tic = 0;
	}
	else
		tic++;
	return (true);
}
