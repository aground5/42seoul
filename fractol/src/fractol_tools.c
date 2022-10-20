/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:28:32 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 16:20:11 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mlx_exit(t_program *prog)
{
	exit(0);
}

void put_pixel(int px, int py, t_program *prog, int color)
{
	int	pixel;
	pixel = py * prog->resol.width * 4 + px * 4;
	if (prog->canvas.endian == 1)
    {
        prog->canvas.buffer[pixel + 0] = (color >> 24);
        prog->canvas.buffer[pixel + 1] = (color >> 16) & 0xFF;
        prog->canvas.buffer[pixel + 2] = (color >> 8) & 0xFF;
        prog->canvas.buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (prog->canvas.endian == 0)
    {
        prog->canvas.buffer[pixel + 0] = (color) & 0xFF;
        prog->canvas.buffer[pixel + 1] = (color >> 8) & 0xFF;
        prog->canvas.buffer[pixel + 2] = (color >> 16) & 0xFF;
        prog->canvas.buffer[pixel + 3] = (color >> 24);
    }
}