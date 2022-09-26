/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:51:08 by sgi               #+#    #+#             */
/*   Updated: 2022/09/26 21:14:05 by sgi              ###   ########.fr       */
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

typedef	struct	s_canvas
{
	void		*image;
	char		*buffer;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}				t_canvas;

typedef struct	s_program
{
	void		*mlx;
	void		*win;
	t_canvas	*canvas;
}				t_program;

int	mouse_event(int button, int x, int y, void *param);

#endif
