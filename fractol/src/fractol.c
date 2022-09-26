/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:06 by sgi               #+#    #+#             */
/*   Updated: 2022/09/26 21:07:52 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}


int main(void)
{
	void		*mlx = mlx_init();
	void		*win = mlx_new_window(mlx, 1280, 360, "Tutorial Window");
	t_program	prog;
	t_canvas	canvas;

	canvas.image = mlx_new_image(mlx, 1280, 360);
	canvas.buffer = mlx_get_data_addr(canvas.image, \
	&canvas.pixel_bits, &canvas.line_bytes, &canvas.endian);
	prog.mlx = mlx;
	prog.win = win;
	prog.canvas = &canvas;
	// draw_line(mlx, win, 640, 360, 0, 0, rgb_to_int(200, 100, 200));
	mlx_mouse_hook(win, &mouse_event, &prog);
    mlx_loop(mlx);
	return (0);
}