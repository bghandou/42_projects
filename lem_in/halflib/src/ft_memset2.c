#include "libft.h"

void	*ft_memset2(void *s, int c, size_t n)
{
	char *s1;

	s1 = (char *)s;
	while (n--)
		*s1++ = c;
	return (s);
}
