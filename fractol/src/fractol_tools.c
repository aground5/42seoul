/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:28:32 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 22:57:56 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_prog_free(t_program *prog)
{
	free(prog->iterCount[0]);
    free(prog->iterCount);
	free(prog->zs[0]);
	free(prog->zs);
}

void	mlx_exit(t_program *prog)
{
    mlx_prog_free(prog);
	exit(0);
}

int get_color(long double t)
{
    int color;
	char *coChar;
	
	coChar = (char *)&color;
	coChar[0] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	coChar[1] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	coChar[2] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

void put_pixel(int px, int py, t_program *prog, long double normedOffset, bool *isAllBlack)
{
    int color;
	int	pixel;
	int	*buffer;

    // color ^= 0x00FFFFFF;
    color = get_color(normedOffset);
	pixel = py * prog->resol.width + px;
	buffer = (int *)prog->canvas.buffer;
	buffer[pixel] = color;
	if (color != 0)
		*isAllBlack = false;
}