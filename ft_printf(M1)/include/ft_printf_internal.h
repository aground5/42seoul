/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:29:24 by sgi               #+#    #+#             */
/*   Updated: 2022/08/09 16:45:28 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf_judge(char *s, va_list *vlst);

int		ft_printf_strlen(char *s);
int		ft_printf_putchar(int c);
int		ft_printf_putstr(char *s);

void	ft_printf_putnbr_ub(char *base, uint32_t nb, int *count);
void	ft_printf_putnbr(int32_t nb, int *count);
void	ft_printf_putpnt(uint64_t nb, int *count);

#endif