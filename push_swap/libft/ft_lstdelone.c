#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;

	if (*alst == NULL)
		return ;
	else
	{
		temp = *alst;
		del(temp->content, temp->content_size);
		*alst = NULL;
	}
}
