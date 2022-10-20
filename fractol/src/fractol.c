/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:06 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 18:03:22 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_program *prog)
{
	prog->resol.width = 1280;
	prog->resol.height = 1024;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->resol.width, prog->resol.height, "fract-ol");
	prog->coord.zero.x = (prog->resol.width / 3) * 2;
	prog->coord.zero.y = prog->resol.height / 2;
	prog->coord.scale = prog->resol.height / 2;
	prog->canvas.image = mlx_new_image(prog->mlx, prog->resol.width, prog->resol.height);
	prog->canvas.buffer = mlx_get_data_addr(prog->canvas.image, \
	 &prog->canvas.pixel_bits, &prog->canvas.line_bytes, &prog->canvas.endian);
}

void	fractol_draw(t_program *prog, int max_iter)
{
	int	px;
	int py;
	int	**iterCount;
	int *numIterationsPerPixel;
	int i = 0;
	long double color;

	iterCount = (int **)ft_calloc(prog->resol.height, sizeof(int *));
	iterCount[0] = (int *)ft_calloc(prog->resol.width * prog->resol.height, sizeof(int));
	i = 1;
	while (i < prog->resol.height)
	{
		iterCount[i] = iterCount[i - 1] + prog->resol.width;
		i++;
	}
	numIterationsPerPixel = (int *)ft_calloc(max_iter + 1, sizeof(int));
	py = 0;
	while (py < prog->resol.height)
	{
		px = 0;
		while (px < prog->resol.width)
		{
			iterCount[py][px] = calc_mandelbrot(prog, px, py, max_iter);
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
	printf("\n");
	printf("total calc\n");
	py = 0;
	while (py < prog->resol.height)
	{
		px = 0;
		while (px < prog->resol.width)
		{
			i = 0;
			color = 0;
			while (i <= iterCount[py][px])
			{
				color += ((long double)numIterationsPerPixel[i] / (long double)total) * 0xFFFFFF;
				i++;
			}
			put_pixel(px, py, prog, color);
			px++;
		}
		py++;
	}
	printf("color calc\n");
	free(numIterationsPerPixel);
	printf("numIterationsPerPixel\n");
	free(iterCount[0]);
	printf("iterCount[0]\n");
	free(iterCount);
	printf("iterCount\n");
	mlx_put_image_to_window(prog->mlx, prog->win, prog->canvas.image, 0, 0);
}

int	fractol_upscale_draw(t_program *prog)
{
	int	max_iter_arr[4] = {10, 100, 200, 500};
	static int	tic;
	static int	i;

	if (tic > 20)
	{
		if (i < 4)
		{
			fractol_draw(prog, max_iter_arr[i]);
			i++;
		}
		tic = 0;
	}
	else
		tic++;
	return (true);
}

int main(void)
{
	t_program	prog;

	fractol_init(&prog);
	mlx_loop_hook(prog.mlx, fractol_upscale_draw, &prog);
	mlx_hook(prog.win, 17, 1L<<0, window_destroyed, &prog);
	mlx_key_hook(prog.win, key_hook, &prog);
    mlx_loop(prog.mlx);
	return (0);
}