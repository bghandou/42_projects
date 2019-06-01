#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*end;

	if (!s)
		return (0);
	if (!(end = (char *)malloc(len + 1)))
		return (NULL);
	end = ft_strncpy(end, (s + start), len);
	end[len] = '\0';
	return (end);
}
