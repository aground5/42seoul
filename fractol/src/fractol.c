/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:06 by sgi               #+#    #+#             */
/*   Updated: 2022/10/21 21:41:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init_malloc(t_program *prog)
{
	int	i;

	prog->itercount = \
	(int **)ft_calloc(prog->resol.height, sizeof(int *));
	prog->itercount[0] = \
	(int *)ft_calloc(prog->resol.width * prog->resol.height, sizeof(int));
	i = 1;
	while (i < prog->resol.height)
	{
		prog->itercount[i] = prog->itercount[i - 1] + prog->resol.width;
		i++;
	}
	prog->zs = (t_ldpoint **)ft_calloc(prog->resol.height, \
	sizeof(t_ldpoint *));
	prog->zs[0] = (t_ldpoint *)ft_calloc(prog->resol.width \
	* prog->resol.height, sizeof(t_ldpoint));
	i = 1;
	while (i < prog->resol.height)
	{
		prog->zs[i] = prog->zs[i - 1] + prog->resol.width;
		i++;
	}
}

void	fractol_init(t_program *prog)
{
	prog->resol.width = 1280;
	prog->resol.height = 1000;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->resol.width, \
	prog->resol.height, "fract-ol");
	prog->coord.zero.x = (prog->resol.width / 3) * 2;
	prog->coord.zero.y = prog->resol.height / 2;
	prog->coord.scale = prog->resol.height / 2;
	prog->canvas.image = mlx_new_image(prog->mlx, prog->resol.width, \
	prog->resol.height);
	prog->canvas.buffer = mlx_get_data_addr(prog->canvas.image, \
	&prog->canvas.pixel_bits, &prog->canvas.line_bytes, &prog->canvas.endian);
	prog->canvas.level = 1;
	prog->fractal = 1;
	fractol_init_malloc(prog);
}

int	main(void)
{
	t_program	prog;

	fractol_init(&prog);
	mlx_loop_hook(prog.mlx, fractol_upscale_draw, &prog);
	mlx_hook(prog.win, 17, 1L << 0, window_destroyed, &prog);
	mlx_key_hook(prog.win, key_hook, &prog);
	mlx_mouse_hook(prog.win, mouse_event, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
