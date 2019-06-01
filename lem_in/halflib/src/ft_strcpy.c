#include "libft.h"

char	*ft_strcpy(char *dest, const char *str)
{
	char *end;

	end = dest;
	while (*str)
		*dest++ = *str++;
	*dest = '\0';
	return (end);
}
