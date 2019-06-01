#include "libft.h"

char	*ft_strdup2(const char *s)
{
	int		index;
	char	*end;

	index = ft_strlen2(s) + 1;
	if (!(end = (char *)malloc(sizeof(char) * (index))))
		return (0);
	while (--index >= 0)
		end[index] = s[index];
	return (end);
}
