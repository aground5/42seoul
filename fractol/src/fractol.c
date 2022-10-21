/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:06 by sgi               #+#    #+#             */
/*   Updated: 2022/10/21 09:38:58 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init_malloc(t_program *prog)
{
	int	i;
	
	prog->iterCount = (int **)ft_calloc(prog->resol.height, sizeof(int *));
	prog->iterCount[0] = (int *)ft_calloc(prog->resol.width * prog->resol.height, sizeof(int));
	i = 1;
	while (i < prog->resol.height)
	{
		prog->iterCount[i] = prog->iterCount[i - 1] + prog->resol.width;
		i++;
	}
	prog->zs = (t_ldpoint **)ft_calloc(prog->resol.height, sizeof(t_ldpoint *));
	prog->zs[0] = (t_ldpoint *)ft_calloc(prog->resol.width * prog->resol.height, sizeof(t_ldpoint));
	i = 1;
	while (i < prog->resol.height)
	{
		prog->zs[i] = prog->zs[i - 1] + prog->resol.width;
		i++;
	}
}

void	fractol_init(t_program *prog)
{
	prog->resol.width = 1200;
	prog->resol.height = 1200;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->resol.width, prog->resol.height, "fract-ol");
	prog->coord.zero.x = (prog->resol.width / 3) * 2;
	prog->coord.zero.y = prog->resol.height / 2;
	prog->coord.scale = prog->resol.height / 2;
	prog->canvas.image = mlx_new_image(prog->mlx, prog->resol.width, prog->resol.height);
	prog->canvas.buffer = mlx_get_data_addr(prog->canvas.image, \
	 &prog->canvas.pixel_bits, &prog->canvas.line_bytes, &prog->canvas.endian);
	prog->canvas.level = 1;
	fractol_init_malloc(prog);
}

void	fractol_draw(t_program *prog, int prev_iter, int max_iter)
{
	int	px;
	int py;
	int	**iterCount;
	int *numIterationsPerPixel;
	int i = 0;
	long double color;

	iterCount = prog->iterCount;
	printf("-----[render start: %d, %d]-----\n", prev_iter, max_iter);
	numIterationsPerPixel = (int *)ft_calloc(max_iter + 1, sizeof(int));
	py = 0;
	while (py < prog->resol.height)
	{
		px = 0;
		while (px < prog->resol.width)
		{
			if (iterCount[py][px] == prev_iter)
			{
				iterCount[py][px] = calc_mandelbrot(prog, px, py, prev_iter, max_iter);
			}
			px++;
		}
		py++;
	}
	printf("iter calc, px = %d, py = %d\n", px, py);
	for (int x = 0; x < prog->resol.width; x++)
	{
		for (int y = 0; y < prog->resol.height; y++)
        {
			i = iterCount[y][x];
        	numIterationsPerPixel[i]++;
		}	
	}
	printf("numIterationsPerPixel calc\n");
	int total = 0;
	for (i = 0; i <= max_iter; i++)
	{
		total += numIterationsPerPixel[i];
	}
	printf("total calc\n");
	long double *colorLUT;
	colorLUT = (long double *)ft_calloc(max_iter + 1, sizeof(long double));
	colorLUT[0] = (long double)numIterationsPerPixel[0] / (long double)total;
	i = 1;
	while (i <= max_iter)
	{
		colorLUT[i] = colorLUT[i - 1] + (long double)numIterationsPerPixel[i] / (long double)total;
		i++;
	}
	py = 0;
	printf("colorLUT calc\n");
	bool isAllBlack = true;
	while (py < prog->resol.height)
	{
		px = 0;
		while (px < prog->resol.width)
		{
			color = colorLUT[iterCount[py][px]];
			put_pixel(px, py, prog, color, &isAllBlack);
			px++;
		}
		py++;
	}
	free(colorLUT);
	printf("color calc\n");
	free(numIterationsPerPixel);
	// printf("numIterationsPerPixel\n");
	if (!isAllBlack)
	{
		mlx_put_image_to_window(prog->mlx, prog->win, prog->canvas.image, 0, 0);
	}
	else
	{
		mlx_string_put(prog->mlx, prog->win, prog->resol.height / 2, prog->resol.width / 2, 0xFFFFFF,
		"Calculating...");
	}
}

int	fractol_upscale_draw(t_program *prog)
{
	int	max_iter_arr[11] = {0, 5, 10, 30, 50, 100, 150, 200, 300, 400, 500};
	static int	tic;

	if (tic > 5)
	{
		if (prog->canvas.level < 11)
		{
			fractol_draw(prog, max_iter_arr[prog->canvas.level - 1], max_iter_arr[prog->canvas.level]);
			prog->canvas.level++;
		}
		else
		{
			fractol_draw(prog, (prog->canvas.level - 6) * 100, (prog->canvas.level - 5) * 100);
			prog->canvas.level++;
		}
		tic = 0;
	}
	else
		tic++;
	return (true);
}

// int	fractol_upscale_draw(t_program *prog)
// {
// 	static int	i = 10;
// 	if (i < 500)
// 	{
// 		fractol_draw(prog, i - 10, i);
// 		i += 10;
// 	}
// 	return (true);
// }

int main(void)
{
	t_program	prog;

	fractol_init(&prog);
	mlx_loop_hook(prog.mlx, fractol_upscale_draw, &prog);
	mlx_hook(prog.win, 17, 1L<<0, window_destroyed, &prog);
	mlx_key_hook(prog.win, key_hook, &prog);
	mlx_mouse_hook(prog.win, mouse_event, &prog);
    mlx_loop(prog.mlx);
	return (0);
}