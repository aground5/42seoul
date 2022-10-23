/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/22 17:31:57 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_destroyed(t_program *prog)
{
	mlx_exit(prog);
	return (true);
}

int	key_hook(int keycode, t_program *prog)
{
	if (keycode == 53)
		mlx_exit(prog);
	else if (keycode >= 18 && keycode <= 19)
	{
		prog->fractal = keycode - 17;
		fractol_reboot(prog);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		prog->max_itercount = 0;
		prog->canvas.level = 0;
		prog->terminate = false;
		if (keycode == 123)
			fractol_shift_right(prog);
		else if (keycode == 124)
			fractol_shift_left(prog);
		else if (keycode == 125)
			fractol_shift_up(prog);
		else if (keycode == 126)
			fractol_shift_down(prog);
	}
	return (true);
}

// 4: scroll_down, 5: scroll_up
int	mouse_event(int button, int x, int y, t_program	*prog)
{
	if (button == 5)
	{
		printf("------------------\n");
		prog->coord.scale = prog->coord.scale * 1.5;
		prog->coord.zero.x += (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y += (prog->coord.zero.y - y) * 0.5;
		prog->max_itercount = 0;
		prog->terminate = false;
		prog->canvas.level = 0;
		fractol_zoom_in(prog, x, y);
		printf("scale -> %lld\n", prog->coord.scale);
		printf("zero.x -> %lld\n", prog->coord.zero.x);
		printf("zero.y -> %lld\n", prog->coord.zero.y);
	}
	if (button == 4)
	{
		printf("------------------\n");
		prog->coord.scale = prog->coord.scale * 0.5;
		prog->coord.zero.x -= (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y -= (prog->coord.zero.y - y) * 0.5;
		prog->max_itercount = 0;
		prog->terminate = false;
		prog->canvas.level = 0;
		fractol_zoom_out(prog, x, y);
		printf("scale -> %lld\n", prog->coord.scale);
		printf("zero.x -> %lld\n", prog->coord.zero.x);
		printf("zero.y -> %lld\n", prog->coord.zero.y);
	}
	printf("%d %d %d\n", button, x, y);
	return (true);
}
