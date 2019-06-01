#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL)
		return ;
	else
	{
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
