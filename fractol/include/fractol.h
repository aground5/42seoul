/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:08 by sgi               #+#    #+#             */
/*   Updated: 2022/10/22 17:32:09 by sgi              ###   ########.fr       */
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

typedef struct s_resolution
{
	int	width;
	int	height;
}		t_resolution;

typedef struct s_ldpoint
{
	long double	x;
	long double	y;
}				t_ldpoint;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_llpoint
{
	long long int	x;
	long long int	y;
}					t_llpoint;

typedef struct s_coord
{
	t_llpoint	zero;
	long long	scale;
}				t_coord;

typedef struct s_canvas
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		level;
}			t_canvas;

typedef struct s_program
{
	void			*mlx;
	void			*win;
	t_resolution	resol;
	t_coord			coord;
	t_canvas		canvas;
	int				**itercount;
	bool			terminate;
	int				max_itercount;
	t_ldpoint		**zs;
	int				fractal;
}					t_program;

// hardware_hook.c
int			window_destroyed(t_program *prog);
int			key_hook(int keycode, t_program *prog);
int			mouse_event(int button, int x, int y, t_program	*prog);

// fractal_functions
void		calc_mandelbrot(t_program *prog, int max_iter);
void		calc_julia(t_program *prog, int max_iter);

// fractol_math.c
t_ldpoint	conv_pixel_coord(t_program *prog, int x, int y);

// fractol_tools.c
void		mlx_prog_free(t_program *prog);
void		mlx_exit(t_program *prog);
void		fractol_reboot(t_program *prog);
int			get_color(long double t);
bool		draw_canvas(t_program *prog, long double *colorLUT);

// fractol_draw.c
void		fractol_draw(t_program *prog, int max_iter);
long double	*fractol_coloring(t_program *prog);
void		fractol_calc(t_program *prog, int max_iter);

// fractol_draw_tools.c
int			reduce_2d1d(int *arr, int size);
void		index_itercount(t_program *prog, int *arr);

// fractol_array_shift.c
void		fractol_shift_left(t_program *prog);
void		fractol_shift_right(t_program *prog);
void		fractol_shift_up(t_program *prog);
void		fractol_shift_down(t_program *prog);

// fractol_array_zoom.c
void		fractol_zoom_in(t_program *prog, int x, int y);
void		fractol_zoom_out(t_program *prog, int x, int y);

// fractol.c
void		fractol_init_malloc(t_program *prog);
int			fractol_upscale_draw(t_program *prog);

#endif
