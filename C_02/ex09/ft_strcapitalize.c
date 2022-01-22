/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:48:02 by sgi               #+#    #+#             */
/*   Updated: 2022/01/13 21:26:16 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ret;

	ret = str;
	while (*str != '\x00')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str - 'A' + 'a';
		}
		str++;
	}
	return (ret);
}

int	is_char_lowercase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		return (1);
	return (0);
}

int	is_char_alphanumeric(char *c)
{
	if ((*c >= 'a' && *c <= 'z')
		|| (*c >= 'A' && *c <= 'Z')
		|| (*c >= '0' && *c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;

	ret = str;
	ft_strlowcase(str);
	if (is_char_lowercase(str) == 1)
	{
		*str = *str - 'a' + 'A';
	}
	str++;
	while (*str != '\x00')
	{
		if (is_char_alphanumeric(str - 1) == 0 && is_char_lowercase(str) == 1)
		{
			*str = *str - 'a' + 'A';
		}
		str++;
	}
	return (ret);
}
