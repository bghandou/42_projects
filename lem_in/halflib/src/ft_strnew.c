#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*start;
	unsigned long	index;

	index = 0;
	if (!(start = (char *)malloc(size + 1)))
		return (NULL);
	while (index <= size / sizeof(char))
		start[index++] = '\0';
	return (start);
}
