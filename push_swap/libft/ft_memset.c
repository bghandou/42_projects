#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*conv;
	unsigned char	val;
	size_t			i;

	conv = b;
	val = c;
	i = 0;
	while (i < len)
	{
		conv[i] = val;
		i++;
	}
	return (b);
}
