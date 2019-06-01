#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*stock;

	if (!(stock = (void*)malloc(size)))
		return (NULL);
	ft_bzero(stock, size);
	return (stock);
}
