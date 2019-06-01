#include "libft.h"

size_t	ft_lstsize(t_list *begin)
{
	size_t	size;

	size = 0;
	while (begin->next)
	{
		size++;
		begin->next = begin->next->next;
	}
	return (size);
}
