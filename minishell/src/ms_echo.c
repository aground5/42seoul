/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:20:19 by sgi               #+#    #+#             */
/*   Updated: 2022/07/28 18:05:36 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_echo(char *input)
{
	int len_cmd;

	len_cmd = ft_strlen("echo");
	if (input[len_cmd + 1] == '-')
	{
		if (input[len_cmd + 2] == 'n')
		{
			if (input[len_cmd + 3] == ' ')
				process_echo_with_n(&input[ft_strlen("echo -n") + 1]);
			else if(input[len_cmd + 3] == '\x00')
				return (0);
			else
				process_echo(&input[len_cmd + 1]);
		}
		else if (input[len_cmd + 2] == ' ' || input[len_cmd + 2] == '\x00')
			printf("\n");
		else
			process_echo(&input[len_cmd + 1]);
	}
	else
		process_echo(&input[len_cmd + 1]);
	return (0);
}

void	process_echo(char *input)
{
	printf("%s\n", input);
}

void	process_echo_with_n(char *input)
{
	printf("%s", input);
}
