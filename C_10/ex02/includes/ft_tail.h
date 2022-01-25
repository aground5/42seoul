/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:29:35 by sgi               #+#    #+#             */
/*   Updated: 2022/01/23 12:29:53 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define NORMEX 0
# define INVALIDOP 1
# define ILGALOFSET 2
# define REQARG 3

int	ft_strlen(char *s);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_atoi(char *str);

#endif
