#include "libft.h"

size_t	ft_strlen2(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
