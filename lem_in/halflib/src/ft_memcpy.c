#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst1;
	char *src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	while (n-- > 0)
		dst1[n] = src1[n];
	return (dst1);
}
