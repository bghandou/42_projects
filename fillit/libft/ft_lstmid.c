#include "libft.h"

void	ft_lstmid(t_list *alst, t_list *new, size_t index)
{
	size_t	i;

	i = 0;
	if (!alst || !new || !index)
		return ;
	while (++i < index)
		alst->next = alst->next->next;
	new->next = alst->next;
	alst->next = new;
}
