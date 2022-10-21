/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:00 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 22:14:23 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int window_destroyed(t_program *prog)
{
	mlx_exit(prog);
	return (true);
}

int	key_hook(int keycode, t_program *prog)
{
	if (keycode == 53)
	{
		mlx_exit(prog);
	}
	return (true);
}

int	mouse_event(int button, int x, int y, t_program	*prog)
{
	// 4: scroll_down, 5: scroll_up
	if (button == 5)
	{
		printf("------------------\n");
		mlx_prog_free(prog);
		fractol_init_malloc(prog);
		prog->coord.scale = prog->coord.scale * 1.5;
		prog->coord.zero.x += (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y += (prog->coord.zero.y - y) * 0.5;
		prog->canvas.level = 1;
		printf("scale -> %lld\n", prog->coord.scale);
		printf("zero.x -> %lld\n", prog->coord.zero.x);
		printf("zero.y -> %lld\n", prog->coord.zero.y);
	}
	if (button == 4)
	{
		printf("------------------\n");
		mlx_prog_free(prog);
		fractol_init_malloc(prog);
		prog->coord.scale = prog->coord.scale * 0.5;
		prog->coord.zero.x -= (prog->coord.zero.x - x) * 0.5;
		prog->coord.zero.y -= (prog->coord.zero.y - y) * 0.5;
		prog->canvas.level = 1;
		printf("scale -> %lld\n", prog->coord.scale);
		printf("zero.x -> %lld\n", prog->coord.zero.x);
		printf("zero.y -> %lld\n", prog->coord.zero.y);
	}
	printf("%d %d %d\n", button, x, y);
	return (true);
}