#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;

	if (!(arr = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_bzero(arr, size + 1);
	return (arr);
}
