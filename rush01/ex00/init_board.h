/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:56:23 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 21:56:25 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BOARD_H

# define INIT_BOARD_H
int		**init_board(int len, char *raw_input);
void	process_input(int **board, int len, char *raw_input);
void	zero_fill(int **board, int len);
void	free_board(int **board);

#endif
