#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dsts;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dsts = i;
	while (src[i - dsts] && i < size - 1 && size != 0)
	{
		dst[i] = src[i - dsts];
		i++;
	}
	if (dsts < size)
		dst[i] = '\0';
	return (dsts + ft_strlen(src));
}
