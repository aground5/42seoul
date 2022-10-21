/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:08 by sgi               #+#    #+#             */
/*   Updated: 2022/10/20 22:57:14 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_custom.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

typedef struct	s_resolution
{
	int			width;
	int			height;
}				t_resolution;

typedef struct	s_ldpoint
{
	long double	x;
	long double	y;
}				t_ldpoint;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct		s_llpoint
{
	long long int	x;
	long long int	y;
}					t_llpoint;

typedef struct	s_coord
{
	t_llpoint	zero;
	long long	scale;
}				t_coord;

typedef struct	s_canvas
{
	void		*image;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	char		*buffer;
	int			level;
}				t_canvas;

typedef struct		s_program
{
	void			*mlx;
	void			*win;
	t_resolution	resol;
	t_coord			coord;
	t_canvas		canvas;
	int				**iterCount;
	t_ldpoint		**zs;
}					t_program;

// hardware_hook.c
int			window_destroyed(t_program *prog);
int			key_hook(int keycode, t_program *prog);
int			mouse_event(int button, int x, int y, t_program	*prog);

//mandelbrot.c
t_ldpoint	mandelbrot(t_ldpoint *pnt, t_ldpoint *c);
int			calc_mandelbrot(t_program *prog, int px, int py, int prev_iter, int max_iter);

// fractol_math.c
bool		is_point_equal(t_point *p1, t_point *p2);
bool		is_ldpoint_equal(t_ldpoint *p1, t_ldpoint *p2);
bool		is_pixel_overflow(t_resolution *res, t_point *p);
t_point		conv_coord_pixel(t_program *prog, t_ldpoint *coord);
t_ldpoint	conv_pixel_coord(t_program *prog, int x, int y);

// fractol_tools.c
void		mlx_prog_free(t_program *prog);
void		mlx_exit(t_program *prog);
int			get_color(long double t);
void 		put_pixel(int px, int py, t_program *prog, long double normedOffset, bool *isAllBlack);

// fractol.c
void		fractol_init_malloc(t_program *prog);
void		fractol_draw(t_program *prog, int prev_iter, int max_iter);
int			fractol_upscale_draw(t_program *prog);

#endif
