#include "libft.h"
#include "garbage.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*end;

	index = ft_strlen(s) + 1;
	if (!(end = (char *)malloc(sizeof(char) * (index))))
		return (0);
	while (--index >= 0)
		end[index] = s[index];
	return (end);
}
