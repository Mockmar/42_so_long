
#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == uc)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_b;
	unsigned char	*s2_b;

	s1_b = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_b[i] == s2_b[i] && s1_b[i] != 0 && s2_b[i] != 0 && i < n - 1)
		i++;
	return (s1_b[i] - s2_b[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_stradchar(char *s1, char c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
	return (str);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return ;
}
