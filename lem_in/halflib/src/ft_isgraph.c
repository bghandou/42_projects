#include "libft.h"

int		ft_isgraph(int c)
{
	return (c >= 33 && c <= 126 ? 1 : 0);
}
