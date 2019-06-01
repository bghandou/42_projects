#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_b;
	unsigned char	*src_b;
	unsigned char	car;
	size_t			i;

	i = 0;
	dst_b = dst;
	src_b = (unsigned char*)src;
	car = c;
	while (i < n)
	{
		dst_b[i] = src_b[i];
		if (car == src_b[i])
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
