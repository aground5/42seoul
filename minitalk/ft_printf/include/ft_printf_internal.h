/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:29:24 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 17:58:23 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_ptf_judge(char *s, va_list *vlst);

int		ft_ptf_strlen(char *s);
int		ft_ptf_putchar(int c);
int		ft_ptf_putstr(char *s);

void	ft_ptf_putnbr_ub(char *base, uint32_t nb, int *count);
void	ft_ptf_putnbr(int32_t nb, int *count);
void	ft_ptf_putpnt(uint64_t nb, int *count);

#endif
