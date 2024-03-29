/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/31 22:29:52 by sgi              ###   ########.fr       */
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

void	log_mouse_event(t_program *prog)
{
	printf("------------------\n");
	printf("scale -> %lld\n", prog->coord.scale);
	printf("zero.x -> %lld\n", prog->coord.zero.x);
	printf("zero.y -> %lld\n", prog->coord.zero.y);
	printf("max_itercount -> %d\n", prog->max_itercount);
}

// 4: scroll_down, 5: scroll_up
int	mouse_event(int button, int x, int y, t_program	*prog)
{
	if (button == 5)
	{
		prog->max_itercount = 0;
		prog->terminate = false;
		prog->coord.scale = prog->coord.scale * 1.5;
		prog->coord.zero.x += (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y += (prog->coord.zero.y - y) * 0.5;
		fractol_zoom_in(prog, x, y);
		prog->canvas.level = 0;
	}
	else if (button == 4)
	{
		prog->max_itercount = 0;
		prog->terminate = false;
		prog->coord.scale = prog->coord.scale * 0.5;
		prog->coord.zero.x -= (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y -= (prog->coord.zero.y - y) * 0.5;
		fractol_zoom_out(prog, x, y);
		prog->canvas.level = 0;
	}
	log_mouse_event(prog);
	return (true);
}
