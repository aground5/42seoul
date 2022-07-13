/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:42:40 by sgi               #+#    #+#             */
/*   Updated: 2022/07/13 14:21:22 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_printf_judge(char *s, va_list vlst);

int		ft_strlen(char *s);
int		ft_putchar(int c);
int		ft_putstr(char *s);

void	ft_putnbr_base_u(char *base, uint32_t nb, int *count);
void	ft_putnbr(int32_t nb, int *count);
void	ft_putpnt(uint64_t nb, int *count);

#endif
