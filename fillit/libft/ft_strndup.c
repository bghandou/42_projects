#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	if (n < ft_strlen(s1))
	{
		if (!(cpy = (char *)malloc((n + 1) * sizeof(char))))
			return (NULL);
		cpy = ft_strncpy(cpy, s1, n);
		cpy[n] = '\0';
	}
	else
		cpy = ft_strdup(s1);
	return (cpy);
}
