#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*np;
	int		i;

	i = 0;
	np = NULL;
	while (s[i] != '\0')
		i++;
	if (c != '\0')
		i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	return (np);
}
