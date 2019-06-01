#include "libft.h"

void	ft_bzero2(char *s, size_t n)
{
	int i;

	i = 0;
	while (n--)
		s[i++] = '\0';
	return ;
}
