#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
	c == '\r' ? 1 : 0);
}
