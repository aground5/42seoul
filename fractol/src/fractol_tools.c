/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:28:32 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 18:02:45 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mlx_exit(t_program *prog)
{
    (void)prog;
	exit(0);
}

int get_color(long double t)
{
    int color;
    
    color = 0;
    color |= (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color <<= 16;
    color |= (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color <<= 8;
    color |= (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

void put_pixel(int px, int py, t_program *prog, int color)
{
    //int color;
	int	pixel;

    color ^= 0x00FFFFFF;
    //color = get_color(normedOffset);
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