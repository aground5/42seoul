/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:56:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/22 17:24:08 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const int	g_max_iter_arr[10] = \
	{5, 10, 30, 50, 100, 150, 200, 300, 400, 500};

void	fractol_calc(t_program *prog, int max_iter)
{
	prog->terminate = true;
	if (prog->fractal == 1)
		calc_mandelbrot(prog, max_iter);
	else if (prog->fractal == 2)
		calc_julia(prog, max_iter);
}

long double	*fractol_coloring(t_program *prog)
{
	int			i;
	int			total;
	int			*num_iter_pixel;
	long double	*color_lut;

	num_iter_pixel = (int *)ft_calloc(prog->max_itercount + 1, sizeof(int));
	color_lut = (long double *)ft_calloc(prog->max_itercount + 1,
			sizeof(long double));
	index_itercount(prog, num_iter_pixel);
	total = reduce_2d1d(num_iter_pixel, prog->max_itercount + 1);
	color_lut[0] = (long double)num_iter_pixel[0] / (long double)total;
	i = 1;
	while (i <= prog->max_itercount)
	{
		color_lut[i] = color_lut[i - 1] + \
		(long double)num_iter_pixel[i] / (long double)total;
		i++;
	}
	free(num_iter_pixel);
	return (color_lut);
}

void	fractol_draw(t_program *prog, int max_iter)
{
	long double	*color_lut;
	bool		is_black;

	printf("-----[render start: %d]-----\n", max_iter);
	fractol_calc(prog, max_iter);
	printf("fractol_calc\n");
	color_lut = fractol_coloring(prog);
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
	static int	tic;

	if (tic > 5)
	{
		if (prog->terminate)
			mlx_put_image_to_window(prog->mlx, prog->win, prog->canvas.image, 0, 0);
		else if (prog->canvas.level < 10)
		{
			if (prog->max_itercount < g_max_iter_arr[prog->canvas.level])
				prog->max_itercount = g_max_iter_arr[prog->canvas.level];
			fractol_draw(prog, g_max_iter_arr[prog->canvas.level]);
			prog->canvas.level++;
		}
		else
		{
			if (prog->max_itercount < (prog->canvas.level - 5) * 100)
				prog->max_itercount = (prog->canvas.level - 5) * 100;
			fractol_draw(prog, (prog->canvas.level - 5) * 100);
			prog->canvas.level++;
		}
		tic = 0;
	}
	else
		tic++;
	return (true);
}
