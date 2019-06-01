#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*prev;
	t_list	*nxt;

	prev = NULL;
	newlist = NULL;
	while (lst && f)
	{
		nxt = f(lst);
		nxt->next = NULL;
		if (newlist == NULL)
		{
			newlist = nxt;
			prev = nxt;
		}
		else
		{
			prev->next = nxt;
			prev = nxt;
		}
		lst = lst->next;
	}
	return (newlist);
}
