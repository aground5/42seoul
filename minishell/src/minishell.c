/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:57:42 by sgi               #+#    #+#             */
/*   Updated: 2022/07/30 14:19:45 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	
	while (1)
	{
		input = readline("$ ");
		add_history(input);
		command(input);
		free(input);
	}
	return (0);
}

void	command(char *input)
{
	if (ft_strncmp("echo", input, ft_strlen("echo")) == 0)
		init_echo(input);
	// else if (ft_strncmp("cd", input, ft_strlen("cd")) == 0)
	// else if (ft_strncmp("pwd", input, ft_strlen("pwd")) == 0)
	// else if (ft_strncmp("export", input, ft_strlen("export")) == 0)
	// else if (ft_strncmp("unset", input, ft_strlen("unset")) == 0)
	// else if (ft_strncmp("env", input, ft_strlen("env")) == 0)
	else if (ft_strncmp("exit", input, ft_strlen("exit")) == 0)
		exit(0);
}
