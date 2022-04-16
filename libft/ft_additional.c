#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len_s1);
	ft_memcpy(ret + len_s1, s2, len_s2);
	return (ret);
}

int	ft_charinset(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		start_pos;

	i = 0;
	while (s1[i])
	{
		if (ft_charinset(s1[i], set) == 0)
			break ;
		i++;
	}
	start_pos = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_charinset(s1[i], set) == 0)
			break ;
		i--;
	}
	ret = (char *)malloc((i - start_pos + 2) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + start_pos, i - start_pos + 2);
	return (ret);
}
