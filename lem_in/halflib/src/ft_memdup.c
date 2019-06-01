#include "libft.h"
#include "garbage.h"

char	*ft_memdup(const char *s, size_t size)
{
	size_t	index;
	char	*end;

	index = 0;
	if (!(end = (char *)malloc(sizeof(char) * size)))
		return (0);
	end[size] = '\0';
	while (size-- > 0)
	{
		end[index] = s[index];
		index++;
	}
	return (end);
}
