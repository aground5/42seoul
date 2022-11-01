/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:34:36 by sgi               #+#    #+#             */
/*   Updated: 2022/11/01 09:59:30 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "julia.h"

extern inline void	julia(t_program *prog, t_point *p,
						int max_iter);

void	calc_julia(t_program *prog, int max_iter)
{
	t_point	p;

	p.y = 0;
	while (p.y < prog->resol.height)
	{
		p.x = 0;
		while (p.x < prog->resol.width)
		{
			julia(prog, &p, max_iter);
			p.x++;
		}
		p.y++;
	}
}

static void	display(void)
{
	printf("Julia fractal with parameter should be used like: \n");
	printf("./fractol 2 [0-1000] [0-1000]\n");
	exit(-1);
}

void	julia_init_with_parameter(t_program *prog, char **argv)
{
	int	x;
	int	y;

	x = ft_atoi(argv[2]);
	y = ft_atoi(argv[3]);
	if (x >= 0 && x <= 1000 && y >= 0 && y <= 1000)
	{
		prog->c.x = x / 1000.0L;
		prog->c.y = y / 1000.0L;
	}
	else
		display();
}

void	julia_init(t_program *prog, int argc, char **argv)
{
	if (argc == 4)
		julia_init_with_parameter(prog, argv);
	else if (argc == 2)
	{
		prog->c.x = 0.285;
		prog->c.y = 0.01;
	}
	else
		display();
}
