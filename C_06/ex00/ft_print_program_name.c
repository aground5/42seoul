/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:05:24 by sgi               #+#    #+#             */
/*   Updated: 2022/01/20 10:54:21 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*name;

	if (argc < 1)
		return (0);
	name = argv[0];
	while (*name != '\x00')
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
	return (0);
}
