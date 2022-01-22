/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_fragment.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:56:10 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 21:56:11 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VIEW_FRAGMENT_H

# define CHECK_VIEW_FRAGMENT_H
int	check_views(int **board, int len, int row, int col);
int	check_row(int **board, int len, int row);
int	check_col(int **board, int len, int col);
int	check_left(int **board, int row, int now_col);
int	check_up(int **board, int now_row, int col);

#endif
