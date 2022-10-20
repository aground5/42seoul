/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 13:29:00 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int window_destroyed(t_program *prog)
{
	mlx_exit(prog);
}

int	key_hook(int keycode, t_program *prog)
{
	if (keycode == 53)
	{
		mlx_exit(prog);
	}
}

// int	mouse_event(int button, int x, int y, void *param)
// {
// 	t_program	*prog;
// 	static int color = 0xABCDEF;

// 	prog = param;
// 	// 4: scroll_down, 5: scroll_up
// 	if (button == 4)
// 	{
// 		color += 0x101010;
// 	}
// 	else if (button == 5)
// 		color -= 0x101010;
// 	if (prog->canvas->pixel_bits != 32)
//     	color = mlx_get_color_value(prog->mlx, color);
// 	for(int y = 0; y < 360; ++y) 
// 	{
// 		for(int x = 0; x < 1280; ++x)
// 		{
// 			int pixel = (y * prog->canvas->line_bytes) + (x * 4);
// 			if (prog->canvas->endian == 1)        // Most significant (Alpha) byte first
// 			{
// 				prog->canvas->buffer[pixel + 0] = (color >> 24);
// 				prog->canvas->buffer[pixel + 1] = (color >> 16) & 0xFF;
// 				prog->canvas->buffer[pixel + 2] = (color >> 8) & 0xFF;
// 				prog->canvas->buffer[pixel + 3] = (color) & 0xFF;
// 			}
// 			else if (prog->canvas->endian == 0)   // Least significant (Blue) byte first
// 			{
// 				prog->canvas->buffer[pixel + 0] = (color) & 0xFF;
// 				prog->canvas->buffer[pixel + 1] = (color >> 8) & 0xFF;
// 				prog->canvas->buffer[pixel + 2] = (color >> 16) & 0xFF;
// 				prog->canvas->buffer[pixel + 3] = (color >> 24);
// 			}
// 			// printf("buffer: %x\n", buffer[pixel]);
// 		}
// 	}
// 	mlx_put_image_to_window(prog->mlx, prog->win, prog->canvas->image, 0, 0);
// 	printf("%d %d %d\n", button, x, y);
// }