/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:52:19 by sgi               #+#    #+#             */
/*   Updated: 2022/01/16 21:53:32 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_DUPLICATE_H

# define CHECK_DUPLICATE_H
int		check_duplicate(int **board, int len, int row, int col);
int		check_duplicate_row(int **board, int len, int row);
int		check_duplicate_col(int **board, int len, int col);
void	init_check_duplicate_list(int *list);

#endif
