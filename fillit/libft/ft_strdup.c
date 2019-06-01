#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = -1;
	while (s1[++i] != '\0')
		;
	while (!(arr = (char*)malloc(sizeof(const char) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		arr[i] = s1[i];
	arr[i] = '\0';
	return (arr);
}
