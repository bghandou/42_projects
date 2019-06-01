#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((int)*s != c && *s)
		s++;
	return (*s == c ? (char *)s : NULL);
}
