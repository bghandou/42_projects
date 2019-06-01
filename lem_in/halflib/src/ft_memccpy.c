#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst1;
	char	*src1;
	int		index;

	dst1 = (char *)dst;
	src1 = (char *)src;
	index = -1;
	while (++index < (int)n)
	{
		dst1[index] = src1[index];
		if (dst1[index] == (char)c)
			return (dst + index + 1);
	}
	return (NULL);
}
