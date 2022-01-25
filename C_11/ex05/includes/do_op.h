/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:33:20 by sgi               #+#    #+#             */
/*   Updated: 2022/01/25 12:33:20 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define DIVERR 2
# define MODERR 3
# define OPINVLD 4

void	write_nbr(int nb, char *d);
void	ft_putnbr(int nb);

int		ft_atoi(char *str);

int		ft_strcmp(char *s1, char *s2);

#endif
