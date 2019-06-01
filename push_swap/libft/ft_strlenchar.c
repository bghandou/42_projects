#include "libft.h"

size_t		ft_strlenchar(const char *s, char trgt)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != trgt)
		i++;
	return (i);
}
