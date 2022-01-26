/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algorithm_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:57:59 by sgi               #+#    #+#             */
/*   Updated: 2022/01/26 00:58:00 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	save_max_collide(int row, int col, t_square *square)
{
	if (square->row_collide < row)
		square->row_collide = row;
	if (square->col_collide < col)
		square->col_collide = col;
}
