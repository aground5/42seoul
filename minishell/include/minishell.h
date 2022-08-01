/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:58:41 by sgi               #+#    #+#             */
/*   Updated: 2022/07/28 18:04:25 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <readline/readline.h>
# include <stdio.h>
# include "libft.h"

void	command(char *input);

int	init_echo(char *input);
void	process_echo(char *input);
void	process_echo_with_n(char *input);

#endif