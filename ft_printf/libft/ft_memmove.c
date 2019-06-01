#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_b;
	char	*src_b;

	dst_b = dst;
	src_b = (char*)src;
	if (dst > src)
	{
		len -= 1;
		while ((int)len >= 0)
		{
			dst_b[len] = src_b[len];
			len--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
