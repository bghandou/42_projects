#include "libft.h"

void	ft_printlist(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		ft_putchar('\n');
		ft_putnbr(list->content_size);
		list = list->next;
	}
}
