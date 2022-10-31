/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:28:32 by sgi               #+#    #+#             */
/*   Updated: 2022/10/23 17:34:24 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

extern const int	g_step;

void	mlx_prog_free(t_program *prog)
{
	free(prog->itercount[0]);
	free(prog->itercount);
	free(prog->zs[0]);
	free(prog->zs);
}

void	mlx_exit(t_program *prog)
{
	mlx_prog_free(prog);
	exit(0);
}

void	fractol_reboot(t_program *prog)
{
	mlx_prog_free(prog);
	fractol_init_malloc(prog);
	prog->canvas.level = 0;
	prog->max_itercount = 0;
	prog->terminate = false;
}

int	get_color(long double t)
{
	int		color;
	char	*color_char;

	color_char = (char *)&color;
	color_char[0] = (uint8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color_char[1] = (uint8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color_char[2] = (uint8_t)(8.5 * pow((1 - t), 3) * t * 255);
	color_char[3] = 0;
	return (color);
}

bool	draw_canvas(t_program *prog, long double *colorLUT)
{
	int			px;
	int			py;
	long double	normed_offset;
	int			pixel;
	bool		is_black;

	is_black = true;
	py = 0;
	while (py < prog->resol.height)
	{
		px = 0;
		while (px < prog->resol.width)
		{
			normed_offset = colorLUT[prog->itercount[py][px]];
			if (prog->itercount[py][px] == prog->max_itercount)
				normed_offset = colorLUT[(prog->canvas.level + 1) * g_step];
			pixel = py * prog->resol.width + px;
			((int *)prog->canvas.buffer)[pixel] = get_color(normed_offset);
			if (((int *)prog->canvas.buffer)[pixel] != 0)
				is_black = false;
			px++;
		}
		py++;
	}
	return (is_black);
}
