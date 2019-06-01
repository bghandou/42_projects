#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*conv;

	i = -1;
	conv = s;
	if (!n)
		return ;
	while (++i < n)
		conv[i] = '\0';
}
