#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s);
	while (*s)
		s++;
	while (*s != c && size-- > 0)
		s--;
	return (*s == c ? (char *)s : NULL);
}
