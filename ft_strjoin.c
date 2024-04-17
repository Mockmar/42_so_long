
#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		str[i + len] = s2[i];
		i++;
	}
	free(s2);
	str[i + len] = 0;
	return (str);
}
