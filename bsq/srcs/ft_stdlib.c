int	ft_natoi_positive(char *str, int n)
{
	int				i;
	int				result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		else
			return (-1)
		i++;
	}
	return (result);
}

char	*ft_string_realloc(char *src, int size)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
	{
		free(src);
		return (NULL);
	}
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (NULL);
}